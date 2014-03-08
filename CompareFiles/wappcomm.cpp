#include "wappcomm.h"
#include <QDir>
#include <QApplication>
#include <QDebug>
WAppComm::WAppComm()
{
    m_dataMap["qssPath"]=":/qss/";
    m_dataMap["imgePath"]=":/images/";
}

WAppComm::~WAppComm()
{
}


/**
 * @brief setImagePath  设置图片路径
 * @param path
 */
void WAppComm::setImagePath(QString path)
{
    m_dataMap["imgePath"]=path;
}

/**
 * @brief getImagePath  获取图片文件路径
 * @param filename
 * @return
 */
QString WAppComm::getImagePath(QString filename)
{
    return m_dataMap["imgePath"]+filename;
}


/**
 * @brief setQssFilePath  设置文件路径
 * @param path
 */
void WAppComm::setQssFilePath(QString path)
{
    m_dataMap["qssPath"]=path;
}

/**
 * @brief getQssFilePath  获取qss文件路径
 * @param filename
 * @return
 */
QString WAppComm::getQssFilePath(QString fileName)
{
    qDebug()<<__FUNCTION__<<m_dataMap["qssPath"]+fileName;
    return m_dataMap["qssPath"]+fileName;
}

/**
 * @brief getAppCurrentFile 获取应用程序目录下的文件完整路径
 * @param filename
 * @return
 */
QString WAppComm::getAppCurrentFile(QString filename)
{
    QDir dir(qApp->applicationDirPath());
    return dir.absoluteFilePath(filename);
}

