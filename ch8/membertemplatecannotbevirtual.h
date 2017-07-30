/* Single thread program to increment a variable half a billion times */
#include <iostream>
#include <cstdint>
#include <thread>
using namespace std;

template <typename T>
class sample
{
public:
    sample(T val)
            : id(val)
    {
    }

    //error: templates may not be ‘virtual’

    template <typename NOT_T>
    virtual void assign(NOT_T val)
    {
        id = val;
    };


    void print()
    {
        std::cout << id << std::endl;
    }

private:
    int id;
};


int main()
{
    sample<int> obj1 = 10;
    float f = 5.4;
    obj1.assign(f);
    obj1.print();

    return 0;
}