#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customtableview.h"
#include "customtavlemodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ListViewModel *listViewModel = new ListViewModel(this);
    ui->listView->setModel(listViewModel);
    customTableModel *tableModel = new customTableModel();
    ui->tableView->setModel(tableModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setColumnWidth(0,150);
    ui->tableView->setColumnWidth(1,380);
    ui->tableView->setColumnWidth(2,190);
    ui->tableView->setColumnWidth(3,240);
    ui->tableView->setColumnWidth(4,250);
    ui->tableView->setColumnWidth(5,240);
    ui->tableView->setWindowTitle("custom tableCView sdfkdf");
    ui->tableView->setGeometry(0, 0, 1920, 1200);
    ui->tableView->setStyleSheet("QTableView{gridline-color : #424242}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

