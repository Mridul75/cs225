template<class ItemType>
PQType<ItemType>::PQType(int max)
{
    maxItems = max;
    items.elements = new ItemType[maxItems];
    numItems = 0;
}

template<class ItemType>	     // copy constructor
PQType<ItemType>::PQType( const PQType<ItemType>& anotherPQueue )
{	
	*this = anotherPQueue;
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
    numItems = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
  delete [] items.elements;
}

template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
// Post: element with highest priority has been removed
//       from the queue; a copy is returned in item.
{
    item = items.elements[0];
    items.elements[0] = items.elements[numItems-1];
    numItems--;
    items.ReheapDown(0, numItems-1);
}

template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
// Post: newItem is in the queue.
{
    numItems++;
    items.elements[numItems-1] = newItem;
    items.ReheapUp(0, numItems-1);
}

template<class ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Function value = true if the queue is full;
//       false, otherwise
{
    return numItems == maxItems;
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Function value = true if the queue is empty;
//       false, otherwise
{
    return numItems == 0;
}

template<class ItemType>	     // overloaded assignment
void PQType<ItemType>::operator=( const PQType<ItemType>& anotherPQueue )
{	
    maxItems = anotherPQueue.maxItems;
    items.elements = new ItemType[maxItems];
    numItems = anotherPQueue.numItems;

	// copy data from anotherQueue
	for (int i = 0; i < numItems; i++)
		items.elements[i] = anotherPQueue.items.elements[i];
}
