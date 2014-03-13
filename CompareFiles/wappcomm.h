#ifndef WAPPCOMM_H
#define WAPPCOMM_H

#include <QString>
#include <QList>
#include <QMap>
#include "singleton.h"
#include <QColor>
#include <QFont>

/**
 * @brief The WAppComm class 用于应用公共数据记录 单例
 */
class WAppComm
{
public:

    ~WAppComm();

    WAppComm();

    /**
     * @brief setImagePath  设置图片路径
     * @param path
     */
    void setImagePath(QString path);

    /**
     * @brief getImagePath  获取图片文件路径
     * @param filename
     * @return
     */
    QString getImagePath(QString filename);

    /**
     * @brief setQssFilePath  设置文件路径
     * @param path
     */
    void setQssFilePath(QString path);

    /**
     * @brief getQssFilePath  获取qss文件路径
     * @param filename
     * @return
     */
    QString getQssFilePath(QString filename);

    /**
     * @brief getAppCurrentFile 获取应用程序目录下的文件完整路径
     * @param filename
     * @return
     */
    QString getAppCurrentFile(QString filename);

    /**
     * @brief getDiffFillColor 获取行不同填充颜色
     * @return
     */
    QColor getDiffFillColor();

    /**
     * @brief setDiffFillColor 设置行不同填充颜色
     */
    void setDiffFillColor(QColor color);

    /**
     * @brief getDiffNumberLineColor 获取行号显示颜色
     * @return
     */
    QColor getDiffNumberLineColor();

    /**
     * @brief setDiffNumberLineColor 设置行号显示颜色
     * @param color
     */
    void setDiffNumberLineColor(QColor color);

    /**
     * @brief getNotDiffNumberLineColor 获取行号不相等显示颜色
     * @return
     */
    QColor getNotDiffNumberLineColor();

    /**
     * @brief setDiffNumberLineColor 设置行号不相等显示颜色
     * @param color
     */
    void setNotDiffNumberLineColor(QColor color);


    /**
     * @brief getDiffShowFont 获取对比显示字体
     * @return
     */
    QFont getDiffShowFont();

    /**
     * @brief setDiffShowFont 设置文字显示font
     * @param font
     */
    void setDiffShowFont(QFont font);
private:
    /**
     * @brief m_dataMap    数据存放 随着程序增加,公用数据变量会增大,采用map 可减少数据变量定义
     */
    QMap<QString,QString>      m_dataMap;


    /**
     * @brief m_colorMap  颜色数据存放 随着自定义要求增加,颜色数据增多
     */
    QMap<QString,QColor>       m_colorMap;

    QFont                      m_diffShowFont;

};

#define PTR_WAPP_COMM Singleton<WAppComm>::getInstance()

#endif // WAPPCOMM_H
