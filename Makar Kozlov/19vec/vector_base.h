#ifndef VECTORBASE_H
#define VECTORBASE_H

#include <iostream>
#include <exception>
#include <memory>

template<class T, class A = std::allocator<T>>
class vector_base
{
public:
    A alloc;
    T* elem;
    int sz;
    int space;

    vector_base(A a, int n)
        : alloc{a}, elem{a.allocate(n)}, sz{n}, space{n} {}
    ~vector_base() { alloc.deallocate(elem, space); }


};


#endif
