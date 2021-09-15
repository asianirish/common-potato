#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include <map>

using namespace std;

namespace util {

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
            return nullptr;
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

#define REGISTER_CLASS_FOR_UTIL_FACTORY(BaseClass, DevClass) Factory<BaseClass>::registerClass<DevClass>(#DevClass);

} // namespace util

#endif // FACTORY_H
