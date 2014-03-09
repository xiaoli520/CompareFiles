#ifndef WTOPWIDGET_H
#define WTOPWIDGET_H

#include <QWidget>
#include "wbaseqsswidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
class FeedBack;

namespace Ui {
class WTopWidget;
}

class WTopWidget : public WBaseQssWidget
{
    Q_OBJECT
    
public:
    explicit WTopWidget(QWidget *parent = 0);

    ~WTopWidget();

    /**
     * @brief mousePressEvent 自定义鼠标拖动事件
     * @param pMouseEvent
     */
    void mousePressEvent(QMouseEvent* pMouseEvent);

    /**
     * @brief mousePressEvent 自定义鼠标拖动事件
     * @param pMouseEvent
     */
    void mouseMoveEvent(QMouseEvent* pMouseEvent);

    /**
     * @brief mousePressEvent 自定义鼠标拖动事件
     * @param pMouseEvent
     */
    void mouseDoubleClickEvent(QMouseEvent *);

signals:
    void showMax();
    void showNormal();
    void triggerClose();

private slots:
    void showMaxRestore();

private:
    Ui::WTopWidget *ui;

    QPushButton*     m_Minimize;
    QPushButton*     m_Maximize;
    QPushButton*     m_Close;
    QLabel*          m_logoLabel;
    QHBoxLayout*     m_hboxLayout;
    QPoint       m_DragPosition;       //定义位置缓存
    QPoint       m_StartPos;
    QPoint       m_ClickPos;
    bool         m_isMax;

};

#endif // WTOPWIDGET_H
