#include "wbaseqssdialog.h"
#include <QMouseEvent>
#include <QPainter>
#include <qdrawutil.h>

WBaseQssDialog::WBaseQssDialog(QWidget *parent, Qt::WindowFlags flags) :
    QDialog(parent, flags), memNum(0)
{
}

void WBaseQssDialog::setBorderImage(const QString &fileName, int flag)
{
    memNum = flag;
    borderImage.load(fileName);
    if (borderImage.isNull())
        setAttribute(Qt::WA_TranslucentBackground, false);
    else
        setAttribute(Qt::WA_TranslucentBackground);
}

void WBaseQssDialog::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        pressedPoint = e->globalPos() - frameGeometry().topLeft();
        e->accept();
    }
}

void WBaseQssDialog::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        move(e->globalPos() - pressedPoint);
        e->accept();
    }
}

void WBaseQssDialog::paintEvent(QPaintEvent *e)
{
    if (borderImage.isNull())
    {
        return QDialog::paintEvent(e);
    }
    else
    {
        QPainter painter(this);
        if (memNum == 0)
            qDrawBorderPixmap(&painter, rect(), QMargins(8,8,8,8), borderImage);
        else
            qDrawBorderPixmap(&painter, rect(), QMargins(12,12,12,12), borderImage);
    }
}

WIDGET_EXTENT_FUN_IMPLEMENT(WBaseQssDialog)
