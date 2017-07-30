#include <iostream>
#include <cstring>
#include <vector>

//Typename Keyword usage - tricky basics


template <typename T>
void PrintCollection(const T& coll)
{
    /*
    //error: need ‘typename’ before ‘T:: const_iterator’ because ‘T’ is a dependent scope
    T::const_iterator pos;
    T::const_iterator end(coll.end());*/

    typename T::const_iterator pos;
    typename T::const_iterator end(coll.end());

    for(pos = coll.begin(); pos != end; ++pos)
    {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}

// .template construct

int main()
{
    std::vector<int> vec {10, 20, 30, 40};
    ::PrintCollection(vec);
    return 0;
}