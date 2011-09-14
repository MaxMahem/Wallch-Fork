#include "raitingdelegate.h"
#include <QPainter>
#include <QDebug>

RaitingDelegate::RaitingDelegate(QWidget *parent) : QStyledItemDelegate(parent) {
        starImage = QImage(":/icons/Pictures/star.png");
}

void RaitingDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();

    QImage scaledStarImage = starImage.scaledToHeight(option.rect.height());

    QRect originalRect   = QRect(option.rect.topLeft(), scaledStarImage.size());
    QRect translatedRect = originalRect;

    // we need to repeat this once for every rating point.
    for (int i = 0; i < index.data().toInt(); ++i) {
        // translate (shift) our image over the right distance, or iteration * width.
        translatedRect = originalRect.translated(i * scaledStarImage.width(), 0);

        // draw our image.
        painter->drawImage(translatedRect, scaledStarImage, scaledStarImage.rect());
    }

    painter->restore();
}

QWidget *RaitingDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
//    StarEditor *editor = new StarEditor(parent);
//    connect(editor, SIGNAL(editingFinished()), this, SLOT(commitAndCloseEditor()));
//    return editor;

    return QStyledItemDelegate::createEditor(parent, option, index);
}

QSize RaitingDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSize size(starImage.size());
    size.scale(option.rect.size(), Qt::KeepAspectRatio);
    size.setWidth(this->starImage.width() * 5);
    return size;
}
