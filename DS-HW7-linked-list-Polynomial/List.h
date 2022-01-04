#pragma once
#ifndef LIST_NODE_H
#define LIST_NODE_H

#include "ListIterator.h"
#include <iostream>
#include <ostream>
using namespace std;

template<class T> class List;
template<class T> class ListIterator; // new added from previos LinkedLIst program 

//*****  ListNode Template Class
template <class T>
class ListNode {
	friend class List <T>;
	friend class ListIterator <T>; // new added for iterator
	template <class T> friend ostream &operator<<(ostream &, List<T>&);
public:
	ListNode(T element = 0) { data = element; link = 0; };
private:
	T data;
	ListNode *link;
};

// *********List Template Class *********************
template <class T>
class List {
	template <class T> friend ostream &operator<<(ostream &, List<T>&);
	friend class ListIterator<T>; // New Added for Iterator
public:
	List() { first = 0; }; // constructor initializing first to 0
	// list manipulation operations
	void Create2(T, T);
	void Insert(ListNode<T>*, T);
	ListNode<T>* FirstNode() { return first; };
	void PrintList();
private:
	ListNode <T> *first;
	ListNode <T> *current;// point to the current node for print only
};


// ***************************************************************************
template<class T>
void List<T>::Create2(T x1, T x2)
{
	first = new ListNode<T>(x1); // create & initialize first node
	// create & initialize 2nd node & place its address in first->link   
	first->link = new ListNode<T>(x2);
};

// ****************************************************************************
template< class T>
void List<T>::Insert(ListNode<T> *x, T value)
{
	ListNode<T> *t = new ListNode<T>(value); // create and initialize new node
	if (!first) // insert into empty list
	{
		first = t;
		exit(1); // exit List::Insert50
	}
	// insert after x
	t->link = x->link;
	x->link = t;
};
//***************************************
template<class T>
void List<T>::PrintList()
{
	current = first;
	cout << "t--> ";
	while (current != NULL) {
		cout << current->data << " --> ";
		current = current->link;
	}
	cout << "NULL" << endl;
};

//****************************************
// Not Yet Finished
//****************************************
template<class T>
ostream & operator<<(ostream &out, List<T>& list) {
	list.current = list.first;
	out << endl
		<< "print the linked list by operator overloading << ll\n" << endl << "ll.list-->";
	while (list.current != NULL)
	{
		out << list.current->data << "-->";
		list.current = list.current->link;
	}
	out << "NULL(end)";
	return out;
};


#endif