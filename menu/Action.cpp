#include "Action.h"

#include <util/Factory.h>

namespace menu {

const QString Action::DEFAULT_UNIQ_VALUE_CLASS_NAME("uniq::TimeQStringValue");

QString Action::_taskIdGenClassName(Action::DEFAULT_UNIQ_VALUE_CLASS_NAME);

uniq::Value<QString> *Action::_taskIdGen = nullptr;


Action::Action(QObject *parent) : QObject(parent)
{

}

uniq::Value<QString> *Action::taskIdGen()
{
    if (_taskIdGen == nullptr) {
        _taskIdGen = createTaskIdGen();
    }

    return _taskIdGen;
}

QString Action::taskIdGenClassName()
{
    return _taskIdGenClassName;
}

void Action::setTaskIdGenClassName(const QString &uniqValueClassName)
{
    _taskIdGenClassName = uniqValueClassName;
}

uniq::Value<QString> *Action::createTaskIdGen()
{
    return util::Factory<uniq::Value<QString>>::create(_taskIdGenClassName.toStdString());
}

} // namespace menu
