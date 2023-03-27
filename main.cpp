#include "mainwindow.h"
#include "customtableview.h"
#include "customtavlemodel.h"
#include "listviewmodel.h"
#include <QHeaderView>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*customTableModel *tableModel = new customTableModel();
    CustomTableView tableView;
    tableView.setModel(tableModel);
    tableView.resizeColumnsToContents();
    tableView.setColumnWidth(0,150);
    tableView.setColumnWidth(1,380);
    tableView.setColumnWidth(2,190);
    tableView.setColumnWidth(3,240);
    tableView.setColumnWidth(4,250);
    tableView.setColumnWidth(5,240);
    tableView.setWindowTitle("custom tableCView sdfkdf");
    tableView.setGeometry(0, 0, 1920, 1200);
    tableView.show();*/
    MainWindow w;
    w.show();
    return a.exec();
}
