#include "test.h"



void vec_test()
{

    Svector<std::string> a(3);
    a.set(0, "str_elem");
    a.set(1, "work");
    a.set(2, "a");

    show_vec_ptr(a);

    Svector<std::string> b{"str_elem work", "b"};
    Svector<std::string> c{b};
    c.set(1, "c");

    show_vec_str(b);
    show_vec_str(c);



    Svector<double> d(5);
    d.set(2, 2.59);
    show_vec(d);

    Svector<double> copy = d;
    show_vec(copy);


    std::cout << "Input number of elements in vec than input chars" << std::endl;
    int n;
    std::cin >> n;
    Svector<char> test_ptr(n);
    read_vec_ptr(test_ptr);
    show_vec_str(test_ptr);

    std::cout << "Input number of elements in vec than input ints" << std::endl;
    std::cin >> n;
    Svector<int> test_brackets(n);
    read_vec_brackets(test_brackets);
    show_vec_brackets(test_brackets);

    const Svector<int> cnst_vec = test_brackets;

    show_vec_brackets(cnst_vec);
    show_vec_ptr(cnst_vec);
    show_vec_str(cnst_vec);
    show_vec(cnst_vec);


}
