#ifndef WPOPUPWIDGET_H
#define WPOPUPWIDGET_H
#include "WBaseWidget.h"
#include "ui_wpopupwidget.h"
#include "WidgetsPlugin_global.h"

//µ¯³ö¶Ô»°¿ò
class WIDGETSPLUGINSHARED_EXPORT WPopupWidget : public WBaseWidget
{
	Q_OBJECT

public:
	WPopupWidget(QWidget *parent = 0);

	~WPopupWidget();

private:
	Ui::WPopupWidget ui;
};

#endif // WPOPUPWIDGET_H

