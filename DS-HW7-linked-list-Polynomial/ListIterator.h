#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "ListNode.h"
enum Boolean {FALSE, TRUE};
template<class T> class List;
template<class T> class ListNode;
template<class T> class ListIterator; // new added from previos LinkedLIst program 

template<class T>
class ListIterator {
  public:
	  ListIterator(const List <T> &l):list(l),current(l.first){};
	  Boolean NotNull();
	  Boolean NextNotNull();
	  T *First();
	  T *Next();
  private:
	  const List <T> & list;     // refers to an existing list
	  ListNode <T> *current; // points to a node in list
};

template<class T> // check that the current element in List is non-null
Boolean ListIterator<T>::NotNull(){
	if(current) return TRUE; 
	else return FALSE; 
};
template<class T> // check that the next element in List is non-null
Boolean ListIterator<T>::NextNotNull() {
	if(current&&current->link) return TRUE;  else return FALSE;
};
template<class T> // return a pointer to the first element of List
T *ListIterator<T>::First() {
	if(list.first) return(&list.first->data); 
	else return 0;
};

template<class T> // return a pointer to the next element of List
T * ListIterator<T>::Next() {
	if(current) {
		current = current->link;
		if(current) return (&current->data);
		else return 0;
	}
	return 0;
 };


#endif