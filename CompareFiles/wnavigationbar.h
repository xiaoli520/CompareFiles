#ifndef WNAVIGATIONBAR_H
#define WNAVIGATIONBAR_H

#include "wbaseqsswidget.h"

namespace Ui {
class WNavigationBar;
}

class WNavigationBar : public WBaseQssWidget
{
    Q_OBJECT

public:
    explicit WNavigationBar(QWidget *parent = 0);
    ~WNavigationBar();

signals:
    void setAutoHide(bool isauto);

private slots:
    void on_leftFileBtn_clicked();

    void on_rightFileBtn_clicked();

    void on_saveFileBtn_clicked();

private:
    Ui::WNavigationBar *ui;
};

#endif // WNAVIGATIONBAR_H
