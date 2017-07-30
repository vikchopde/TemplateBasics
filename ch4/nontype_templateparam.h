#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <deque>
#include <array>
#include <algorithm>
#include <iterator>

//Non Type function Template arguements

template <typename T, int val>
T addVal(const T& ele)
{
    return val + ele;
};

int main()
{
    std::vector<int> vec {9, 19, 29 ,39, 49};
    std::vector<int> vec2;

    std::transform(std::begin(vec), std::end(vec),
                   std::back_inserter(vec2),
                   addVal<int, 1>);

    for(const auto& ele : vec2)
    {
        std::cout << ele << ' ';
    }
    return 0;
}