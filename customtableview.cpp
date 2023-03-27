#include "customtableview.h"

CustomTableView::CustomTableView(QWidget* parent)
    : QTableView(parent)
{

}


void CustomTableView::setColumnMargins(int column, int leftMargin, int rightMargin)
{
    if (column >= 0 && column < model()->columnCount()) {
        QAbstractItemDelegate *delegate = itemDelegateForColumn(column);
        if (delegate) {
            delegate->setProperty("leftMargin", leftMargin);
            delegate->setProperty("rightMargin", rightMargin);
        }
    }
}


void CustomTableView::setModel(QAbstractItemModel* model)
{
    QTableView::setModel(model);
    // Set the custom margins for each column
    for (int i = 0; i < model->columnCount(); ++i) {
       // setColumnMargins(i, 1000, 1000);
    }
}
