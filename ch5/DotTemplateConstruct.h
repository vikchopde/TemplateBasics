#include <iostream>
#include <cstring>
#include <vector>
#include <array>
//Tricky basics : .template construct
#include <iostream>

template <int N>
struct Collection {
    std::array<int,N> data;

    Collection()
            : data(std::array<int,N> {})
    {
    };

    void SetValue(int v) {
        data.fill(v);
    };

    template <int I>
    int GetValue(void) const {
        return data[I];
    };
};

/*
//Error : Compilation error
template <int N, int I>
void PrintElement(const Collection<N>& coll)
{
    std::cout << coll.GetValue<I>() << std::endl;
};*/

//solution : .template construct for dependent name GetValue.
template <int N, int I>
void PrintElement(const Collection<N>& coll)
{
    std::cout << coll.GetValue<I>() << std::endl;
};


/*
 GetValue is a dependent name, and so you need to explicitly tell the compiler that what follows c is a function template
 , not some member data. That is why you need to write template keyword to disambiguate this.
Without template keyword, the following

c.GetValue<I>()  //without template keyword
could be interpreted as:

//GetValue is interpreted as member data, comparing it with I, using < operator
((c.GetValue) < I) > () //attempting to make it a boolean expression
that is, the < is interpreted as less-than operator, and > is interpreted as greater-than operator. The above interpretation is of course incorrect, as it doesn't make sense, and therefore, would result in compilation error.

 */
int main()
{
    return 0;
}