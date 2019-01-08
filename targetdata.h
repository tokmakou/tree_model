#ifndef TARGETDATA_H
#define TARGETDATA_H

#include <targetbase.h>
#include <object1.h>
#include <object2.h>

#include <QDebug>

template <class T>
class TargetData: public TargetBase
{
public:
    TargetData(T * internal_pointer):
        TargetBase(internal_pointer){}

    QVariant headerData(int role = Qt::DisplayRole) const override
    {
        if (typeid(TargetData<T>) == typeid(TargetData<Object1>))
            return QString("this is Object 1");

        if (typeid(TargetData<T>) == typeid(TargetData<Object2>))
            return QString("this is Object 2");
    }

    QVariant additionalData(int row, int role = Qt::DisplayRole) const override
    {
        if (typeid(TargetData<T>) == typeid(TargetData<Object1>))
            switch (row) {
            case 0:
                return static_cast<const Object1 *>(_internal_pointer)->data1;
                break;
            case 1:
                return static_cast<const Object1 *>(_internal_pointer)->data2;
                break;
            case 2:
                return static_cast<const Object1 *>(_internal_pointer)->data3;
                break;
            default:
                return QVariant();
            }

        if (typeid(TargetData<T *>) == typeid(TargetData<Object2 *>))
            switch (row) {
            case 0:
                return static_cast<const Object2 *>(_internal_pointer)->data1;
                break;
            case 1:
                return static_cast<const Object2 *>(_internal_pointer)->data2;
                break;
            default:
                return QVariant();
            }
    }

    QVariant additionalHeaderData(int role = Qt::DisplayRole) const override
    {
        if (typeid(TargetData<T>) == typeid(TargetData<Object1>))
            return QString("Подробнее об объекте 1");

        if (typeid(TargetData<T>) == typeid(TargetData<Object2>))
            return QString("Подробнее об объекте 2");
    }

    int rowCount() const override
    {
        if (typeid(TargetData<T>) == typeid(TargetData<Object1>))
            return 3;

        if (typeid(TargetData<T>) == typeid(TargetData<Object2>))
            return 2;
    }
};

#endif // TARGETDATA_H
