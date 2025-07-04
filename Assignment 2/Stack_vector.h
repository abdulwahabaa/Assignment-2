#pragma once
#ifndef STACK_H
#define STACK_H

#include <vector>
using namespace std;

class Stack 
{
private:
    vector<int> data;       //using vector as storage

public:
    void push(int value);   //add to top
    void pop();             //remove from top
    int top() const;        
    bool empty() const;
    size_t size() const;
    double average() const; //calulate average
};

#endif