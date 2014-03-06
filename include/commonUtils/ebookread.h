#ifndef EBOOKREAD_H
#define EBOOKREAD_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QString>
#include <QToolButton>
#include "WidgetsPlugin_global.h"
#include "wbaseqsswidget.h"
class EBookTopButton;
class EBookTopWidget;
class WIDGETSPLUGINSHARED_EXPORT EBookRead : public WBaseQssWidget
{
    Q_OBJECT
    
public:
    EBookRead(QWidget *parent = 0);

    ~EBookRead();

    virtual void paintEvent(QPaintEvent *);

public slots:
    virtual void zoomIn(){}
    virtual void zoomOut(){}
    virtual void shareBook(){}
    virtual void fullScreen();
protected:
    virtual void resizeEvent(QResizeEvent *event);

    //初始化控件
    void ControlInit();

    void initTopWidget();


    virtual void adjustWidgetPos();

    virtual void initWidget();


protected slots:
    //显示与隐藏顶窗口
    void showTopWidget();
    void hideTopWidget();

protected:
    //电子书阅读窗口的宽和高
    int width, height;
    //电子书阅读上方的工具栏按钮
    EBookTopButton *ebookTopButton;
    //电子书阅读上方的工具栏窗口
    EBookTopWidget *ebookTopWidget;
    //上方窗口的4个工具按钮
    QToolButton *reduceButton, *largeButton, *shareButton, *fullScreenButton;

};

#endif // EBOOKREAD_H
