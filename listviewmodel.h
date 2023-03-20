#ifndef LISTVIEWMODEL_H
#define LISTVIEWMODEL_H

#include <QObject>
#include <QAbstractListModel>

class ListViewModel : public  QAbstractListModel
{
    Q_OBJECT
public:
                ListViewModel(QObject* parent = 0);
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

#endif // LISTVIEWMODEL_H
