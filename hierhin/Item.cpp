#include "Item.h"
#include "Essence.h"
#include "Node.h"
#include "ItemContextSetter.h"
#include "ex/UnregisteredClassException.h"
#include "nav/ItemRef.h"
#include "menu/SyncLauncher.h"

#include <util/SingletonRegistry.h>
#include <util/ObjectRegistry.h>

#include <hierhin/ex/UnsupportedCommand.h>
#include <hierhin/ex/IncompatibleEssenceExecution.h>

#include <hierhin/LinkEssence.h>
#include <hierhin/LinkOwnerEssence.h>
#include <hierhin/LinkableEssence.h>

#include <QJsonDocument>
#include <QJsonObject>

namespace hierhin {

const QString Item::DEFAULT_ID_GEN_CLASS_NAME("uniq::TimeQStringValue");
//const QString Item::DEFAULT_ESSENCE_CLASS_NAME("hierhin::SimpleEssence");
const QString Item::ID_KEY("id");
const QString Item::ESSENCE_CLASS_KEY("essenceClass");
const QString Item::PROPERTIES_KEY("prop");
const QString Item::BASE_TYPE_KEY("baseType");
const QString Item::ROLE_KEY("role");

potato_util::LazyPointer<uniq::Value<Id>> Item::_idGen(Item::DEFAULT_ID_GEN_CLASS_NAME);

Item::Item() : _launcherIndex(0)
{
    static bool yes = false;
    if (!yes) {

        //register system Essences
        REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, hierhin::LinkEssence);
        REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, hierhin::LinkOwnerEssence);
        REGISTER_CLASS_FOR_UTIL_FACTORY(hierhin::Essence, hierhin::LinkableEssence);

        yes = true;
    }
}

Id Item::id() const
{
    if (_id.isEmpty()) {
        _id = _idGen->value();
    }
    return _id;
}

void Item::setId(const Id &id)
{
    if (_id.isEmpty()) {
        _id = id; //set once
    }
}

void Item::setIdGenClassName(const QString &className)
{
    if (_idGen) {
        return;  //do not set if it already exists (ptr set)
    }

    _idGen.setClassName(className);
}

void Item::setEssenceClassName(const QString &className)
{
    if (_essenceClassName.isEmpty()) {
        _essenceClassName = className;
    }
}

EssencePtr Item::essencePtr() const
{
    if (_essenceClassName.isEmpty()) {
        return {};
    }

    try {
        return potato_util::SingletonRegistry<hierhin::Essence>::ptr(_essenceClassName);
    }  catch (potato_util::UnregisteredClassException &e) {
        throw ex::UnregisteredClassException(QString::fromStdString(e.className()));
    }
}

const Role &Item::role() const
{
    return _role;
}

void Item::setRole(const Role &newRole)
{
    auto weakParent = parentNode();
    if (weakParent) {
        auto prnt = weakParent.lock();

        if (prnt) {
            prnt->assignRole(newRole, id());
        }
    }

    _role = newRole;
}

QVariantMap Item::toMap() const
{
    QVariantMap mp;
    mp.insert(ID_KEY, id());

    if (!_essenceClassName.isEmpty()) {
        mp.insert(ESSENCE_CLASS_KEY, _essenceClassName);
    }

    if (!_properties.isEmpty()) {
        mp.insert(PROPERTIES_KEY, _properties);
    }

    mp.insert(BASE_TYPE_KEY, static_cast<int>(baseType()));

    //TODO: implement
    nodeToMap(mp);
    return mp;
}

void Item::fromMap(const QVariantMap &mp)
{
    _id = mp.value(ID_KEY).value<Id>();
    _essenceClassName = mp.value(ESSENCE_CLASS_KEY).value<QString>();
    _properties = mp.value(PROPERTIES_KEY).value<QVariantMap>();

    nodeFromMap(mp);
}

QByteArray Item::toJson() const
{
    QJsonObject jObj = QJsonObject::fromVariantMap(toMap());
    return QJsonDocument(jObj).toJson();
}

QVariant Item::property(const QString &name) const
{
    return _properties.value(name);
}

void Item::setProperty(const QString &name, const QVariant &value)
{
    auto def = definition();

    if (def) {
        def.validateProperty(name, value);
    }

    _properties.insert(name, value);
}

