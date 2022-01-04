#ifndef CUTEFACTORY_H
#define CUTEFACTORY_H

#include <QString>
#include <QMap>

namespace potato_util {


template <typename BaseClass>
class AbstractCuteCreator
{
public:
    virtual BaseClass *create() const = 0;
};

template <typename BaseClass, typename DerClass>
class CuteCreator : public AbstractCuteCreator<BaseClass>
{
public:
    CuteCreator();

    BaseClass *create() const override {
        return new DerClass();
    }
};

template <typename BaseClass>
class CuteFactory
{
public:

    template<typename T>
    static void registerClass(const QString &className, AbstractCuteCreator<BaseClass> *creator) {
        if (_creators.contains(className)) {
            return;
        }

        _creators.insert(className, creator);
    }

    static BaseClass *create(const QString &className) {
        if (!_creators.contains(className)) {
            return nullptr;
        }
        AbstractCuteCreator<BaseClass>* creator = _creators.value(className, nullptr);

        if (creator) {
            return creator->create();
        }

        return nullptr;

    }

private:
    static QMap<QString, AbstractCuteCreator<BaseClass>*> _creators;
};

template <typename BaseClass>
QMap<QString, AbstractCuteCreator<BaseClass>* > CuteFactory<BaseClass>::_creators;

template <typename BaseClass, typename DerClass>
CuteCreator<BaseClass, DerClass>::CuteCreator()
{
    auto className = DerClass::staticMetaObject.className();
    CuteFactory<BaseClass>::template registerClass<DerClass>(className, this);
}

/*
 * using:
 * //register:
    util::CuteCreator<QObject, Hi::TestA> cra;
    util::CuteCreator<QObject, Hi::TestB> crb;
    util::CuteCreator<QObject, Hi::TestC> crc;

    //create:
    auto obj = util::CuteFactory<QObject>::create("Hi::TestA");
 * */

} // namespace util

#endif // CUTEFACTORY_H
