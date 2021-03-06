#ifndef POTATO_UTIL_FACTORY_H
#define POTATO_UTIL_FACTORY_H

#include <string>
#include <map>

using namespace std;

namespace potato_util {

class UnregisteredClassException
{
public:
    UnregisteredClassException(const std::string &className) : _className(className) {

    }

    std::string className() const {
        return _className;
    }

private:
    std::string _className;
};

template <typename BaseClass>
class AbstractCreator
{
public:
    virtual ~AbstractCreator() = default;

    virtual BaseClass *create() const = 0;
};

template <typename BaseClass, typename DerClass>
class Creator : public AbstractCreator<BaseClass>
{
public:

    BaseClass *create() const override {
        return new DerClass();
    }
};

template <typename BaseClass>
class Factory
{
public:

    static void clear() {
        for (auto pr : _creators) {
            delete pr.second;
        }

        _creators.clear();
    }

    template<typename T>
    static void registerClass(const string &className) {
        if (_creators.count(className)) {
            return;
        }

        AbstractCreator<BaseClass> *creator = new Creator<BaseClass,T>();

        _creators.insert({className, creator});
    }

    static BaseClass *create(const string &className) {
        if (_creators.count(className) == 0) {
            throw UnregisteredClassException(className);
        }

        AbstractCreator<BaseClass>* creator = _creators.at(className);

        if (creator) {
            return creator->create();
        }

        return nullptr;

    }

private:
    static map<string, AbstractCreator<BaseClass>*> _creators;
};

template <typename BaseClass>
map<string, AbstractCreator<BaseClass>*> Factory<BaseClass>::_creators;

} // namespace potato_util

#define REGISTER_CLASS_FOR_UTIL_FACTORY(BaseClass, DevClass) potato_util::Factory<BaseClass>::registerClass<DevClass>(#DevClass);

#endif // POTATO_UTIL_FACTORY_H
