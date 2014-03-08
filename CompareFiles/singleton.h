#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include <memory>
#include <QMutex>

template<typename T>
class Singleton
{
public:
    static T* getInstance()
	{
        if (_instance.get() == NULL)
        {
            _mutex.lock();
            if (_instance.get() == NULL)
                _instance.reset(new T);
            _mutex.unlock();
		}
        return _instance.get();
	}	
private:
    Singleton(){}
    ~Singleton(){}
    Singleton(const Singleton&);
    Singleton& operator= (const Singleton &);

    static std::auto_ptr<T> _instance;
    static QMutex _mutex;
};

template <class T>
std::auto_ptr<T> Singleton<T>::_instance;

template <class T>
QMutex Singleton<T>::_mutex;

#define DECLARE_SINGLETON_CLASS(type) \
	friend class std::auto_ptr<type>; \
    friend class Singleton<type>;

#endif

