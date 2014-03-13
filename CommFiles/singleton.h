#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include <cstdlib>
#include <iostream>
using namespace std;

/**
 *   使用模板编写单列模式，单列代码重复
 */
template <typename T>
class Singleton
{
public:
    static T*getInstance()
    {
        init();
        return instance_;
    }

private:
    static void init()
    {
        if (instance_ == 0)
        {
            instance_ = new T;
            atexit(destroy); //程序结束时调用注册的函数
        }
    }
    static void destroy()
    {
        delete instance_;
    }
    Singleton(const Singleton &other);
    Singleton &operator=(const Singleton &other);
    Singleton();
    ~Singleton();

    static T *instance_;
};

template <typename T>
T *Singleton<T>::instance_ = 0;
#endif

