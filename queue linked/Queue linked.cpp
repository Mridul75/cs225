#include <cstddef>		 	// For NULL

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
QueType<ItemType>::QueType()	// Class constructor.
// Post:  qFront and qRear are set to NULL.
{
    qFront = NULL;
    qRear = NULL;
}

template <class ItemType>
void QueType<ItemType>::MakeEmpty()
// Post: Queue is empty; all elements have been deallocated.
{
    NodeType<ItemType>* p;

    while (qFront != NULL)
    {
        p = qFront;
        qFront = qFront->next;
        delete p;
    }
    qRear = NULL;
}

template <class ItemType>		// Class destructor.
QueType<ItemType>::~QueType()
{
    MakeEmpty();
}

template <class ItemType>
bool QueType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType on the free store;
// false otherwise.
{
    NodeType<ItemType>* p = new NodeType<ItemType>;
    if (p == NULL)
        return true;
    else
    {
        delete p;
        return false;
    }
}

template <class ItemType>
bool QueType<ItemType>::IsEmpty() const
// Returns true if there are no elements on the queue; false otherwise.
{
    return (qFront == NULL);
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
// Adds newItem to the rear of the queue.
// Pre:  Queue has been initialized and is not full.
// Post: newItem is at rear of queue.
{
    NodeType<ItemType>* p = new NodeType<ItemType>;
    p->info = newItem;
    p->next = NULL;
    if (qRear == NULL)
        qFront = p;
    else
        qRear->next = p;
    qRear = p;
}

template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
// Removes front item from the queue and returns it in item.
// Pre:  Queue has been initialized and is not empty.
// Post: Front element has been removed from queue.
//       item is a copy of removed element.
{
    NodeType<ItemType>* p = qFront;
    item = qFront->info;
    qFront = qFront->next;
    if (qFront == NULL)
        qRear = NULL;
    delete p;
}

