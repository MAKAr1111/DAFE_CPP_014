#ifndef SVECTOR_H
#define SVECTOR_H

#include <iostream>
#include <exception>
//#include <algorithm>
#include <memory>

#include "vector_base.h"
#include "range_error.h"

//int a;
//std::allocator<int> a;
//a.allocate(5, &a);

template<class T, class A = std::allocator<T>>
class Svector   : private vector_base<T, A>
{
public:
    Svector() : vector_base<T, A>(A(), 0) {} //sz{0}, space{0}, elem{ alloc.allocate(0) } {}

    explicit Svector(int n, T val = T());

    Svector(std::initializer_list<T> lst);
    ~Svector(){}

    Svector(const Svector&);
    Svector(Svector&& a);


    int size() const { return this->sz; }
    int capacity() const { return this->space; }


    T* begin() const { return this->elem; }
    T* end() const { return this->elem + this->sz; }

    Svector& operator=(const Svector&);
    Svector& operator=(Svector&&);
    T& operator[](int n);
    const T& operator[](int n) const;
    T& at(int n);
    const T& at(int n) const;

    void reserve(int newalloc);
    void resize(int newsize, T val = T());
    void push_back(const T& val);



};




template <class T, class A>
Svector<T, A>::Svector(int n, T val)
    :  vector_base<T, A>(A(), n)
{
    //for(int i = 0; i < this->sz; ++i)
    std::uninitialized_fill(this->elem, this->elem + this->sz, val);
}

template<class T, class A>
Svector<T, A>::Svector(std::initializer_list<T> lst)
    :  vector_base<T, A>(A(), lst.size())
{
    for(int i = 0; i < this->sz; ++i)
        this->alloc.construct(&this->elem[i], *(lst.begin() + i)); // for some reason we can't use [] operator for initialiser list
}



template <class T, class A>
Svector<T, A>::Svector(const Svector& arg)
    : vector_base<T, A>(A(), arg.size())
{
    for(int i = 0; i < this->sz; ++i)
        this->alloc.construct(&this->elem[i], arg[i]);
}




template <class T, class A>
Svector<T, A>& Svector<T, A>::operator=(const Svector& a)
{
    if (this == &a)     // selfcopying
        return *this;
    if(a.size() <= this->space)
    {
        for(int i = 0; i < this->sz; ++i)
            this->alloc.construct(&this->elem[i], a[i]);
        this->sz = a.sz;
        return *this;
    }
    T* ptr = this->alloc.allocate(a.sz);

    for(int i = 0; i < this->sz; ++i)
        this->alloc.construct(&this->elem[i], ptr[i]);
    this->alloc.delocate(this->elem, this->sz);

    this->elem = ptr;
    this->sz = this->space = a.sz;
    return *this;
}


template <class T, class A>
Svector<T, A>::Svector(Svector&& a)
{
    this->elem = a.elem;
    this->space = this->sz = a.size();
    a.sz  = 0;
    a.elem = nullptr;
}


template <class T, class A>
Svector<T, A>& Svector<T, A>::operator=(Svector&& a)
{
    delete [] this->elem;
    this->elem = a.elem;
    this->sz = a.sz;
    this->space = a.sz;
    a.elem = nullptr;
    a.sz = 0;
    a.space = 0;
    return *this;
}


template <class T, class A>
void Svector<T, A>::reserve(int newalloc)
{

    int cur_size = this->sz;
    if(newalloc <= this->sz) return;
    vector_base<T, A> new_base(this->alloc, newalloc);
    std::uninitialized_copy(this->elem, this->elem + this->sz, new_base.elem); //copying


    for(int i = 0; i < this->sz; ++i)
        this->alloc.destroy(&this->elem[i]);

    std::swap<vector_base<T, A>>(*this, new_base);
    this->sz = cur_size;


    //    T *elem_resized = alloc.allocate(newalloc);  //new T[newalloc];
    //    for(int i = 0; i < sz; ++i)
    //        alloc.construct(&elem_resized[i], elem[i]);   //elem_resized[i] = elem[i];
    //    for(int i = 0; i < sz; ++i)
    //        alloc.destroy(&elem[i]);
    //    alloc.deallocate(elem, space);   //delete[] elem;
    //    elem = elem_resized;
    //    space = newalloc;
}

template <class T, class A>
void Svector<T, A>::resize(int newsize, T val) // T val = T()
{
    reserve(newsize);
    for(int i = size(); i < newsize; ++i)
        this->alloc.construct(&this->elem[i], val);
    for(int i = newsize; i < size(); ++i)
        this->alloc.destroy(&this->elem[i]);
    this->sz = newsize;
}

template  <class T, class A>
void Svector<T, A>::push_back(const T& val)
{
    if(this->space == 0)
        reserve(8);
    else if(size() == this->space)
        reserve(size()*2);

    this->alloc.construct(&this->elem[size()], val);
    this->sz += 1;

}


template  <class T, class A>
T& Svector<T, A>::at(int n)
{
    if(n < 0 || n >= this->size())
        throw Range_error(n);
    return this->elem[n];
}


template  <class T, class A>
const T& Svector<T, A>::at(int n) const
{
    if(n < 0 || n >= this->size())
        throw Range_error(n);
    return this->elem[n];
}



template  <class T, class A>
T& Svector<T, A>::operator[](int n)
{
    return this->elem[n];
}


template  <class T, class A>
const T& Svector<T, A>::operator[](int n) const
{
    return this->elem[n];
}





#endif
