#include "targettreemodel.h"

TargetTreeModel::TargetTreeModel(QObject *parent) :
    QAbstractItemModel(parent),
    _root(new TreeItem(TreeItem::Root))
{

}

TargetTreeModel::~TargetTreeModel()
{
    delete _root;
}

QModelIndex TargetTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    TreeItem *parentItem = getItem(parent);

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex TargetTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = getItem(index);
    TreeItem *parentItem = childItem->parent();

    if (parentItem == _root)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}

int TargetTreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem = getItem(parent);
    return parentItem->rowCount();
}

int TargetTreeModel::columnCount(const QModelIndex &parent) const
{
    TreeItem *parentItem = getItem(parent);
    return parentItem->columnCount();
}

QVariant TargetTreeModel::data(const QModelIndex &index, int role) const
{
    return static_cast<TreeItem *>(index.internalPointer())->data(index.row(), index.column(), role);
}

TreeItem *TargetTreeModel::getRoot() const
{
    return _root;
}

TreeItem * TargetTreeModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return _root;
}
