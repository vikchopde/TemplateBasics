#include <iostream>
#include <cstring>


//// Overloading of function templates

template <typename T>
inline
T MAX(const T& a, const T& b)
{
    std::cout << "MAX(const T& a, const T& b)" << std::endl;
    return a > b ? a : b;
}

template <typename T>
inline
T* MAX(T* const a, T* const b)
{
    std::cout << "MAX(const T* a, const T* b)" << std::endl;
    return *a > *b ? a : b;
}

inline
const char* MAX(const char* a, const char* b)
{
    std::cout << "char* MAX(const char* a, const char* b)" << std::endl;
    return strcmp(a, b) < 0 ? b: a;
}


int main()
{
    int a = 10;
    int b = 20;

    MAX(a, b);

    auto *ptrA = &a;
    auto *ptrB = &b;

    MAX(ptrA, ptrB);

    const char* charA = "11";
    const char* charB = "1122";

    MAX(charA, charB);
    return 0;
}