void Item::addValue(const QString &name, const QVariant &value)
{
    auto def = definition();


    if (def) {
        auto propDef = def.propertyDef(name);

        if (!propDef.isListType()) {
            throw "not a list type"; //TODO: exception class
        }
    }

    auto propValue = _properties.value(name);

    if (propValue.canConvert<QVariantList>()) {
        auto lst = propValue.toList(); //TODO: other list types?

        lst.append(value);

        setProperty(name, lst);
    } else {
        QVariantList lst;

        if (propValue.isValid()) {
            lst.append(propValue);
        }

        lst.append(value);
        setProperty(name, lst);
    }
}

menu::TaskId Item::execute(const QString &command, const QVariantList &args, menu::TaskId *taskIdOut)
{
    auto essence = essencePtr();
    auto lnch = launcher();
    auto def = definition();
    auto cmdNames = def.methodNames();

    if (!cmdNames.contains(command)) {
        throw ex::UnsupportedCommand(command);
    }

//    def::MethodDef cmdDef = cmdDefs.value(command);
//    auto validatedArgs = cmdDef.validate(args);

    if (essence->className() == essenceClassName()) {

        ItemContextSetter cntx;
        cntx.setItem(this);

        return lnch->launch(command, args, &cntx, taskIdOut);
    }

    throw ex::IncompatibleEssenceExecution(essence->className(), essenceClassName());

}

NodeDef Item::definition() const
{
    EssencePtr essPtr = essencePtr();

    if (essPtr) {
        return essPtr->nodeDef();
    }

    return {};
}

QString Item::essenceClassName() const
{
    return _essenceClassName;
}

QStringList Item::essenceClassNames() const
{
    EssencePtr essPtr = essencePtr();

    if (essPtr) {
        return essPtr->classNames();
    }

    return {};
}

bool Item::isKindOf(const QString &className) const
{
    EssencePtr essPtr = essencePtr();

    if (essPtr) {
        return essPtr->isKindOf(className);
    }

    return false;
}

BaseType Item::baseType() const
{
    if (dynamic_cast<const Node *>(this)) {
        return BaseType::NODE;
    }
    //TODO: <Link>
    return BaseType::ITEM;
}

ItemPtr Item::clone() const
{
    QScopedPointer<ItemCreator> cr(createCreator());
    auto mp = this->toMap();
    auto cloneItem = cr->createItem(mp);
    cloneItem->fromMap(mp);
    return cloneItem;
}

nav::Path Item::absPath() const
{
    ConstItemPtr item = sharedFromThis();
    QList<nav::Step> lst;

    while (!item->isRoot()) {
        nav::Step step;

        auto rl = item->role();

        if (rl.isEmpty()) {
            step.setAction(nav::Step::CHILD_ID);
            step.setArg(item->id());
        } else {
            step.setAction(nav::Step::CHILD_ROLE);
            step.setArg(item->role());
        }

        lst.prepend(step);

        item = item->parentNode().lock();
    }

    nav::Step rootStep;
    rootStep.setAction(nav::Step::ROOT);
    lst.prepend(rootStep);

    return nav::Path(lst);
}

bool Item::isRoot() const
{
    return !parentNode();
}

ItemPtr Item::itemByProperty(const QString &name)
{
    QVariant var = property(name);
    nav::ItemRef ref = var.value<nav::ItemRef>();
    return ref.ptr(sharedFromThis());
}

int Item::launcherIndex() const
{
    return _launcherIndex;
}

void Item::setLauncherIndex(int launcherIndex)
{
    _launcherIndex = launcherIndex;
}

QSharedPointer<menu::Launcher> Item::launcher() const
{
    //TODO: define a launcher class here (not LazyRegistry)
    return ObjectRegistry<int, menu::Launcher>::ptr(_launcherIndex);
}

ItemPtr Item::refPtr(const QString &refName)
{
    QVariant refVar = property(refName);

    if (refVar.canConvert<nav::ItemRef>()) {
        auto ref = refVar.value<nav::ItemRef>();
        return ref.ptr(sharedFromThis());
    }

    return {};
}

QStringList Item::essenceMethodNames() const
{
    return essencePtr()->methodNames();
}

ItemPtr Item::createImpl(const QString &essenceClassName) const
{
    auto essence = potato_util::SingletonRegistry<hierhin::Essence>::ptr(essenceClassName);
    auto bsType = essence->nodeDef().requiredBaseType();
    QScopedPointer<ItemCreator> cr(createCreator());
    auto itemPtrImpl = cr->createItem(bsType);
    itemPtrImpl->setEssenceClassName(essenceClassName);
    return itemPtrImpl;
}

} // namespace hierhin
