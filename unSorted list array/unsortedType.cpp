template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
  length = 0;
}

template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
  length = 0;
}

template <class ItemType>
bool UnsortedType<ItemType>::IsFull() const 
{
  return (length == MAX_ITEMS);
}

template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const 
{
  return length;
}

template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found) 
// Pre: Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
// list and a copy of that element has been stored in item; 
// otherwise, item is unchanged. 
{
  bool moreToSearch;
  int location = 0;
  found = false;
  
  moreToSearch = (location < length);
  
  while (moreToSearch && !found) 
  {
    if (item == info[location]) 
	{
		found = true;
	    item = info[location];
	}
	else 
	{
		location++;
	    moreToSearch = (location < length);
	}
  }
}

template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item) 
  // Post: item is in the list. 
{
  info[length] = item;
  length++; 
}

template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item) 
  // Pre: item's key has been initialized. 
  // An element in the list has a key that matches item's. 
  // Post: No element in the list has a key that matches item's. 
{
  int location = 0;
  
  while (item != info[location])
    location++;

  info[location] = info[length - 1];
  length--;
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList()  
  // Post: currentPos has been initialized. 
{
  currentPos = 0;
}

template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item) 
  // Returns the next element in list.
  // Pre:  Current position is defined.
  // Post: item is a copy of the element at the current position.
  //       After returning the current item, current position is updated 
  //       to the next position.
{
  item = info[currentPos];
  currentPos++;
}

template <class ItemType>
bool UnsortedType<ItemType>::AtEnd()
// Returns true if currentPos is at end of list.
// Pre:  Current position is defined.
{
  return currentPos == length;  
}