#ifndef WSEARCHWIDGET_H
#define WSEARCHWIDGET_H

#include <QWidget>
#include "WidgetsPlugin_global.h"

#include "WBaseQssWidget.h"
class QVBoxLayout;
class QPushButton;
#include <QVector>
#include "lineedit.h"

namespace Ui
{
class WSearchWidget;
}

class WIDGETSPLUGINSHARED_EXPORT WSearchWidget : public WBaseQssWidget
{
	Q_OBJECT

public:
	WSearchWidget(QWidget *parent = 0);

	~WSearchWidget();

	//过滤回车消息
	bool eventFilter(QObject* obj,QEvent* pevent);

    QString getSearchText();
    void changeSearchText(QString str);

    void setPlaceholderText(QString str);
    void setMaxLength(int len);
signals:

	//搜索事件
	void onSearchEvent(const QString& str);  

	//文字变化事件
	void searchTextChanged(QString str);

public slots:
	
	//响应搜索事件
    void onSearchBtnCliked();
    void onDeleteBtnCliked();
private slots:
    void searchTextChangedSlot(QString str);
private:
    Ui::WSearchWidget* ui;
};

class WIDGETSPLUGINSHARED_EXPORT WHistoryList : public WBaseQssWidget
{
    Q_OBJECT

public:
    WHistoryList(QStringList list, QWidget *parent = 0);
    ~WHistoryList();

signals:
    void sendMessage(QString);

private slots:
    void clickedBtnEvent();

private:
    QVBoxLayout* mainLayout;
    QVector <QPushButton *> btnVtor;
};

#endif // WSEARCHWIDGET_H
