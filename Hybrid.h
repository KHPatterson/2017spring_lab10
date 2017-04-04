#if !defined (HYBRID_H)
#define HYBRID_H

#include "DoubleNode.h"
#include "QueueLinked.h"
using CSC2110::QueueLinked;
#include "SortedListDoublyLinked.h"
#include <iostream>
#include "text.h"
using CSC2110::String;

using namespace std;

template < class T >
class Hybrid
{

   private:
      QueueLinked< DoubleNode<T> >* q;
      SortedListDoublyLinked<T>* sldl;

   public:
      Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));
      ~Hybrid();

      bool isEmpty();
      void enqueue(T* item);
      T* dequeue();
      ListDoublyLinkedIterator<T>* iterator();

};

template < class T >
Hybrid<T>::Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item))
{
   //q = new QueueLinked<T>();
   q = new QueueLinked< DoubleNode<T> >();
   sldl = new SortedListDoublyLinked<T>(comp_items, comp_keys);
}

template < class T >
Hybrid<T>::~Hybrid()
{
   delete q;
   delete sldl;
}

//DO THIS
//complete the implementation for the Hybrid ADT in two different ways
//as outlined in the Lab 10 description
//simply comment the first implementation out when working on the second implementation
//use the getKey method to dequeue/remove

template < class T >
bool Hybrid<T>::isEmpty()
{
   return q->isEmpty();
}

template < class T >
ListDoublyLinkedIterator<T>* Hybrid<T>::iterator()
{
   ListDoublyLinkedIterator<T>* iter = sldl->iterator();
   return iter;
}


// FIRST IMPLEMENTATION
/*
template < class T >
void Hybrid<T>::enqueue(T* item)
{
   q->enqueue(item);
   sldl->add(item);
}

template < class T >
T* Hybrid<T>::dequeue()
{
   T* item = q->dequeue();
 

      cout << "yuup... it's dequeued" << endl;

   String* str = item->getKey();
   sldl->remove(str);

      cout << "\twe called the remover" << endl;

   return item;
}
*/


// SECOND IMPLEMENTATION

template < class T >
void Hybrid<T>::enqueue(T* item)
{
   DoubleNode<T>* dbn = sldl->addDN(item);
   q->enqueue(dbn);
}


template < class T >
T* Hybrid<T>::dequeue()
{
   DoubleNode<T>* dbn = q->dequeue();
   T* item = sldl->remove(dbn);

   return item;
}

#endif
