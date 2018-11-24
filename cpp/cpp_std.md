1. std::unique_lock:

- The class unique_lock is a general-purpose mutex ownership wrapper allowing deferred locking, time-constrained attempts at locking, recursive locking, transfer of lock ownership, and use with condition variables.

- The class unique_lock is movable, but not copyable -- it meets the requirements of MoveConstructible and MoveAssignable but not of CopyConstructible or CopyAssignable.

- The class unique_lock meets the BasicLockable requirements. If Mutex meets the Lockable requirements, unique_lock also meets the Lockable requirements (ex.: can be used in std::lock); if Mutex meets the TimedLockable requirements, unique_lock also meets the TimedLockable requirements.

2. std::mutex:
- The mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads.

- mutex offers exclusive, non-recursive ownership semantics:

- A calling thread owns a mutex from the time that it successfully calls either lock or try_lock until it calls unlock.
When a thread owns a mutex, all other threads will block (for calls to lock) or receive a false return value (for try_lock) if they attempt to claim ownership of the mutex.
- A calling thread must not own the mutex prior to calling lock or try_lock.
The behavior of a program is undefined if a mutex is destroyed while still owned by any threads, or a thread terminates while owning a mutex. The mutex class satisfies all requirements of Mutex and StandardLayoutType.

- std::mutex is neither copyable nor movable.


3. static
Interview Question - What's static?
This is one of the frequently asked questions during the interview. Most of the candidates get the first one, and some with the second, third, and may be 4th ones as well. But rarely they address the 5th one:

- A variable declared static within the body of a function maintains its value between invocations of the function.
- A variable declared static within a module (but outside the body of a function) is accessible by all functions within that module. However, it is not accessible by functions from other modules.
static members exist as members of the class rather than as an instance in each object of the class. There is only a single instance of each static data member for the entire class.
- Non-static member functions can access all data members of the class: static and non-static. 
- Static member functions can only operate on the static data members.
- C functions declared static within a module may only be called by other functions within that module (file scope).


4. std::transform

Applies an operation sequentially to the elements of one (1) or two (2) ranges and stores the result in the range that begins at result.

This operation could be :
- unary operation: Applies op to each of the elements in the range [first1,last1) and stores the value returned by each operation in the range that begins at result.
- binary operation: Calls binary_op using each of the elements in the range [first1,last1) as first argument, and the respective argument in the range that begins at first2 as second argument. The value returned by each call is stored in the range that begins at result.
