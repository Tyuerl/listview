#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <QAbstractTableModel>

class MyTableModel : public QAbstractTableModel
{ 
    Q_OBJECT
public:
                MyTableModel(QObject* parent = 0);
    int         rowCount(const QModelIndex &parent) const;
    int         columnCount(const QModelIndex &parent) const;
    QVariant    data(const QModelIndex &index, int role) const;

    bool        canFetchMore(const QModelIndex &parent) const;
    void        fetchMore(const QModelIndex &parent);

private:
    QList<QString> mDataList;
    long int mCounter;

private slots:
    void        loadMoreData();
};


#endif // MYTABLEMODEL_H
