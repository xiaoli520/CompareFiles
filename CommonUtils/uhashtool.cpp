#include "uhashtool.h"

/**
 * @brief BKDRHash
 * @detail 本算法由于在Brian Kernighan与Dennis Ritchie的《The C Programming Language》一书被展示而得名，
 *         是一种简单快捷的hash算法，也是Java目前采用的字符串的Hash算法（累乘因子为31）
 * @param data
 * @param len
 * @return
 */
size_t UHashTool::BKDRHash(const char* data,int len)
{
    register size_t hash = 0;
    while(len-- >= 0)
    {
        size_t ch=*data;
        hash = hash * 131 + ch;
        data++;
    }
    return hash;
}

/**
 * @brief SDKRHash
 * @detail 本算法是由于在开源项目SDBM（一种简单的数据库引擎）中被应用而得名，它与BKDRHash思想一致,只是种子不同而已。
 * @param data
 * @param len
 * @return
 */
size_t UHashTool::SDKRHash(const char* data,int len)
{
    register size_t hash = 0;
    while(len-- >= 0)
    {
        size_t ch=*data;
        hash = 65599 * hash + ch;
        data++;
    }
    return hash;
}

/**
 * @brief RSHash
 * @detail 因Robert Sedgwicks在其《Algorithms in C》一书中展示而得名。
 * @param data
 * @param len
 * @return
 */
size_t UHashTool::RSHash(const char* data,int len)
{
    register size_t hash = 0;
    size_t magic = 63689;
    while(len-- >= 0)
    {
        size_t ch=*data;
        hash = hash * magic + ch;
        magic *= 378551;
        data++;
    }

    return hash;
}

/**
 * @brief APHash
 * @detail 由Arash Partow发明的一种hash算法
 * @param data
 * @param len
 * @return
 */
size_t UHashTool::APHash(const char* data,int len)
{
    register size_t hash = 0;
    int i=0;
    while(len-- >= 0)
    {
        size_t ch=*data;
        if ((i & 1) == 0)
        {
            hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
        }
        else
        {
            hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
        }
        i++;
        *data++;
    }
    return hash;
}

/**
 * @brief JSHash
 * @detail 由Justin Sobel发明的一种hash算法。
 * @param data
 * @param len
 * @return
 */
size_t UHashTool::JSHash(const char* data,int len)
{
    register size_t hash = 0;
    while(len-- >= 0)
    {
        size_t ch=*data;
        hash ^= ((hash << 5) + ch + (hash >> 2));
        data++;
    }

    return hash;
}

/**
 * @brief DEKHash
 * @detail 本算法是由于Donald E. Knuth在《Art Of Computer Programming Volume 3》中展示而得
 * @param data
 * @param len
 * @return
 */
size_t UHashTool::DEKHash(const char* data,int len)
{
    register size_t hash = 1315423911;
    while(len-- >= 0)
    {
        size_t ch=*data;
        hash ^= ((hash << 5) + ch + (hash >> 2));
        data++;
    }
    return hash;
}

/**
 * @brief FNVHash
 * @detail Unix system系统中使用的一种著名hash算法，后来微软也在其hash_map中实现。
 * @param data
 * @param len
 * @return
 */
size_t UHashTool::FNVHash(const char* data,int len)
{
    register size_t hash = 2166136261;
    while(len-- >= 0)
    {
        size_t ch=*data;
        hash *= 16777619;
        hash ^= ch;
        data++;
    }

    return hash;
}

/**
 * @brief DJBHash
 * @detail 由Daniel J. Bernstein教授发明的一种hash算法。
 * @param data
 * @param len
 * @return
 */
size_t UHashTool::DJBHash(const char* data,int len)
{
    register size_t hash = 5381;
    while(len-- >= 0)
    {
        size_t ch=*data;
       hash += (hash << 5) + ch;
       data++;
    }

    return hash;

}

/**
 * @brief DJBHash
 * @detail 由Daniel J. Bernstein教授发明的另一种hash算法。
 * @param data
 * @param len
 * @return
 */
size_t UHashTool::DJB2Hash(const char* data,int len)
{
    register size_t hash = 5381;
    while(len-- >= 0)
    {
        size_t ch=*data;
       hash = hash * 33 ^ ch;
       data++;
    }

    return hash;
}

/**
 * @brief PJWHash
 * @detail 本算法是基于AT&T贝尔实验室的Peter J. Weinberger的论文而发明的一种hash算法。
 * @param data
 * @param len
 * @return
 */
size_t UHashTool::PJWHash(const char* data,int len)
{
    static const size_t TotalBits       = sizeof(size_t) * 8;
    static const size_t ThreeQuarters   = (TotalBits  * 3) / 4;
    static const size_t OneEighth       = TotalBits / 8;
    static const size_t HighBits        = ((size_t)-1) << (TotalBits - OneEighth);

    register size_t hash = 0;
    size_t magic = 0;
    while(len-- >= 0)
    {
        size_t ch=*data;
        hash = (hash << OneEighth) + ch;
        if ((magic = hash & HighBits) != 0)
        {
            hash = ((hash ^ (magic >> ThreeQuarters)) & (~HighBits));
        }
        data++;
    }
    return hash;

}

/**
 * @brief ELFHash
 * @detail 由于在Unix的Extended Library Function被附带而得名的一种hash算法，它其实就是PJW Hash的变形。
 * @param data
 * @param len
 * @return
 */
size_t UHashTool::ELFHash(const char* data,int len)
{
    static const size_t TotalBits       = sizeof(size_t) * 8;
    static const size_t ThreeQuarters   = (TotalBits  * 3) / 4;
    static const size_t OneEighth       = TotalBits / 8;
    static const size_t HighBits        = ((size_t)-1) << (TotalBits - OneEighth);
    register size_t hash = 0;
    size_t magic = 0;
    while(len-- >= 0)
    {
        size_t ch=*data;
        hash = (hash << OneEighth) + ch;
        if ((magic = hash & HighBits) != 0)
        {
            hash ^= (magic >> ThreeQuarters);
            hash &= ~magic;
        }

        data++;
    }
    return hash;
}
