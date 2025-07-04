#include "Stack_vector.h"
#include <stdexcept>

void Stack::push(int value) 
{
    data.push_back(value);                          //vector handles allocation
}

void Stack::pop()                                   //remove top element
{
    if (empty()) 
    {
        throw std::out_of_range("Stack empty");     //in case of error
    }
    data.pop_back();                                
}

int Stack::top() const                              //access top element
{
    if (empty()) 
    {
        throw std::out_of_range("Stack empty");
    }
    return data.back();
}

bool Stack::empty() const                           //check if stack is empty
{
    return data.empty();
}

size_t Stack::size() const                          //gives current stack size
{
    return data.size();
}

double Stack::average() const                       //calculates average of stack
{
    if (empty()) return 0.0;
    double sum = 0.0;
    for (int num : data)                            //range based for loop
    {
        sum += num;
    }
    return sum / data.size();                       //floating point division
}