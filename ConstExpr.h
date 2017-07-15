#ifndef TEMPLATES_BASICS_CONSTEXPR_H
#define TEMPLATES_BASICS_CONSTEXPR_H

#include <vector>
#include <array>

class ConstExprSample
{
public:

    //Blog : http://blog.quasardb.net/demystifying-constexpr/

    //ConstExpr Function . Everything required for function is available at compile time.
    constexpr int sum(int a, int b)
    {
        return a + b;
    }

    //error: call to non-constexpr function
    //constexpr int sum(std::vector<int>& a, std::vector<int>& b)
    //{
    //    return a.size() + b.size();
    //}


    //array.size() is a constexpr function
    template <size_t N1, size_t N2>
    constexpr int sum(std::array<int, N1>& a, std::array<int, N2>& b)
    {
        return a.size() + b.size();
    }

};



#endif //TEMPLATES_BASICS_CONSTEXPR_H
