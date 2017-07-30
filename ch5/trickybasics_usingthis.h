#include <iostream>
#include <cstring>
#include <vector>
#include <array>

//Using this-> pr base<T>::member variable in derived class

template <typename T>
class base
{
public:
    base()
            :   id(T())
    {}

protected:
    T id;
};

template <typename T>
class derived : public base<T>
{
public:

    //using base<T>::id; // Or

    derived()
    {
        // error: ‘id’ was not declared in this scope
        // std::cout << id << std::endl;

        //Solution :
        std::cout << base<T>::id << std::endl;
    }
};


int main()
{
    derived<int> obj;
    return 0;
}