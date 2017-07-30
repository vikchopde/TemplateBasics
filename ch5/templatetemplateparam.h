#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <deque>

////Template Class Specialization

template <typename T , template <typename ELEM,
        typename ALLOC = std::allocator<ELEM>>
        class CONT = std::deque>
class Stack
{
public:
    Stack()  = default;
    ~Stack() = default;

    void push(const T& val);
    void pop();
    T top() const;
    bool isEmpty() const { return ele_.empty(); }
    auto size() -> typename std::vector<T>::size_type
    {
        ele_.size();
    }

private:
    CONT<T> ele_;
};

template <typename T, template <typename, typename > class CONT>
void Stack<T, CONT>::push(const T &val)
{
    ele_.push_back(val);
}

template <typename T, template <typename, typename > class CONT>
void Stack<T, CONT>::pop()
{
    if(isEmpty())
        throw  std::runtime_error("stack is empty.");
    ele_.pop_back();
}

template <typename T, template <typename, typename > class CONT>
T Stack<T, CONT>::top() const
{
    return ele_.back();
}

int main()
{
    try
    {
        Stack<int> intStack;

        intStack.push(10);
        std::cout << intStack.top() << std::endl;

    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}