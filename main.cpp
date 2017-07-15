#include <iostream>
#include "ConstExpr.h"

int main()
{
    ConstExprSample obj;
    constexpr size_t a = 10;
    constexpr size_t b = 20;

    obj.sum(a,b);


    std::vector<int> aVec {10,20,30,40};
    std::vector<int> bVec {10,20,30,40};

    //obj.sum(aVec,bVec);

    std::array<int,4> aArr {10,20,30,40};
    std::array<int,4> bArr {10,20,30,40};

    obj.sum<4,4>(aArr,bArr);


    return 0;
}
