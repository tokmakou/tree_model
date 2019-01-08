#include "treeitem.h"
#include <QDebug>

TreeItem::TreeItem(TreeItem::TreeItemType type, TreeItem *parent):
    _item_type(type),
    _parent(parent),
    _target_data(nullptr)
{
    qDebug()<<"Создаем Item"<<_item_type;

    if (type == Target)
        _child_list.append(new TreeItem(AdditionalData, this));
}

TreeItem::~TreeItem()
{
    qDebug()<<"Удаляем Item"<<_item_type;

    if (_item_type == Root)
    while (_child_list.count()) {
        foreach (auto var, _child_list) {
            delete var;
            _child_list.removeAll(var);
        }
    }

    if (_item_type == Target)
    {
        auto parent = _parent;
        while (parent->_parent)
            parent = parent->_parent;

        foreach (auto var, _child_list)
            if (var->_item_type == Target)
                parent->addChild(var);
            else if (var->_item_type == AdditionalData)
            {
                qDeleteAll(var->_child_list);
                delete var;
            }
    }
}

void TreeItem::addChild(TreeItem *item)
{
    if (item->_parent) item->_parent->_child_list.removeAll(item);
    item->_parent = this;
    _child_list.append(item);
}

int TreeItem::rowCount()
{
    if (_item_type == AdditionalData) return _parent->_target_data->rowCount();
    return _child_list.count();
}

int TreeItem::columnCount()
{
    return 1;
}

TreeItem *TreeItem::child(int number)
{
    if (_item_type == AdditionalData)
    {
        if (_child_list.count() != _parent->_target_data->rowCount())
        {
            qDeleteAll(_child_list);
            _child_list.clear();
            for (auto i = 0; i < _parent->_target_data->rowCount(); ++i)
                _child_list.push_back(new TreeItem(Data, this));
        }
    }
    return _child_list.value(number);
}

int TreeItem::childNumber() const
{
    if (_parent)
        return _parent->_child_list.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

QVariant TreeItem::data(int row, int column, int role)
{
    if (role == Qt::DisplayRole && _item_type == AdditionalData)
        return _parent->_target_data->additionalHeaderData(role);
    if (role == Qt::DisplayRole && _item_type == Target)
        return _target_data->headerData(role);
    if (role == Qt::DisplayRole && _item_type == Data)
        return _parent->_parent->_target_data->additionalData(row, role);
    return QVariant();
}

TreeItem *TreeItem::parent() const
{
    return _parent;
}

void TreeItem::setTarget_data(TargetBase *target_data)
{
    _target_data = target_data;
}
