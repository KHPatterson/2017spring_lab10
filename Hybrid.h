#if !defined (HYBRID_H)
#define HYBRID_H

#include "QueueLinked.h"
using CSC2110::QueueLinked;
#include "SortedListDoublyLinked.h"

template < class T >
class Hybrid
{

   private:
      QueueLinked<T>* q;
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
   q = new QueueLinked<T>();
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

// DEQUEUE FUNCTION - first implementation.
//    FIRST - dequeue to get the Item being removed.  use item->getkey() to get a string*
//    SECOND - pass string to finder function.  This returns a doublenode.
//    THIRD - We call the remove function.  Sorted_list->remove(DBN*)
//    PROFIT?...

// DEQUEUE FUNCTION - second implementation
//    FIRST - dequeue the actual queue.  This returns the doublenode (called KILL) with all necessary pointers.
//    SECOND - set temp pointers to bypass KILL. see pic from pseudo.
//    THIRD - NULL temp pointers and kill the KILL item with deconstructor.




#endif
