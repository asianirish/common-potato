#ifndef POTATO_UTIL_BIMAP_H
#define POTATO_UTIL_BIMAP_H

#include <QMap>
#include <QDebug>

namespace potato_util {

template <class LeftType, class RightType>
class BiMap
{
public:
    BiMap(){}

    BiMap(std::initializer_list<std::pair<LeftType, RightType> > list) : _leftMap(list)
    {
        reverseCopy();
    }

    const QMap<LeftType, RightType> &leftMap() const {
        return _leftMap;
    }

    const QMap<RightType, LeftType> &rightMap() const {
        return _rightMap;
    }

    RightType value(const LeftType &key, const RightType &defaultValue = RightType()) const {
        return _leftMap.value(key, defaultValue);
    }

    LeftType reverseValue(const RightType &key, const LeftType &defaultValue = LeftType()) const {
        return _rightMap.value(key, defaultValue);
    }

    QList<RightType> leftValues(const LeftType &key) const {
        return _leftMap.values(key);
    }

    QList<LeftType> rightValues(const RightType &key) const {
        return _rightMap.values(key);
    }

    void insert(const LeftType &key, const RightType &value) {
        _leftMap.insert(key, value);
        _rightMap.insert(value, key);
    }

    bool leftContains(const LeftType &key) const {
        return _leftMap.contains(key);
    }

    bool rightContains(const RightType &key) const {
        return _rightMap.contains(key);
    }

private:
    QMap<LeftType, RightType> _leftMap;
    QMap<RightType, LeftType> _rightMap;

    void reverseCopy() {
        for (auto key : _leftMap.uniqueKeys()) {
//            qDebug() << "key:" << key;
            for (auto value : _leftMap.values(key)) {
//                qDebug() << "reverseCopy:" << key << value;
                _rightMap.insert(value, key);
            }
        }

//        qDebug() << "_rightMap: " << _rightMap;
    }

};

} // namespace potato_util

#endif // POTATO_UTIL_BIMAP_H
