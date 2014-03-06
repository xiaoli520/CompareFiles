#ifndef WNAVIGATIONALBAR_H
#define WNAVIGATIONALBAR_H

#include <QToolButton>
#include <QMap>
#include "WidgetsPlugin_global.h"
#include "wbaseqsswidget.h"
class QButtonGroup;

class WNavigationalSeparator :public WBaseQssWidget
{
    Q_OBJECT
public:
    QSize sizeHint() const;
private:
    WNavigationalSeparator(QWidget *parent = 0);

    friend class WNavigationalBar;
};

class WNavigationalButton : public QToolButton
{
    Q_OBJECT
public:
    enum StyleType
    {
        StyleIcon,            ///< Icon change when press, checkable is false
        StyleText,            ///< only display text,background,checkable is false
        StyleIconCheckable,   ///< Icon and background change when press, checkable is true
        StyleTextCheckable    ///< only display text,background change when press, checkable is true
    };

private:
    WNavigationalButton(StyleType styleType = StyleIcon, int id = 0,
                        const QString &objectName = "", const QString &text = "", QWidget *parent = 0);

    StyleType style;  ///we will set different effect by qss according to the style
    int eventId;

    static const char* styleName;

    friend class WNavigationalBar;
};

class WIDGETSPLUGINSHARED_EXPORT WNavigationalBar : public WBaseQssWidget
{
    Q_OBJECT
public:
    explicit WNavigationalBar(QWidget *parent = 0);

    WNavigationalSeparator* createSeparator();
    WNavigationalButton* createButton(WNavigationalButton::StyleType styleType = WNavigationalButton::StyleIcon,
                                      int id = 0, const QString &objectName = "", const QString &text = "", bool isIconBtn = false);
    QSize sizeHint()const;

signals:
    void eventTriggered(int id);
    void statusChanged(int preId, int curId);

public slots:
    /**
     * @brief changeStatus, take notice of that it'll send statusChanged signal
     * @param id,the event id
     */
    void changeStatus(int id);

protected slots:
    void btClicked();
    void btToggled(bool checked);

private:
    int preStatusId;
    int curStatusId;
    QButtonGroup *btGroup;
    QMap<int, WNavigationalButton*> mapIdButtons;
};

#endif // WNAVIGATIONALBAR_H
