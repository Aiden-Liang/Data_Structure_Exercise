#ifndef LIST_NODE_H
#define LIST_NODE_H

#include "ChainIterator.h"
#include <iostream>
#include <ostream>
using namespace std;

template<class T> class Chain;
template<class T> class ChainIterator; // new added from previos LinkedLIst program 

//*****  ChainNode Template Class
template <class T>
class ChainNode {
friend class Chain <T>;
friend class ChainIterator <T>; // new added for iterator
template <class T> friend ostream &operator<<(ostream &,  List<T>&);
public:
	ChainNode(T element=0) {data=element;link=0;};
private:
	T data;
	ChainNode<T> *link;
};

// *********List Template Class *********************
template <class T>
class Chain {
template <class T> friend ostream &operator<<(ostream &,  List<T>&);
friend class ListIterator<T>; // New Added for Iterator
public:
	Chain() { first=0; }; // constructor initializing first to 0
	// list manipulation operations
	void Create2(T, T);
    void Insert(ListNode<T>*,T);
	ChainNode<T>* FirstNode() {return first; };
	void PrintList();
private:
	ChainNode <T> *first;
	ChainNode <T> *current;// point to the current node for print only
};


// ***************************************************************************
template<class T>
void Chain<T>::Create2(T x1,T x2)
	{
     first = new ChainNode<T>(x1); // create & initialize first node
	 // create & initialize 2nd node & place its address in first->link   
	 first->link = new ChainNode<T>(x2);
	};

// ****************************************************************************
template< class T>
void Chain<T>::Insert(ChainNode<T> *x, T value)
{
	ChainNode<T> *t = new ChainNode<T>(value); // create and initialize new node
	if(!first) // insert into empty list
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
void Chain<T>::PrintList()
{
	current=first;
	cout <<"t--> ";
	while(current!=NULL){
		cout << current->data <<" --> ";
		current=current->link;
	}
	cout << "NULL"<< endl;
};

//****************************************
// Not Yet Finished
//****************************************
template<class T>
ostream & operator<<(ostream &out, Chain<T>& list){
    list.current=list.first;
	out << endl
		<< "print the linked list by operator overloading << ll\n" << endl<<"ll.list-->";
	while(list.current!=NULL) 
	{
		out << list.current->data<< "-->";
		list.current=list.current->link;
	}
	out << "NULL(end)";
	return out;
};


#endif