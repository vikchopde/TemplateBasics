#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <deque>

////Template Class Specialization

//specializing class templates allows you to optimize implementations for certain types or to fix a misbehavior of certain types for an instantiation of the
//class template. However, if you specialize a class template, you must also specialize all member functions.
//Although it is possible to specialize a single member function, once you have done so, you can no longer specialize the whole class.

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

template <>
class Stack<std::string>
{
public:
    Stack()  = default;
    ~Stack() = default;

    void push(const std::string& val);
    void pop();
    std::string top() const;
    bool isEmpty() const { return ele_.empty(); }
    auto size() -> typename std::deque<std::string>::size_type
    {
        ele_.size();
    }

private:
    std::deque<std::string> ele_;
};


void Stack<std::string>::push(const std::string &val)
{
    ele_.push_back(val);
}


void Stack<std::string>::pop()
{
    if(isEmpty())
        throw  std::runtime_error("stack is empty.");
    ele_.pop_back();
}

std::string Stack<std::string>::top() const
{
    return ele_.back();
}

int main()
{
    try
    {
        Stack<std::string> stringStack;

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