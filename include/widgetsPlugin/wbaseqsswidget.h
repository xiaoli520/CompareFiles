#ifndef WBASEQSSWIDGET_H
#define WBASEQSSWIDGET_H

#include <QWidget>
#include "WidgetsPlugin_global.h"

/**
 * @brief The WBaseQssWidget class, QWidget基础类,支持QSS,凡是工程中自定义QWidget类应继承WBaseQssWidget
 */
class WIDGETSPLUGINSHARED_EXPORT WBaseQssWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WBaseQssWidget(QWidget *parent = 0);

    /**
     * @brief paintEvent, 使widget 支持qss 文件
     */
    virtual void paintEvent(QPaintEvent *);
    

    WIDGET_EXTENT_FUN_DECLARE
};

#endif // WBASEQSSWIDGET_H
