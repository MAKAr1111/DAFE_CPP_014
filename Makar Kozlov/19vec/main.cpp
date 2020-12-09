#include <iostream>

#include "Svector.h"
#include "readshow.h"
#include "test.h"
#include "range_error.h"







int main()
try
{

    return 0;
}
catch(Range_error& r)
{
    std::cerr << r.what() << " " << r.index << std:: endl;
}
catch(std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return 1;
}
catch (...)
{
    std::cerr << "unknown error" << std::endl;
    return 2;
}


