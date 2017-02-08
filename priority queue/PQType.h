#include "heap.cpp"

template<class ItemType>
class PQType
{
public:
  PQType(int);          // parameterized class constructor
  PQType( const PQType<ItemType>& anotherPQueue);    // copy constuctor

  ~PQType();            // class destructor

  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.
  
  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)
  
  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)
  
  void Enqueue(ItemType newItem);
  // Function: Adds newItem to the rear of the queue.
  // Pre:  Queue is not full.
  // Post: newItem is in the queue.
  
  void Dequeue(ItemType& item);
  // Function: Removes element with highest priority from the queue
  // and returns it in item.
  // Pre:  Queue is not empty.
  // Post: Highest priority element has been removed from the queue.
  //       item is a copy of the removed element.

  void operator=( const PQType<ItemType>& anotherPQueue );
  // overloaded assignment

private:
  int numItems;
  HeapType<ItemType> items;
  int maxItems;
};

#include "PQType.cpp"
