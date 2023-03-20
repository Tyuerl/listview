#include "listviewmodel.h"

#include <QTime>
#include <QTimer>

ListViewModel::ListViewModel(QObject * parent)
    : QAbstractListModel(parent)
{

    QTime time=QTime::currentTime();
    for(int i=0; i<10; i++)
    {
        mDataList.push_back(QString("%1 -- %2").arg(i).arg(time.toString("hh:mm:ss")));
    }

    return;
}


int ListViewModel::rowCount(const QModelIndex &parent) const
{
    return mDataList.size();
}

int ListViewModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}


QVariant ListViewModel::data(const QModelIndex &index, int role) const
{
    if(role==Qt::DisplayRole)
    {
        return mDataList.at(index.row());
    }
    return QVariant();
}

bool ListViewModel::canFetchMore(const QModelIndex &parent) const
{
    return true;
}



void ListViewModel::fetchMore(const QModelIndex &parent)
{
    QTimer::singleShot(1000, this, SLOT(loadMoreData()));
}


void ListViewModel::loadMoreData()
{
    int currentSize = mDataList.size();
    int insertLen=10;

    emit beginInsertRows(QModelIndex(), mDataList.size(), mDataList.size()+insertLen-1);

    QTime time=QTime::currentTime();
    for(int i=currentSize; i<currentSize+insertLen; i++)
    {
        mDataList.push_back(QString("%1 -- %2").arg(i).arg(time.toString("hh:mm:ss")));
    }

    emit endInsertRows();
}

