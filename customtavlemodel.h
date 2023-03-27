#ifndef CUSTOMTAVLEMODEL_H
#define CUSTOMTAVLEMODEL_H

#include <QAbstractTableModel>
#include <vector>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include <QSize>
#include <QFont>

class customTableModel : public QAbstractTableModel
{
    struct IPerson
    {
        QString id_p;
        QString id_ob;
        QDateTime date;
        QDateTime birthday;
        std::string fullName;
        QTime time;
        IPerson ()
            : id_p("MG110312"),
              id_ob("255.255.2.255"),
              date(QDateTime(QDate(2023, 4, 22))),
              birthday(QDateTime(QDate(2002, 4, 9))),
              fullName("Иванова Дарья Иванова"),
              time (QTime(14, 10 , 0))
        {}
    };
public:
    customTableModel(QObject *parent = 0);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    bool        canFetchMore(const QModelIndex &parent) const override;
    void        fetchMore(const QModelIndex &parent) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;


private slots:
    void        loadMoreData();
    void        changeFocusedItem(const QModelIndex &index);
protected:
    QVector<IPerson> mPersons;
};

#endif // CUSTOMTAVLEMODEL_H
