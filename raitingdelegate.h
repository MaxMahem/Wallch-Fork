#ifndef RAITINGDELEGATE_H
#define RAITINGDELEGATE_H

#include <QStyledItemDelegate>

class RaitingDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    RaitingDelegate(QWidget *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
//    void setEditorData(QWidget *editor, const QModelIndex &index) const;
//    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    QImage starImage;

private Q_SLOTS:
//    void commitAndCloseEditor();
};

#endif // RAITINGDELEGATE_H
