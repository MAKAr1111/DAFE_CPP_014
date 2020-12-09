#ifndef SVECTOR_H
#define SVECTOR_H

#include <iostream>

template<class T>
class Svector
{
public:
    Svector() : sz{0}, elem{ new T[0] } {}

    explicit Svector(int n);

    Svector(std::initializer_list<T> lst)
        : sz{static_cast<int>(lst.size())}, elem{new T[static_cast<int>(lst.size())]}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }
    ~Svector() { delete[] elem; }

    Svector(const Svector&);
    Svector(Svector&& a);


    int size() const { return sz; }

    T get(int n) const { return elem[n]; }
    void set(int n, T val) { elem[n] = val; }

    T* begin() const { return elem; }
    T* end() const { return elem + sz; }

    Svector& operator=(const Svector&);
    Svector& operator=(Svector&&);
    T& operator[](int n) { return elem[n]; }
    const T& operator[](int n) const { return elem[n]; }


private:
    int sz;
    T* elem;

};





template <class T>
Svector<T>::Svector(int n)
    : sz{n}, elem{new T[n]}
{
    if(typeid (T) == typeid (int) || typeid (T) == typeid (double)|| typeid (T) == typeid (char) )
        for(int i = 0; i < sz; ++i)
            elem[i] = static_cast<T>(0);
}



template <class T>
Svector<T>::Svector(const Svector& arg)
    : sz{arg.sz}, elem{new T[arg.sz]}
{
    std::copy(arg.begin(), arg.end(), elem);


}


template <class T>
Svector<T>& Svector<T>::operator=(const Svector& a)
{
    T* ptr = new T[a.sz];
    std::copy(a.elem, a.elem + a.sz, ptr);
    delete[] elem;
    elem = ptr;
    sz = a.sz;
    return *this;
}


template <class T>
Svector<T>::Svector(Svector&& a)
    : sz{a.sz}, elem{a.elem}
{
    a.sz  = 0;
    a.elem = nullptr;
}


template <class T>
Svector<T>& Svector<T>::operator=(Svector&& a)
{
    delete [] elem;
    elem = a.elem;
    sz = a.sz;
    a.elem = nullptr;
    a.sz = 0;
    return *this;
}

#endif VECTOR_H
