#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>

template <typename T>
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
    std::vector<T> ele_;
};

template <typename T>
void Stack<T>::push(const T &val)
{
    ele_.push_back(val);
}

template <typename T>
void Stack<T>::pop()
{
    if(isEmpty())
        throw  std::runtime_error("stack is empty.");
    ele_.pop_back();
}

template <typename T>
T Stack<T>::top() const
{
    return ele_.back();
}

int main()
{
    try
    {
        Stack<int> intStack;
        Stack<std::string> stringStack;

        intStack.push(10);
        std::cout << intStack.top() << std::endl;

        stringStack.push("vikram");
        stringStack.push("chopde");
        std::cout << stringStack.top() << std::endl;

        stringStack.pop();
        stringStack.pop();
        stringStack.pop();
    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}