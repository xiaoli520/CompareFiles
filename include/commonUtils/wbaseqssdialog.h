#ifndef WBASEQSSDIALOG_H
#define WBASEQSSDIALOG_H

#include <QDialog>
#include <QPixmap>
#include "WidgetsPlugin_global.h"

/**
 * @brief The WBaseQssDialog class
 */
class WIDGETSPLUGINSHARED_EXPORT WBaseQssDialog : public QDialog
{
    Q_OBJECT
public:
    explicit WBaseQssDialog(QWidget *parent = 0, Qt::WindowFlags flags = Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Tool | Qt::X11BypassWindowManagerHint);

    /**
     * @brief setBorderImage,set the background image
     * @param fileName,the image size must equal or large than 20*20
     */
    void setBorderImage(const QString &fileName, int flag = 0);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);

private:
    QPixmap borderImage;
    QPoint pressedPoint;
    int    memNum;
    
    WIDGET_EXTENT_FUN_DECLARE
};

#endif // WBASEQSSDIALOG_H
