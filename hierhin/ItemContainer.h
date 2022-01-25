#ifndef HIERHIN_ITEMCONTAINER_H
#define HIERHIN_ITEMCONTAINER_H

#include <util/CuteContainer.h>
#include <Item.h>
#include <type.h>

namespace hierhin {

class ItemWrapper : public BaseWrapper
{
public:

    ItemWrapper() = default;// : _object(nullptr) {}

//    virtual ~ItemPtrWrapper();

    ItemPtr value() {
        return _item;
    }

    void setValue(const ItemPtr &item) {
        _item = item;
    }

    QString key() const {
        return _item->id();
    }

    void setKey(const QString &key) {
        _item->setId(key);
    }

    QString name() const {
        return _item->role();
    }

    void setName(const QString &name) {
        _item->setRole(name);
    }

private:
    ItemPtr _item;
};

class ItemContainer : public potato_util::CuteContainer<Id, ItemPtr, ItemWrapper>
{
public:
    ItemContainer();

protected:
    Id indexToKeyType(int index) override;

};

} // namespace hierhin

#endif // HIERHIN_ITEMCONTAINER_H
