#pragma once

#include <vector>

template <typename T>
class Stack
{
private:
    std::vector<T> data;
public:
    Stack();
    void push(const T& val);
    void pop();
    T top() const;
    bool empty() const;
    int size() const;
};

template <typename T>
Stack<T>::Stack() {}

template <typename T>
void Stack<T>::push(const T& val) {
    data.push_back(val);
}

template <typename T>
void Stack<T>::pop() {
    if (!empty()) {
        data.pop_back();
    }
}

template <typename T>
T Stack<T>::top() const {
    return data.back();
}

template <typename T>
bool Stack<T>::empty() const {
    return data.empty();
}

template <typename T>
int Stack<T>::size() const {
    return data.size();
}
~Stack();
};

Stack::Stack(/* args */)
{
}

Stack::~Stack()
{
}
