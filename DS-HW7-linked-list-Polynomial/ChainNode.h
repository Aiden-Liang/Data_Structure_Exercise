#ifndef CHAIN_NODE_H
#define CHAIN_NODE_H

#include "ChainIterator.h"
#include <iostream>
#include <ostream>
using namespace std;

template<class T> class Chain;
template<class T> class ChainIterator; // new added from previos LinkedChain program 

//*****  ChainNode Template Class 
template <class T>
class ChainNode {
//	friend ostream &operator<<(ostream &, Polynomial &);
	friend class Chain <T>;
	friend class ChainIterator <T>; // new added for iterator
	template <class T> friend ostream &operator<<(ostream &,  Chain<T>&);
	
public:
	ChainNode(T element=0) {data=element;link=0;};
private:
	T data;
	ChainNode *link;
};

// *********Chain Template Class *********************
template<class T>  
class Chain {
	template <class T> friend ostream &operator<<(ostream &, Chain<T>&);
	friend class ChainIterator<T>; // New Added for Iterator
public:
	Chain() { first=last=0; }; // constructor initializing first to 0
	// Chain(const Chain<T> &l); // copy constructor
	// Chain manipulation operations
	void Create2(T, T);
    void Insert(ChainNode<T>*,T);
	void Delete(ChainNode<T>*, ChainNode<T> *);
	void InsertBack(const T& e);
	ChainNode<T>* FirstNode() {return first; };
	void PrintChain();
private:
	ChainNode <T> *first, *last;
	ChainNode <T> *current;
};


// ***************************************************************************
template<class T>
void Chain<T>::Create2(T x1,T x2)
	{
     first = new ChainNode<T>(x1); // create & initialize first node
	 // create & initialize 2nd node & place its address in first->link   
	 last = first->link = new ChainNode<T>(x2);
	};

// ****************************************************************************
template< class T>
void Chain<T>::Insert(ChainNode<T> *x, T value)
{
	ChainNode<T> *t = new ChainNode<T>(value); // create and initialize new node
	if(!first) // insert into empty Chain
	{
		first = t;
		exit(1); // exit Chain::Insert50
	}
	// insert after x
		t->link = x->link;
		x->link = t;
};
//************************************************************************************
// copy constructor
//***********************************************************************************
//template<class T>
//Chain<T>::Chain(const Chain<T> & list) {
//	first = last = current = 0;
//	cout << "now in the copy constructor linked list\n";
//	ChainNode * current = list.first;
//	while (current) {
//		this->InsertBack(current->data);
//		current = current->next;
//	}
//};

//*********************************************************************************
template <class T>
void Chain<T>::Delete(ChainNode<T>* x, ChainNode<T> *y)
{
	if (x == first) first = first->link;
	else y->link = x->link;
	delete x;
};
//*********************************************************************************
template <class T>
void Chain<T>::InsertBack(const T& e)
{
	if (first) { // non null chain
		last->link = new ChainNode<T>(e);
		last = last->link;
	}
	else first = last = new ChainNode<T>(e);
};
//***************************************
template<class T>
void Chain<T>::PrintChain()
{
	current=first;
	cout <<"t--> ";
	while(current!=NULL){
		cout << current->data <<" --> ";
		current=current->link;
	}
	cout <<"NULL"<< endl;
};

//****************************************
//  Finished in 2020
//****************************************
template<class T>
ostream & operator<<(ostream &out, Chain<T>& Chain){
    Chain.current=Chain.first;
	out << endl
		<< "print the linked Chain by operator overloading << ll\n" << endl<<"ll.Chain-->";
	while(Chain.current!=NULL) 
	{
		out << Chain.current->data<< "-->";
		Chain.current=Chain.current->link;
	}
	out << "NULL(end)";
	return out;
};
#endif