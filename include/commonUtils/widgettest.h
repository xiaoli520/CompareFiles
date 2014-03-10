#ifndef WIDGETTEST_H
#define WIDGETTEST_H

#include <QWidget>
#include "commonUtils_global.h"
class QLineEdit;
class QPushButton;

class COMMONUTILS_EXPORT WidgetTest : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetTest(QWidget *parent = 0);
    
signals:
    
public slots:
private:
    QLineEdit *edit;
    QPushButton *button;
    
};

#endif // WIDGETTEST_H
