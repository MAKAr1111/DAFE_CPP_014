#ifndef RANGEERROR_H
#define RANGEERROR_H

#include <iostream>
#include <exception>


struct Range_error : std::out_of_range
{
    int index;
    Range_error(int i) : out_of_range{"Range error"}, index{i} {}

};






#endif
