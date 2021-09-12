#ifndef VALUE_H
#define VALUE_H

namespace uniq {

template<typename T>
class Value
{
public:
    Value() = default;
    virtual ~Value() = default;

    virtual T value() const = 0;

    operator T() const {
        return value();
    }

    virtual bool isGlobal() const = 0;

};

} // namespace uniq

#endif // VALUE_H
