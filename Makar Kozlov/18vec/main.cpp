#include <iostream>
#include "vector.h"
#include "readshow.h"
#include "test.h"


int main()
try
{
    vec_test();
    return 0;
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







