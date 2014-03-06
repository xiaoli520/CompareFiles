#ifndef WPROMPTDLG_H
#define WPROMPTDLG_H

#include <QWidget>
#include "WBaseQssDialog.h"
#include "WidgetsPlugin_global.h"

class WIDGETSPLUGINSHARED_EXPORT WPromptDlg : public WBaseQssDialog
{
    Q_OBJECT
public:
    enum PromptType
    {
        oneBtn,
        twoBtn
    };

    enum PromptIconType
    {
        warning      //感叹号
    };


    enum ClickBtnId
    {
        Confirm_OneBtn,
        Confirm_TwoBtn,
        Cancel
    };

public:
    explicit WPromptDlg(QString title, QString content,PromptIconType iconStyle=warning,PromptType style=oneBtn, QWidget *parent = 0);
    ~WPromptDlg();

    void setConfirmBtnName(const QString& name);
    void setCancelBtnName(const QString& name);
signals:
    void btnClickedSignal(int id);

private:
    void initControl(QString title, QString content,PromptIconType iconStyle, PromptType style);

private slots:
    void ConfirmbtnClickedSLot();
    void CancelbtnClickedSLot();

private:
    QWidget *wTop, *wBottom;
    QPushButton *ConfirmBtn;
    QPushButton *CancelBtn;

    PromptType promptType;
};

#endif // WPROMPTDLG_H
