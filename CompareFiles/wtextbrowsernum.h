#ifndef WTEXTBROWSERNUM_H
#define WTEXTBROWSERNUM_H

#include <QWidget>
#include "wtextbrowser.h"
#include "wbaseqsswidget.h"

namespace Ui {
class WTextBrowserNum;
}

/**
 * @brief The WTextBrowserNum class TextBrowser 行号显示
 */
class WTextBrowserNum : public QWidget
{
    Q_OBJECT

public:
    explicit WTextBrowserNum(QWidget *parent = 0);

    ~WTextBrowserNum();

    void updateLineNumber();

    void paintEvent(QPaintEvent *e);

private:
    Ui::WTextBrowserNum *ui;

    WTextBrowser* m_textBrowser;
};

#endif // WTEXTBROWSERNUM_H
