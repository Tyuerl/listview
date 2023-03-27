#include "listviewmodel.h"

#include <QTime>
#include <QTimer>
#include <QFont>

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
    if (role == Qt::FontRole)
    {
        return QFont("Roboto", 24, QFont::Bold);
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

QVariant ListViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return QVariant();
    switch (section) {
        case 0:
            return tr("ID Пациента");
        case 1:
            return tr("ФИО");
        case 2:
            return tr("Дата рождения");
        case 3:
            return tr("Дата обследования");
        case 4:
            return tr("Время обследования");
        case 5:
            return tr("ID обследования");
        default:
            return QVariant();
    }
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

