#include <iostream>

template <class ItemType>
struct NodeType;

template <class ItemType>
class DeQueType
{
public:
    DeQueType();
    // Class constructor.
    // Because there is a default constructor, the precondition that the
    // queue has been initialized is omitted.

    ~DeQueType();
    // Class destructor.

    void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: Queue is empty.

    bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)

    bool IsFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)

    void EnqFront(ItemType newItem);
    // Function: Adds newItem to the front of the queue.
    // Pre:  Queue is not full.
    // Post: newItem is at the front of the queue.

    void EnqRear(ItemType newItem);
    // Function: Adds newItem to the rear of the queue.
    // Pre:  Queue is not full.
    // Post: newItem is at the rear of the queue.

    void DeqFront(ItemType& item);
    // Function: Removes front item from the queue and returns it in item.
    // Pre:  Queue is not empty.
    // Post: Front element has been removed from the queue.
    //       item is a copy of the removed element.

    void DeqRear(ItemType& item);
    // Function: Removes rear item from the queue and returns it in item.
    // Pre:  Queue is not empty.
    // Post: Rear element has been removed from the queue.
    //       item is a copy of the removed element.

	void Print( std::ostream& out );
	// Function: Prints items in the deque from front to rear.  
	// Deque is printed on a single line of output with one space between each item.
	// Pre:  Deque has been initialized.
	// Post: Deque is unchanged.

	int Length();
	// Function: Returns the number of items in the deque.  
	// Pre:  Deque has been initialized.
	// Post: Function value = number of items in the deque.
	//       Deque is unchanged.

private:
    NodeType<ItemType>* dequeFront;
    NodeType<ItemType>* dequeRear;
};

#include "hw3 DeQue.cpp"