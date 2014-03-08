#ifndef WMIDWIDGET_H
#define WMIDWIDGET_H

#include <QWidget>
#include "wbaseqsswidget.h"

namespace Ui {
class WMidWidget;
}

class WMidWidget : public WBaseQssWidget
{
    Q_OBJECT
    
public:
    explicit WMidWidget(QWidget *parent = 0);
    ~WMidWidget();
    
private:
    Ui::WMidWidget *ui;
};

#endif // WMIDWIDGET_H
