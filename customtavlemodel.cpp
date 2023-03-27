#include "customtavlemodel.h"
#include <QColor>

customTableModel::customTableModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    for(int i = 0; i < 50; i++)
    {
        mPersons.push_back(IPerson());
    }
}

int customTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mPersons.size();
}

int customTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 6;
}

QVariant customTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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

QVariant customTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::FontRole)
    {
        return QFont("Roboto", 14, 400);
    }
    if (role == Qt::BackgroundColorRole)
        return QColor("#424242");
    if (role == Qt::BackgroundRole)
        return QColor("#424242");
    if (role == Qt::TextColorRole)
        return QColor(Qt::white);
    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
        case 0:
            return mPersons[index.row()].id_p;
        case 1:
            return QString::fromStdString(mPersons[index.row()].fullName);
        case 2:
            return mPersons[index.row()].birthday.date().toString();
        case 3:
            return mPersons[index.row()].date.date().toString();
        case 4:
            return QString::number(mPersons[index.row()].time.hour())
                    + ":" +
                    QString::number(mPersons[index.row()].time.minute());
        case 5:
            return mPersons[index.row()].id_ob;
        default:
            return QVariant();
        }
    }
    return QVariant();
}

bool customTableModel::canFetchMore(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return true;
}

void customTableModel::fetchMore(const QModelIndex &parent)
{
    Q_UNUSED(parent);
    loadMoreData();
}

void customTableModel::loadMoreData()
{
    int currentSize = mPersons.size();
    int insertLen=100;

    emit beginInsertRows(QModelIndex(), mPersons.size(), mPersons.size()+insertLen-1);

    for(int i=currentSize; i<currentSize+insertLen; i++)
    {
        mPersons.append(IPerson());
    }

    emit endInsertRows();
}

void customTableModel::changeFocusedItem(const QModelIndex &index)
{

}
