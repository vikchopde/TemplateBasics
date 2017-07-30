#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <deque>

////Partial Specialization

template <typename T1, typename T2>
class MyClass
{
public:
    MyClass()
    {
        std::cout << "Base Template"<< std::endl;
    }
};

template <typename T>
class MyClass<T, T>
{
public:
    MyClass()
    {
        std::cout << "partial specialization with same type"<< std::endl;
    }

};

template <typename T>
class MyClass<T, int>
{
public:
    MyClass()
    {
        std::cout << "partial specialization with one fixed type int"<< std::endl;
    }

};

template <typename T1, typename T2>
class MyClass<T1*, T2*>
{
public:
    MyClass()
    {
        std::cout << "partial specialization with both template parameters as pointer type"<< std::endl;
    }
};

template <typename T>
class MyClass<T*, T*>
{
public:
    MyClass()
    {
        std::cout << "partial specialization with both template parameters as same pointer type"<< std::endl;
    }
};



int main()
{

    MyClass<int, float>     obj1; // Base Template
    MyClass<float, float>   obj2; // partial specialization with same type
    MyClass<float, int>     obj3; // partial specialization with one fixed type int

    MyClass<int*, float*>   obj4; // partial specialization with both template parameters as pointer type

    MyClass<int*, int*>     obj5; // ambiguous class template instantiation for ‘class MyClass<int*, int*>
    // error: candidates are: class MyClass<T, T>
    // error:                 class MyClass<T1*, T2*>
    //solution : provide specialization for template params with same pointer type

    return 0;
}