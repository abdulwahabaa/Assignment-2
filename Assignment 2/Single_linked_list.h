#pragma once
#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cstdlib>														//must be included for size_t
													
template <typename Item_type>
class Single_linked_list
{
private:																//private node structure for linked list elements
	struct Node
	{
		Item_type data;													//data storage
		Node* next;														//pointer to next node
		Node(const Item_type & item) : data(item), next(nullptr) {}		//node constructor 
	};

	Node* head;															//pointer to first node
	Node* tail;															//pointer to last node
	size_t num_items;													//item counter

public:
	Single_linked_list();												//initializes empty list
	~Single_linked_list();												//cleans up all the nodes

	void push_front(const Item_type& item);								//add to front
	void push_back(const Item_type& item);								//add to end
	void pop_front();													//removes from front
	void pop_back();													//removes from back
	Item_type& front();													//access first element
	Item_type& back();													//then access last element
	bool empty() const;
	void insert(size_t index, const Item_type& item);					//inserts 
	bool remove(size_t index);											//removes
	size_t find(const Item_type& item);
	size_t size() const { return num_items;  }							//finds current size

};

#endif