#include <QTime>
#include <QTimer>
#include <QFont>


#include "MyTableModel.h"

MyTableModel::MyTableModel(QObject * parent)
    : QAbstractTableModel(parent)
{

    QTime time=QTime::currentTime();
    for(int i=0; i<10; i++)
    {
        mDataList.push_back(QString("%1 -- %2").arg(i).arg(time.toString("hh:mm:ss")));
    }

    return;
}


int MyTableModel::rowCount(const QModelIndex &parent) const
{
    return mDataList.size();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}


QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if(role==Qt::DisplayRole)
    {
        return mDataList.at(index.row());
    }
    if (role == Qt::FontRole)
    {
        return QFont("Roboto", 24, QFont::Bold);
    }
    return QVariant();
}

bool MyTableModel::canFetchMore(const QModelIndex &parent) const
{
    return true;
}



void MyTableModel::fetchMore(const QModelIndex &parent)
{
    QTimer::singleShot(1000, this, SLOT(loadMoreData()));
}


void MyTableModel::loadMoreData()
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

