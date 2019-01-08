#include <QApplication>
#include <qtreeview.h>
#include <targettreemodel.h>

#include <targetdata.h>
#include <object1.h>
#include <object2.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto treeView = new QTreeView;
    auto model = new TargetTreeModel;

    auto treeItem1 = new TreeItem;
    auto treeItem2 = new TreeItem;
    auto treeItem3 = new TreeItem;
    auto treeItem4 = new TreeItem;


    treeItem1->setTarget_data(new TargetData<Object1>(new Object1));
    treeItem2->setTarget_data(new TargetData<Object2>(new Object2));
    treeItem3->setTarget_data(new TargetData<Object1>(new Object1));
    treeItem4->setTarget_data(new TargetData<Object2>(new Object2));

    treeItem1->addChild(treeItem3);
    treeItem1->addChild(treeItem4);

    model->getRoot()->addChild(treeItem1);
    model->getRoot()->addChild(treeItem2);
//    model->getRoot()->addChild(treeItem3);
    treeItem1->addChild(treeItem2);
    treeView->setModel(model);
    treeView->show();


//    treeView->setModel(nullptr);
//    model->getRoot()->~TreeItem();

    return a.exec();
}
