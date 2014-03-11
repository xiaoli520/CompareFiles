#ifndef DEFINES_H
#define DEFINES_H

/**
 * @brief The sDiffInfo struct 记录行是否相等信息
 */
struct sDiffInfo
{
    int   m_leftLineCount;
    int   m_rightLineCount;
    int   m_lineNumber;
    bool  m_isEqual;
};


#endif // DEFINES_H
