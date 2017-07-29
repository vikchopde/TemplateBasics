#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <functional>
#include <complex>


//Defining the template

template <typename T>
inline T MAX(const T& a, const T& b)
{
    return a > b ? a : b;
}

int main(int argc, char *argv[])
{
    //Using the template

    auto i  = 10;
    std::cout << "MAX(i, 20) = " << MAX(10, 20) << std::endl;

    auto di = 2.0, dj = -3.5;
    std::cout << "MAX(di, dj) = " << MAX(di, dj) << std::endl;

    std::string str1 = "22", str2 = "4444";
    std::cout << "MAX(str1, str2) = " << MAX(str1, str2) << std::endl;

    //An attempt to instantiate a teArgument Deductionmplate for a type that doesn’t support all the operations used within it will result in a compile-time error
    //error: no match for ‘operator>’ in ‘a > b’
    std::complex<float> c1, c2;
    MAX(c1, c2);

    return 0;
}

// 1 : During compile time template code is generated for each type.
// 2 : An attempt to instantiate template for a type which does not support all template operations will cause a compile time error.
//   : Templates are compiled twice :
//     1 : compiled first to check for syntax errors in templates.
//     2 : compiled second time to check for all operations are supported or not.
//     3 : Thats the reason compiler need to see the definition of template also during the compilation phase as opposed to only declartion.
//     4 : Hence, Template declaration and defintion should be in same file / transation unit.

