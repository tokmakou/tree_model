#ifndef TREEITEM_H
#define TREEITEM_H

#include <QVariant>
#include <QList>
#include <targetbase.h>

class TreeItem
{
public:
    enum TreeItemType { AdditionalData, Target, Root, Data };

    TreeItem(TreeItemType type = Target, TreeItem * parent = nullptr);
    ~TreeItem();

    void addChild(TreeItem * item);
    int rowCount();
    int columnCount();
    TreeItem *child(int number);
    int childNumber() const;

    QVariant data(int row, int column, int role = Qt::DisplayRole);

    TreeItem *parent() const;
    void setTarget_data(TargetBase *target_data);

private:
    TreeItemType _item_type;
    TargetBase *_target_data;

    TreeItem * _parent;
    QList <TreeItem *> _child_list;
};

#endif // TREEITEM_H
