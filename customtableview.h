#ifndef CUSTOMTABLEVIEW_H
#define CUSTOMTABLEVIEW_H

#include <QWidget>
#include <QAbstractItemView>
#include <QTableView>
#include <QStandardItemModel>

class CustomTableView : public QTableView
{
public:
    CustomTableView(QWidget* parent = nullptr);
    void setColumnMargins(int column, int leftMargin, int rightMargin);
    void setModel(QAbstractItemModel* model) override;
};

#endif // CUSTOMTABLEVIEW_H
