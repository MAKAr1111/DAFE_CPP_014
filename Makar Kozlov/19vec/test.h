#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "Svector.h"
#include "readshow.h"


class X
{
public:
    X(int z)
    {
        x += 1;
        n = z;
    }
    static int x;

    X(const X& arg)
        : a{arg.a}, n{arg.n}
    {
        x += 1;
        //std::cout << "N: " << n << std::endl;
        if(x > n)
            throw std::runtime_error("x error");
    }

private:
    std::string a = std::string('c', 10000);
    int n;
};


void vec_test();
void vec_test_final();
void vec_test_memory_leak();


#endif
