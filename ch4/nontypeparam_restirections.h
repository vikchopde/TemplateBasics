#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <deque>
#include <array>
#include <algorithm>
#include <iterator>

//Function Template non type parameter restrictions

// Non type template parameter can be only integeral values or pointer to objects with external linkage

/*
//error: ‘double’ is not a valid type for a template constant parameter
template <typename T, double val>
T addVal(const T& ele)
{
    return val + ele;
};


//error: ‘hello’ is not a valid template argument because ‘hello’ is a variable, not the address of a variable
const char* hello = "hello";

template <const char*>
class sample
{

};*/


//However this will work , as helloarr is object with external linkage
extern const char helloarr[] = "hello";

template <const char*>
class sample
{

};

int main()
{
    sample<helloarr> obj;
    return 0;
}