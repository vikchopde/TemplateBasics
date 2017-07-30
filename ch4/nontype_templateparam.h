#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <deque>
#include <array>

//Non Type Template arguements
// MAXSIZE is non type template parameter of type int

template <typename T, int MAXSIZE>
class Stack
{
public:
    Stack();
    void push(const T& val);
    void pop();
    T top() const;

private:
    int numElems;
    std::array<T, MAXSIZE> elems_;
};

template <typename T, int MAXSIZE>
Stack<T,MAXSIZE>::Stack()
        : numElems(0)
{

}

template <typename T, int MAXSIZE>
void Stack<T,MAXSIZE>::pop()
{
    numElems--;
}

template <typename T, int MAXSIZE>
void Stack<T,MAXSIZE>::push(const T& val)
{
    elems_.at(numElems++) = val;
}

template <typename T, int MAXSIZE>
T Stack<T,MAXSIZE>::top() const
{
    return elems_.at(numElems);
}

int main()
{
    Stack<int,2> intStack;

    try {
        intStack.push(10);
        intStack.push(10);
        //intStack.push(20);
    }
    catch(std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}