#include "wappcomm.h"
#include <QDir>
#include <QApplication>
#include <QDebug>
WAppComm::WAppComm()
{
    m_dataMap["qssPath"]=":/qss/";
    m_dataMap["imgePath"]=":/images/";
    m_colorMap["diffFillColor"] = QColor(0xff,0xff,0x00);
    m_colorMap["diffNumberLineColor"] = QColor(0x00,0x00,0x00);
    m_colorMap["notDiffNumberLineColor"]=QColor(0xff,0x00,0x00);
    m_diffShowFont.setFamily(QStringLiteral("微软雅黑"));
    m_diffShowFont.setPixelSize(16);
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


/**
 * @brief getDiffFillColor 获取行不同填充颜色
 * @return
 */
QColor WAppComm::getDiffFillColor()
{
    return m_colorMap["diffFillColor"];
}

/**
 * @brief setDiffFillColor 设置行不同填充颜色
 */
void WAppComm::setDiffFillColor(QColor color)
{
    m_colorMap["diffFillColor"]=color;
}


/**
 * @brief getDiffNumberLineColor 获取行号显示颜色
 * @return
 */
QColor WAppComm::getDiffNumberLineColor()
{
     return m_colorMap["diffNumberLineColor"];
}

/**
 * @brief setDiffNumberLineColor 设置行号显示颜色
 * @param color
 */
void WAppComm::setDiffNumberLineColor(QColor color)
{
    m_colorMap["diffNumberLineColor"]=color;
}

/**
 * @brief getNotDiffNumberLineColor 获取行号不相等显示颜色
 * @return
 */
QColor WAppComm::getNotDiffNumberLineColor()
{
    return m_colorMap["notDiffNumberLineColor"];
}

/**
 * @brief setDiffNumberLineColor 设置行号不相等显示颜色
 * @param color
 */
void WAppComm::setNotDiffNumberLineColor(QColor color)
{
    m_colorMap["notDiffNumberLineColor"] = color;
}

/**
 * @brief getDiffShowFont 获取对比显示字体
 * @return
 */
QFont WAppComm::getDiffShowFont()
{
    return m_diffShowFont;
}

/**
 * @brief setDiffShowFont 设置文字显示font
 * @param font
 */
void WAppComm::setDiffShowFont(QFont font)
{
    m_diffShowFont = font;
}
