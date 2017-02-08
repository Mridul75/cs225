//*****************************************************************
// Marissa Carson
// CS2 Terry Hostetler Spring 2013 Semester
// Homework 3: Implementation file for double-ended queue ADT
// March 18th 2013
//*****************************************************************

#include <cstddef>		 	// For NULL
using namespace std;

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
DeQueType<ItemType>::DeQueType()	// Class constructor.
// Post:  dequeFront and dequeRear are set to NULL.
{
    dequeFront = NULL;
    dequeRear = NULL;
}

template <class ItemType>
void DeQueType<ItemType>::MakeEmpty()
// Post: Queue is empty; all elements have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (dequeFront != NULL)
    {
        tempPtr = dequeFront;
        dequeFront = dequeFront->next;
        delete tempPtr;
    }
    dequeRear = NULL;
}

template <class ItemType>		// Class destructor.
DeQueType<ItemType>::~DeQueType()
{
    MakeEmpty();
}

template <class ItemType>
bool DeQueType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType on the free store;
// false otherwise.
{
    NodeType<ItemType>* ptr;
    ptr = new NodeType<ItemType>;
    if (ptr == NULL)
        return true;
    else
    {
        delete ptr;
        return false;
    }
}

template <class ItemType>
bool DeQueType<ItemType>::IsEmpty() const
// Returns true if there are no elements on the queue; false otherwise.
{
    return (dequeFront == NULL);
}

template<class ItemType>
void DeQueType<ItemType>::EnqFront(ItemType newItem)
// Function: Adds newItem to the front of the queue.
// Pre:  Queue is not full.
// Post: newItem is at the front of the queue.
{
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode->info = newItem;

	if (dequeFront == NULL)      // If the list is empty,
	{                            // then the new item will be the only item in the list, 
		newNode->next = NULL;    // so the new node should not point to any next item,
		dequeRear = newNode;     // and it should be the last item in the list.
	}
	else
		newNode->next = dequeFront;  // Otherwise, have the new node point 
	                                 // to the current front item as next.

	dequeFront = newNode; // New item becomes the new front of the list. 
}

template <class ItemType>
void DeQueType<ItemType>::EnqRear(ItemType newItem)
// Adds newItem to the rear of the queue.
// Pre:  Queue has been initialized and is not full.
// Post: newItem is at rear of queue.
{
    NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode->info = newItem;
	newNode->next = NULL;

    if (dequeRear == NULL)
        dequeFront = newNode;
    else
        dequeRear->next = newNode;
    dequeRear = newNode;
}

template <class ItemType>
void DeQueType<ItemType>::DeqFront(ItemType& item)
// Removes front item from the queue and returns it in item.
// Pre:  Queue has been initialized and is not empty.
// Post: Front element has been removed from queue.
//       item is a copy of removed element.
{
    NodeType<ItemType>* tempPtr;

    tempPtr = dequeFront;
    item = dequeFront->info;
    dequeFront = dequeFront->next;
    if (dequeFront == NULL)
        dequeRear = NULL;
    delete tempPtr;
}

template <class ItemType>
void DeQueType<ItemType>::DeqRear(ItemType& item)
// Function: Removes rear item from the queue and returns it in item.
// Pre:  Queue is not empty.
// Post: Rear element has been removed from the queue.
//       item is a copy of the removed element.
{
	NodeType<ItemType>* tempPtr = dequeFront;
	
	if (dequeFront == dequeRear)      // If there is only one item in the list,
	{
		dequeFront = NULL;            // the list will become empty.
		tempPtr = NULL;
	}
	else
	{             
		while (tempPtr->next->next != NULL)
			tempPtr = tempPtr->next;         // Find 2nd to last item,
		tempPtr->next = NULL;                // set its next to null.
	}

	item = dequeRear->info;         // Record the last item's information.
	delete dequeRear;               // Then delete the last item.
	dequeRear = tempPtr;            // Make the second-to-last item the last item.
}

template <class ItemType>
void DeQueType<ItemType>::Print( std::ostream& out )
// Function: Prints items in the deque from front to rear.  
// Deque is printed on a single line of output with one space between each item.
// Pre:  Deque has been initialized.
// Post: Deque is unchanged.
{
	NodeType<ItemType>* tempPtr;      // Create a temporary reference item
	tempPtr = dequeFront;             // and initialize it as equal to the front item.

	while (tempPtr != NULL)
	{
		out << tempPtr->info << ' ' ;    // Outputs the current item
		tempPtr = tempPtr->next;         // and then moves forward in the list.
	}

	out << endl;
}

template <class ItemType>
int DeQueType<ItemType>::Length()
// Function: Returns the number of items in the deque.  
// Pre:  Deque has been initialized.
// Post: Function value = number of items in the deque.
//       Deque is unchanged.
{
	NodeType<ItemType>* tempPtr;      // Create a temporary reference item
	tempPtr = dequeFront;             // and initialize it as equal to the front item.
	int length = 0;
	while (tempPtr != NULL)
	{
		length++;
		tempPtr = tempPtr->next;
	}

	return length;
}

