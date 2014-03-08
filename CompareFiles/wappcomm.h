#ifndef WAPPCOMM_H
#define WAPPCOMM_H

#include <QString>
#include <QList>
#include <QMap>
#include "singleton.h"
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

private:
    /**
     * @brief m_dataMap    数据存放 随着程序增加,公用数据变量会增大,采用map 可减少数据变量定义
     */
    QMap<QString,QString>      m_dataMap;


    DECLARE_SINGLETON_CLASS(WAppComm)
};

#define PTR_WAPP_COMM Singleton<WAppComm>::getInstance()

#endif // WAPPCOMM_H
