#ifndef WMIDWIDGET_H
#define WMIDWIDGET_H

#include <QWidget>
#include "wbaseqsswidget.h"
#include <QScrollBar>
#include "wtextbrowser.h"
#include "wcomparethread.h"

namespace Ui {
class WMidWidget;
}

class WMidWidget : public WBaseQssWidget
{
    Q_OBJECT
    
public:
    explicit WMidWidget(QWidget *parent = 0);
    ~WMidWidget();

    virtual void customEvent(QEvent *event);
    
    void startCompareFile();
private:
    Ui::WMidWidget *ui;

    QScrollBar*     m_leftScrollBar;
    QScrollBar*     m_rightScrollBar;
    WTextBrowser*   m_leftTextBrowser;
    WTextBrowser*   m_rightTextBrowser;
    WCompareThread* m_compareThread;
};

#endif // WMIDWIDGET_H
