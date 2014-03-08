#include "wmidwidget.h"
#include "ui_wmidwidget.h"
#include "wappcomm.h"

WMidWidget::WMidWidget(QWidget *parent) :
    WBaseQssWidget(parent),
    ui(new Ui::WMidWidget)
{
    ui->setupUi(this);

}

WMidWidget::~WMidWidget()
{
    delete ui;
}
