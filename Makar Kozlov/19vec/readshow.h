#ifndef READSHOW_H
#define READSHOW_H

#include <iostream>
#include "Svector.h"





template <class T>
void show_vec_str(const Svector<T>& vec)
{
    for(int i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    std::cout << "---" << std::endl; // "--- end of vec" << std::endl;
}

template <class T>
void show_vec(const Svector<T>& vec)
{
    std::cout << "vec: " << std::endl;
    for(auto el : vec)
        std::cout << el << std::endl;
    std::cout << "---" << std::endl; // "--- end of vec" << std::endl;
}

template <class T>
void show_vec_ptr(const Svector<T>& vec)
{
    std::cout << "Shoving vector using ptr: " << std::endl;
    for(T* ptr = vec.begin(); ptr != vec.end(); ++ptr)
    {
        std::cout << *ptr << std::endl;
    }
    std::cout << "---" << std::endl; // "--- end of vec" << std::endl;
}

template <class T>
void show_vec_brackets(const Svector<T>& vec)
{
    std::cout << "Shoving vector using brackets: " << std::endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << std::endl;
    }
    std::cout << "---" << std::endl; // "--- end of vec" << std::endl;
}

template <class T>
void read_vec_ptr(Svector<T>& vec)
{
    std::cout << "Inputing vector using ptr: " << std::endl;
    for(T* ptr = vec.begin(); ptr != vec.end(); ++ptr)
    {
        std::cin >> *ptr;
    }
    std::cout << "---" << std::endl; // "--- end of vec" << std::endl;
}


template<class T>
void read_vec_brackets(Svector<T>& vec)
{
    std::cout << "Inputing vector using brackets: " << std::endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        std::cin >> vec[i];
    }
    std::cout << "---" << std::endl; // "--- end of vec" << std::endl;
}




#endif
