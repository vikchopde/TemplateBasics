#include <iostream>

//// Overloading of function templates

int MAX(const int& a, const int& b)
{
    std::cout << "MAX(const int& a, const int& b)" << std::endl;
    return a > b ? a : b;
}

template <typename T>
T MAX(const T& a, const T& b)
{
    std::cout << "MAX(const T& a, const T& b)" << std::endl;
    return a > b ? a : b;
}

template <typename T>
T MAX(const T& a, const T& b, const T& c)
{
    std::cout << "MAX(const T& a, const T& b, const T& c)" << std::endl;
    return MAX(MAX(a, b), c);
}

int main()
{

    MAX(10, 200 ,30); // MAX(const T& a, const T& b, const T& c)
    MAX(10.0, 200.0); // MAX(const T& a, const T& b)
    MAX('a', 'b');    // MAX(const T& a, const T& b)
    MAX(10, 200);     // MAX(const int& a, const int& b)
    MAX<>(10, 200);   // MAX(const T& a, const T& b)
    MAX<double>(10, 200); // MAX(const T& a, const T& b)
    MAX('a', 20);     // "MAX(const int& a, const int& b)
    return 0;
}