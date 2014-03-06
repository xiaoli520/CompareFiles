#ifndef ITEMDELEGATENOFOCUS_H
#define ITEMDELEGATENOFOCUS_H

#include <QStyledItemDelegate>
#include "WidgetsPlugin_global.h"

class WIDGETSPLUGINSHARED_EXPORT ItemDelegateNoFocus : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ItemDelegateNoFocus(QObject *parent = 0);
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // ITEMDELEGATENOFOCUS_H
