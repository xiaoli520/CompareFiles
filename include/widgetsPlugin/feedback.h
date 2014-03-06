#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QWidget>
#include "WBaseQssDialog.h"
#include "WidgetsPlugin_global.h"

class WIDGETSPLUGINSHARED_EXPORT FeedBack : public WBaseQssDialog
{
    Q_OBJECT
public:
    enum TipsLevel
    {
        Warning,
        Wrong
    };

    
public:
    explicit FeedBack(QString title = "", QString content = "", TipsLevel style=Warning, QWidget *parent = 0);
    ~FeedBack();

signals:
    void btnClicked();

private:
    void initControl(QString title, QString content, TipsLevel style);

private slots:
    void cerBtnClicked();

private:
    QWidget *wTop, *wBottom;
    
};

#endif // FEEDBACK_H
