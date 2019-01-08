#ifndef TARGETBASE_H
#define TARGETBASE_H

#include <QVariant>

class TargetBase
{
public:
    TargetBase(void * internal_pointer);
    virtual ~TargetBase();
    virtual QVariant headerData(int role = Qt::DisplayRole) const = 0;
    virtual QVariant additionalData(int row, int role = Qt::DisplayRole) const = 0;
    virtual QVariant additionalHeaderData(int role = Qt::DisplayRole) const = 0;
    virtual int rowCount() const = 0;
    const void * _internal_pointer;
};

#endif // TARGETBASE_H
