#include <iostream>

template <typename T>
inline
T MAX(const T& a, const T& b)
{
    return a > b ? a : b;
}

/*
//Soulution 3 : Return type is bound to first template type. (Wrong)
template <typename T1, typename t2>
inline
T1 MAX(const T1& a, const T2& b)
{
    return a > b ? a : b;
}*/

//Solution : c++11

template <typename T1, typename T2>
inline
auto MAX(const T1& a, const T2& b) -> decltype(a > b ? a : b)
{
    return a > b ? a : b;
}

int main()
{

    MAX(10,20);

    //error: no matching function to call
    //MAX(10, 20.0);

    //Solution2 : expilicit specification of type T
    std::cout << MAX<double>(10,20.0) << std::endl;

    //Solution1 : Explcit cast to double
    std::cout << MAX<>(static_cast<double>(10), 20.0) << std::endl;

    //Solution3 : modify function template to take two differnt types;
    std::cout << MAX(10, 20.0) << std::endl;

    return 0;
}