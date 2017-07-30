#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>

////Member Template


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

    T& operator[] (int index)
    {
        return ele_[index];
    }

    //// Member function template thats takes Stack of another type and assign.
    template <typename T2>
    Stack<T>& operator = (const Stack<T2>& rhs);

private:
    std::vector<T> ele_;
};


// Note : Take  a not on the declaration this is important
template <typename T>
template <typename T2>
Stack<T>&  Stack<T>::operator= ( const Stack<T2> &rhs )
{
    if((void*)(this) != (void*)(&rhs))
    {
        auto tmp = rhs;

        for(int i = 0;i < tmp.size() ; ++i)
        {
            this->ele_[i] = tmp[i];
        }
    }
    return *this;
}

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

        intStack.push(1);
        intStack.push(12);

        Stack<double> doubleStack;
        doubleStack.push(3.2);
        doubleStack.push(4.5);

        intStack = doubleStack;
        std::cout << intStack[0] << std::endl;
        std::cout << intStack[1] << std::endl;

    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}