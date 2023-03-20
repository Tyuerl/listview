#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ListViewModel *listViewModel = new ListViewModel(this);
    ui->listView->setModel(listViewModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

