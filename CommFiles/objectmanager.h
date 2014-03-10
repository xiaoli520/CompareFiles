#ifndef _OBJECTMANAGER_H_
#define _OBJECTMANAGER_H_
#include <QObject>
#include "clearup.h"

class QMutex;

class ObjectManager: public QObject
{
    Q_OBJECT
public:
    ObjectManager(QObject *parent = NULL);
    ~ObjectManager(void);

public slots:
	/**
	* Explicitly initialize (construct the singleton instance of) the
	* ObjectManager.  Returns 0 on success, -1 on failure, and 1
	* if it had already been called.
	*/
    int init();

	/**
	* Explicitly destroy the singleton instance of the
	* ObjectManager.  Returns 0 on success, -1 on failure, and 1
	* if it had already been called.
	*/
    int fini();

public:
	/**
	* Returns 1 before the ObjectManager has been constructed.
	*/
    static int starting_up();

	/**
	* Returns 1 after the ObjectManager has been destroyed.
	*/
    static int shutting_down();

	/**
	* Register an ACE_Cleanup object for cleanup at process termination.
	*/
	static int at_exit (Clearup *object, void *param = 0);

	static int at_exit (void *object,
		CLEANUP_FUNC cleanup_hook,
		void *param = 0);

	static int remove_at_exit(void *object);

    static int get_singleton_lock (QMutex *&lock);

    static ObjectManager *instance();

    enum Object_Manager_State
    {
        OBJ_MAN_UNINITIALIZED = 0,
        OBJ_MAN_INITIALIZING,
        OBJ_MAN_INITIALIZED,
        OBJ_MAN_SHUTTING_DOWN,
        OBJ_MAN_SHUT_DOWN
    };

	enum Preallocated_Object
	{
		PREALLOCATED_OBJECTS  // This enum value must be last!
	};

private:
    /**
     * Returns 1 before ObjectManager has been constructed.
     */
    int starting_up_i();

    /**
     * Returns 1 after ObjectManager has been destroyed.
     */
    int shutting_down_i();

	/// Register an object or array for deletion at program termination.
	/// See description of static version above for return values.
	int at_exit_i(void *object, CLEANUP_FUNC cleanup_hook, void *param);

	/// Remove an object for deletion at program termination.
	/// See description of static version above for return values.
	int remove_at_exit_i(void *object);

	/// Disallow copying by not implementing the following . . 
	ObjectManager (const ObjectManager &);
	ObjectManager &operator= (const ObjectManager &);

private:
    /// State of the Object_Manager;
    Object_Manager_State object_manager_state_;
    bool dynamically_allocated_;
	ExitInfo exit_info_;
    QMutex *internal_lock_;
	static ObjectManager *instance_;
};
#endif /* _OBJECTMANAGER_H_ */
