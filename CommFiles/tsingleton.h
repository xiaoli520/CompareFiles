#ifndef _TSINGLETON_H_
#define _TSINGLETON_H_

#include <QMutex>
#include "objectmanager.h"

template <class TYPE>
class TSingleton: public Clearup
{
public:
	/// Global access point to the Singleton.
    static TYPE *getInstance();

	/// Cleanup method to destroy the Singleton.
	virtual void cleanup (void *param = 0);

	/// Explicitly delete the Singleton instance.
	static void close ();

protected:
	/// Default constructor.
    TSingleton(void){}

	/// Contained instance.
	TYPE instance_;

	/// Pointer to the Singleton instance.
    static TSingleton<TYPE> *singleton_;

	/// Get pointer to the Singleton instance.
    static TSingleton<TYPE> *&instance_i()
	{
		return singleton_;
	}
};


template<class TYPE>
TSingleton<TYPE> *TSingleton<TYPE>::singleton_ = NULL;

template<class TYPE>
TYPE* TSingleton<TYPE>::instance()
{
    TSingleton<TYPE> *&singleton = TSingleton<TYPE>::instance_i();
	if (singleton == NULL)
	{
		if (ObjectManager::starting_up() || ObjectManager::shutting_down())
		{
            singleton = new TSingleton<TYPE>();
		}
		else
		{
            static QMutex *lock = 0;
            if (ObjectManager::get_singleton_lock (lock) != 0)
                return 0;
            lock->lock();
			if (singleton == NULL)
			{
                singleton = new TSingleton<TYPE>();
				ObjectManager::at_exit(singleton);
			}
            lock->unlock();
		}
	}
    return &singleton->instance_;
}

template<class TYPE>
void TSingleton<TYPE>::cleanup (void *param)
{
	ObjectManager::remove_at_exit(param);
	delete this;
    TSingleton<TYPE>::instance_i() = NULL;
}

template<class TYPE>
void TSingleton<TYPE>::close()
{
    TSingleton<TYPE> *&singleton = TSingleton<TYPE>::instance_i();
	if (singleton)
	{
		singleton->cleanup();
        TSingleton<TYPE>::instance_i() = NULL;
	}
}

#define DECLARE_SINGLETON_CLASS(type) \
    friend class TSingleton<type>;

#endif /* _TSINGLETON_H_ */
