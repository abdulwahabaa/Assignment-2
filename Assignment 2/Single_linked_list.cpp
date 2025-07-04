#include "Single_linked_list.h"
#include <stdexcept>
#include <list>
#include <iostream>

using namespace std;

template <typename Item_type>																		//initializes empty list
Single_linked_list<Item_type>::Single_linked_list() : head(nullptr), tail(nullptr), num_items(0)
{}
template <typename Item_type>																		//cleans up all nodes
Single_linked_list<Item_type>::~Single_linked_list()
{
	while (!empty())																				//continue until empty
	{
		pop_front();
	}
}

template <typename Item_type>
void Single_linked_list<Item_type>::push_front(const Item_type& item)
{
	Node* new_node = new Node(item);																//makes a new node
	if (empty())
	{
		head = tail = new_node;
	}
	else {
		new_node->next = head;
		head = new_node;																			//updates head(beginning)
	}
	num_items++;
}

template <typename Item_type>
void Single_linked_list<Item_type>::push_back(const Item_type& item)
{
	Node* new_node = new Node(item);
	if (empty())
	{
		head = tail = new_node;
	}
	else 
	{
		tail->next = new_node;
		tail = new_node;																			//updates tail(end)
	}
	num_items++;

}

template <typename Item_type>
void Single_linked_list<Item_type>::pop_front()
{
	if (empty()) return;
	Node* old_head = head;																			//saves current head
	head = head->next;																				//advances head
	delete old_head;																				//frees the memory
	num_items--;
	if (empty()) tail = nullptr;
}

template <typename Item_type>																		//removes from end
void Single_linked_list<Item_type>::pop_back()
{
	if (empty()) return;
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
	}
	else 
	{
		Node* current = head;
		while (current->next != tail)
		{
			current = current->next;
		}
		delete tail;																			//remove last node
		tail = current;
		tail->next = nullptr;																	//terminates list

	}
	num_items--;
}

template <typename Item_type>
Item_type& Single_linked_list<Item_type>::front()
{
	if (empty()) throw std::out_of_range("List empty");											//checks if list empty
	return head->data;																			//return refrence to front data
}

template <typename Item_type>
Item_type& Single_linked_list<Item_type>::back()
{
	if (empty()) throw std::out_of_range("List empty");
	return tail->data;																			//return refrence to back data
}

template <typename Item_type>
bool Single_linked_list<Item_type>::empty() const
{
	return num_items == 0;
}

template <typename Item_type>
void Single_linked_list<Item_type>::insert(size_t index, const Item_type& item)
{
	if (index == 0)
	{
		push_front(item);																			//special case insert at head
	}
	else if (index >= num_items)
	{
		push_back(item);																			//special case insert past tail												
	}
	else
	{
		Node* new_node = new Node(item);
		Node* current = head;
		for (size_t i = 0; i < index - 1; ++i)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
		num_items++;
	}
}

template <typename Item_type>
bool Single_linked_list<Item_type>::remove(size_t index)
{
	if (index >= num_items) return false;
	if (index == 0)
	{
		pop_front();																			//remove head
	}
	else if (index == num_items - 1)
	{
		pop_back();																				//remove tail
	}
	else
	{
		Node* current = head;
		for (size_t i = 0; i < index - 1; ++i)
		{
			current = current->next;
		}
		Node* temp = current->next;
		current->next = temp->next;
		delete temp;
		num_items--;
	}
	return true;

}

template <typename Item_type>																		//finds first item
size_t Single_linked_list<Item_type>::find(const Item_type& item)
{
	Node* current = head;
	size_t index = 0;
	while(current != nullptr)
	{
		if (current->data == item)
		{
			return index;																			//returns if found
		}
		current = current->next;
		index++;
	}
	return num_items;																				//returns if not found
}

template class Single_linked_list<int>;