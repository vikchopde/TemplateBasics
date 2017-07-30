#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <deque>

template <typename T, typename CONT = std::vector<T>>
class Stack
{
public:
    void push(const T& val);
    void pop();
    T top() const;
    bool isEmpty() const { return elems_.empty(); }

private:
    CONT elems_;
};


template <typename T, typename CONT>
void Stack<T, CONT>::push(const T &val)
{
    elems_.push_back(val);
}


template <typename T, typename CONT>
T Stack<T, CONT>::top() const
{
    return elems_.back();
}


template <typename T, typename CONT>
void Stack<T, CONT>::pop()
{
    if(isEmpty())
        std::runtime_error("stack is empty");
    elems_.pop_back();
}


int main()
{
    Stack<int, std::vector<int>> obj1;
    obj1.push(10);
    std::cout << obj1.top() << std::endl;

    return 0;
}