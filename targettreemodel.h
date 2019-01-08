#ifndef TARGETTREEMODEL_H
#define TARGETTREEMODEL_H

#include <QAbstractItemModel>
#include <treeitem.h>

class TargetTreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit TargetTreeModel(QObject *parent = nullptr);
    virtual ~TargetTreeModel();

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    TreeItem *getRoot() const;

signals:

public slots:

private:
    TreeItem *_root;
    TreeItem * getItem(const QModelIndex &index) const;
};

#endif // TARGETTREEMODEL_H
