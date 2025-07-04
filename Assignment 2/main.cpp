#include <iostream>
#include "Single_linked_list.h"
#include "Stack_vector.h"

using namespace std;

void static test_linked_list()                                                  //tests function for linked list
{
    cout << "Testing Single Linked List:\n";
    Single_linked_list<int> list;

    std::cout << "Is list empty? " << (list.empty() ? "Yes" : "No") << "\n";

    list.push_back(10);
    list.push_front(5);
    list.push_back(20);
    list.insert(1, 15);

    cout << "Front: " << list.front() << ", Back: " << list.back() << "\n";     //verifies after inserts
    cout << "Size: " << list.size() << "\n";

    cout << "Finding 15: Position " << list.find(15) << "\n";

    list.remove(1);
    list.pop_front();
    list.pop_back();
    cout << "After operations, size:" << list.size() << "\n\n";
}

void static test_stack()                                                        //tests function for stack
{
    cout << "Testing Stack:\n";
    Stack s;

    cout << "Is Stack empty? " << (s.empty() ? "Yes" : "No") << "\n";

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << "\n";
    cout << "Size: " << s.size() << "\n";
    cout << "Average: " << s.average() << "\n";
    cout << "Is empty?" << (s.empty() ? "Yes" : "No") << "\n";

    s.pop();
    cout << "\nAfter pop():\n";
    cout << "New top:  " << s.top() << "\n";
    cout << "Size: " << s.size() << "\n";
}

int main() 
{                                                                               //runs all the tests
    test_linked_list();
    test_stack();
    return 0;
}