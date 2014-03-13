#ifndef DEFINES_H
#define DEFINES_H
#include <QString>
/**
 * @brief The sDiffInfo struct 记录行是否相等信息
 */
struct sDiffInfo
{
    int   m_leftLineCount;  //右边行字节个数,用于自绘显示自动换行时计算真实行号
    int   m_rightLineCount; //右边行字节个数,用于自绘显示自动换行时计算真实行号
    int   m_lineNumber;     //行号
    bool  m_isEqual;        //是否相等

    QString toString()
    {
        QString number="%1:%2:%3:%4";
        number=number.arg(QString::number(m_lineNumber)).arg(QString::number(m_isEqual)).arg(QString::number(m_leftLineCount)).arg(QString::number(m_rightLineCount));
        return number;
    }
};


#endif // DEFINES_H
