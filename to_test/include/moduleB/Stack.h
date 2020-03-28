#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template<typename T, template<typename> class Cont = std::vector>
class Stack {
public:
    Stack() = default;
    template<typename U> Stack(std::initializer_list<U>);
    void push(T);
    void pop();
    T& top();
    size_t size() { return elems.size(); }
    bool empty() { return elems.empty(); }
private:
    Cont<T> elems;
};

template<typename T, template<typename> class Cont>
template<typename U>
Stack<T, Cont>::Stack(std::initializer_list<U> il)
{
    std::copy(il.begin(), il.end(),
        std::back_inserter(elems));
}

template<typename T, template<typename> class Cont>
void Stack<T, Cont>::push(T t)
{
    elems.push_back(t);
}

template<typename T, template<typename> class Cont>
void Stack<T, Cont>::pop()
{
    if (elems.empty()) throw std::out_of_range("pop on emtpy stack");
    elems.pop_back();
}

template<typename T, template<typename> class Cont>
T& Stack<T, Cont>::top()
{
    if (elems.empty()) throw std::out_of_range("top on emtpy stack");
    return elems.back();
}

#endif // !STACK_H
