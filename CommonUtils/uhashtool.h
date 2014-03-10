#ifndef UHASHTOOL_H
#define UHASHTOOL_H
#include "commonUtils_global.h"

class COMMONUTILS_EXPORT UHashTool
{
public:
    /**
     * @brief BKDRHash
     * @detail 本算法由于在Brian Kernighan与Dennis Ritchie的《The C Programming Language》一书被展示而得名，
     *         是一种简单快捷的hash算法，也是Java目前采用的字符串的Hash算法（累乘因子为31）
     * @param data
     * @param len
     * @return
     */
    static size_t BKDRHash(const char* data,int len);

    /**
     * @brief SDKRHash
     * @detail 本算法是由于在开源项目SDBM（一种简单的数据库引擎）中被应用而得名，它与BKDRHash思想一致,只是种子不同而已。
     * @param data
     * @param len
     * @return
     */
    static size_t SDKRHash(const char* data,int len);

    /**
     * @brief RSHash
     * @detail 因Robert Sedgwicks在其《Algorithms in C》一书中展示而得名。
     * @param data
     * @param len
     * @return
     */
    static size_t RSHash(const char* data,int len);

    /**
     * @brief APHash
     * @detail 由Arash Partow发明的一种hash算法
     * @param data
     * @param len
     * @return
     */
    static size_t APHash(const char* data,int len);

    /**
     * @brief JSHash
     * @detail 由Justin Sobel发明的一种hash算法。
     * @param data
     * @param len
     * @return
     */
    static size_t JSHash(const char* data,int len);

    /**
     * @brief DEKHash
     * @detail 本算法是由于Donald E. Knuth在《Art Of Computer Programming Volume 3》中展示而得
     * @param data
     * @param len
     * @return
     */
    static size_t DEKHash(const char* data,int len);

    /**
     * @brief FNVHash
     * @detail Unix system系统中使用的一种著名hash算法，后来微软也在其hash_map中实现。
     * @param data
     * @param len
     * @return
     */
    static size_t FNVHash(const char* data,int len);

    /**
     * @brief DJBHash
     * @detail 由Daniel J. Bernstein教授发明的一种hash算法。
     * @param data
     * @param len
     * @return
     */
    static size_t DJBHash(const char* data,int len);

    /**
     * @brief DJBHash
     * @detail 由Daniel J. Bernstein教授发明的另一种hash算法。
     * @param data
     * @param len
     * @return
     */
    static size_t DJB2Hash(const char* data,int len);

    /**
     * @brief PJWHash
     * @detail 本算法是基于AT&T贝尔实验室的Peter J. Weinberger的论文而发明的一种hash算法。
     * @param data
     * @param len
     * @return
     */
    static size_t PJWHash(const char* data,int len);

    /**
     * @brief ELFHash
     * @detail 由于在Unix的Extended Library Function被附带而得名的一种hash算法，它其实就是PJW Hash的变形。
     * @param data
     * @param len
     * @return
     */
    static size_t ELFHash(const char* data,int len);

};

#endif // UHASHTOOL_H
