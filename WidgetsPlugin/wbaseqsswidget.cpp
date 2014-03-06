#include "wbaseqsswidget.h"
#include <QStyleOption>
#include <QPainter>

WBaseQssWidget::WBaseQssWidget(QWidget *parent) :
    QWidget(parent)
{

}

void WBaseQssWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

WIDGET_EXTENT_FUN_IMPLEMENT(WBaseQssWidget)
