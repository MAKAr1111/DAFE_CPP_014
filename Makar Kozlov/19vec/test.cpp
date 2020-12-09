#include "test.h"

int X::x = 0;

void vec_test_memory_leak()
{

    for(int i = 0; i < 1000000; ++i )
    {
        try
        {

            Svector<X> a(100000, X(99990));

        }
        catch(std::exception& e)
        {
            std::cout << i << " " << X::x <<  std::endl;
            X::x = 0;
        }
    }

}



void vec_test()
{
    //simple check

    Svector<std::string> a(3);
    a[0] = "str_elem";
    a[1] =  "work";
    a[2] =  "a";

    show_vec_ptr(a);

    Svector<std::string> b{"str_elem work", "b"};
    Svector<std::string> c{b};
    c[1] = "c";

    show_vec_str(a);
    show_vec_str(b);
    show_vec_str(c);



    Svector<double> d(5);
    d[2] = 2.59;
    show_vec(d);
    Svector<double> copy = d;
    show_vec(copy);

    //copy = 5; //  we avoid it using explicit in assignment constructor
    //without explicit we'd get copy == {0, 0, 0, 0, 0}



    std::cout << "Testing vec of chars and ptr_input: " << std::endl;
    int n = 4;
    char ch[n] = {'a', 'b', 'c', 'd'};
    Svector<char> test_ptr(n);
    //int i = 0;
    for(char* ptr = test_ptr.begin(), i = 0; ptr!= test_ptr.end(); ptr++, i++) //??
        *ptr = ch[i];



    show_vec_str(test_ptr);

    std::cout << "Testing vec of ints and brackets_input: " << std::endl;
    Svector<int> test_brackets(n);
    for(int i = 0; i < n; ++i)
        test_brackets[i] = i;
    show_vec_brackets(test_brackets);

    const Svector<int> cnst_vec = test_brackets;

    //read_vec_brackets(cnst_vec); // cant  change const vector;
    //read_vec_ptr(cnst_vec); // cant  change const vector;

    //cnst_vec = d; cant change const vector

    //checking that we can use vals to elements of const vec by any type of access
    show_vec_brackets(cnst_vec);
    show_vec_ptr(cnst_vec);
    show_vec_str(cnst_vec);
    show_vec(cnst_vec);


}


void vec_test_final()
{
    Svector<double> ex;

    std::cout << "SIZE of vec: " << ex.size() << std::endl;

    std::cout << "Input 5 doubles: " << std::endl;
    int iter = 5;
    while(iter--)
    {
        double val;
        std::cin >> val;
        ex.push_back(val);
    }
    std::cout << "SIZE of vec: " << ex.size() << std::endl;
    show_vec_brackets(ex);

    ex.resize(7);
    std::cout << "Resizing Svector to size 7" << std::endl;
    show_vec_brackets(ex);

    std::cout << "Trying to access the element which is out of range" << std::endl;
    for(int i = 0; i < 10; ++i) //code to check check range errors
    {
        std::cout << ex.at(i) << std::endl;
    }


}

