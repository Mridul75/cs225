//*******************************************
// Marissa Carson
// CS2 with Terry Hostetler
// Homework #1
// 2/6/2013
//*******************************************

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

template <class ItemType>
void UnsortedType<ItemType>::Print( ostream& out )
  // Prints items in the list from beginning to end.  
  // Items are printed on a single line of output with one space between each item.  
  // Terminates the line with endl.
  // Pre: List has been initialized.
  // Post: List is unchanged.
{
	int index=0;
	for (index; index<length; index++)
		out << info[index] << ' ';
	out << endl;
}

template <class ItemType>
UnsortedType<ItemType> UnsortedType<ItemType>::Merge( UnsortedType list2 )
  // Merges two unsorted lists (list and list2) into a third unsorted list.
  // Pre: Lists have been initialized.
  //      list and list2 are different lists.
  //      Merged list does not exceed the maximum size for a list.
  // Post: Function value = list that contains all of the items from list and list2.  
  //       list and list2 are unchanged.
{
	UnsortedType<int> merged;
	int mergedLength = list2.LengthIs() + length;
	if (mergedLength >= MAX_ITEMS)
	{
		cout << "Merged list exceeds maximum length. Partial list is shown." << endl;
		mergedLength = MAX_ITEMS;
	}
	
	ResetList();
	int index = 0;
	for (index; index < length; index++)  // Adding first list
	{
		ItemType item;
		GetNextItem(item);
		merged.InsertItem(item);
	}
	                                  // index = length       
	list2.ResetList();
	for (index; index < mergedLength; index++)    // Adding second list
	{
		ItemType item;
		list2.GetNextItem(item);
		merged.InsertItem(item);
	}

	return merged;
}

template <class ItemType>
void UnsortedType<ItemType>::Split( ItemType item, UnsortedType& list1, UnsortedType& list2 )
  // Divides list into two lists (list1 and list2) according to the key of item.  
  // Pre: List has been initialized and is not empty.
  //      List, list1, and list2 are different lists.
  // Post: list1 contains all of the items of list whose keys are less than or equal to item’s key.  
  //       These will be the only items in list1.
  //       list2 contains all of the items of list whose keys are greater than item’s key.
  //       These will be the only items in list2.
  //       List is empty.
{
	list1.MakeEmpty();
	list2.MakeEmpty();
	list1.ResetList();
	list2.ResetList();
	ResetList();
	ItemType next;

	while (length > 0)
	{
		GetNextItem(next);
		if (next <= item)
			list1.InsertItem(next);
		else
			list2.InsertItem(next);
		DeleteItem(next);
	}
}