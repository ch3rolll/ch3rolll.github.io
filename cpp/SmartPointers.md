# Smart Pointers

## V.S. Raw pointers
1. Have same interfaces: dereferencing(operator `*`) and indirection (operator `->`)
2. To solve the common issues with raw pointers. Most common bugs in C++ is related to pointers and memory management:
- dangling pointers
- memory leaks
- allocation failures

## Why Smart Pointers?
Less bugs:
1. Automatic cleanup
2. Automatic initialization
3. Dangling pointers
4. Funtionalities:

Pointers|Functions
---|---
copied_ptr | Create a new copy
owned_ptr | Transfer ownership
counted_ptr | Reference counting
linked_ptr | Reference linking
cow_ptr | Copy on write

5. Exception Safety

6. STL containers  


```cpp
	MyClass* p(new MyClass);
	MyClass* q = p;
	delete p;
	p->DoSomething();   // Watch out! p is now dangling!
	p = NULL;           // p is no longer dangling
	q->DoSomething();   // Ouch! q is still dangling!
	For auto_ptr, this is solved by setting its pointer to NULL when it is copied:
	template <class T>
	auto_ptr<T>& auto_ptr<T>::operator=(auto_ptr<T>& rhs)
	{
	    if (this != &rhs) {
	        delete ptr;
	        ptr = rhs.ptr;
	        rhs.ptr = NULL;
	    }
	    return *this;
	}
```

## auto_ptr

### Interfaces:

```cpp
template <class T> class auto_ptr
{
    T* ptr;
public:
    explicit auto_ptr(T* p = 0) : ptr(p) {}
    ~auto_ptr()                 {delete ptr;}
    T& operator*()              {return *ptr;}
    T* operator->()             {return ptr;}
    // ...
};
```

### Smartness

auto_ptr is smarter b/c it takes care of deleting in its destructor.
```cpp
void foo()
{
    auto_ptr<MyClass> p(new MyClass);
    p->DoSomething();
}
```
## linked_ptr

### Smartness

```cpp
vector< linked_ptr<Base> > v;
v.push_back(new Base);      // OK
v.push_back(new Derived);   // OK too
```




