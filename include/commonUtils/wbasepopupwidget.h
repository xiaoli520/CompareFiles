#ifndef WBASEPOPUPWIDGET_H
#define WBASEPOPUPWIDGET_H
#include "wbaseqsswidget.h"

class WIDGETSPLUGINSHARED_EXPORT WBasePopupWidget : public WBaseQssWidget
{
    Q_OBJECT
public:
    explicit WBasePopupWidget(QWidget *parent = 0);
protected:
    virtual bool event(QEvent *event);
};

#endif // WBASEPOPUPWIDGET_H
