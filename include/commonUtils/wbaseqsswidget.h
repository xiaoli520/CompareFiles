#ifndef WBASEQSSWIDGET_H
#define WBASEQSSWIDGET_H

#include <QWidget>
#include "WidgetsPlugin_global.h"

/**
 * @brief The WBaseQssWidget class, inherit from this class to support Qss
 */
class WIDGETSPLUGINSHARED_EXPORT WBaseQssWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WBaseQssWidget(QWidget *parent = 0);

    /**
     * @brief paintEvent, let widget support Qss
     */
    virtual void paintEvent(QPaintEvent *);
    

    WIDGET_EXTENT_FUN_DECLARE
};

#endif // WBASEQSSWIDGET_H
