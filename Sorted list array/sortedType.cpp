template <class ItemType>
SortedType<ItemType>::SortedType()
{
  length = 0;
}

template <class ItemType>
bool SortedType<ItemType>::IsFull() const 
// Determines whether list is full.
// Post: Function value = (list is full)
{
  return (length == MAX_ITEMS);
}

template <class ItemType>
int SortedType<ItemType>::LengthIs() const
// Determines the number of elements in list.
// Post: Function value = number of elements in list.
{
  return length;
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
// Initializes list to empty state.
// Post:  List is empty.
{
  length = 0;
}

template <class ItemType>
void SortedType<ItemType>::binarySearch( ItemType& item, bool& found, int& loc ) 
// Searches for list element whose key matches item's key.
// Pre:  Key member of item is initialized.
// Post: If there is an element whose key matches item's key, 
//         then found == true and location is the index is where it was found; 
//         otherwise found == false and location is undefined. 
//       List is unchanged.
{
  int midPoint;
  int first = 0;
  int last = length - 1;

  bool more = first <= last;
  found = false;
  while (more && !found) 
  {
    midPoint = (first + last) / 2;
	if (item == info[midPoint])
	{
		found = true;
		loc = midPoint;
	}
	else
	{
		if (item < info[midPoint])
		  last = midPoint - 1;
		else
		  first = midPoint + 1;
        more = (first <= last);
	}
  }
}

template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found) 
// Retrieves list element whose key matches item's key 
// (if present).
// Pre:  Key member of item is initialized.
// Post: If there is an element someItem whose key matches 
//       item's key, then found = true and item is a copy 
//       of someItem; otherwise found = false and item is 
//       unchanged. 
//       List is unchanged.
{
	int loc;
	binarySearch( item, found, loc );

	if (found)
		item = info[loc];
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
// Adds item to list.
// Pre:  List is not full.
//       item is not in list. 
// Post: item is in list.
{
  bool more;
  int loc = 0;

  more = (loc < length);

  // locate the insertion point
  while (more)
  {
    if (item > info[loc])
	{
		loc++;
        more = (loc < length);
	}
	else
        more = false;
  }

  // shift elements down to make room for new item
  for (int index = length; index > loc; index--)
    info[index] = info[index - 1];

  // insert new item
  info[loc] = item;

  length++;
}


template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item) 
// Deletes the element whose key matches item's key.
// Pre:  Key member of item is initialized.
//       One and only one element in list has a key matching
//       item's key.
// Post: No element in list has a key matching item's key.
{
  bool found;
  int loc = 0;

  // locate the deletion point
  binarySearch( item, found, loc );

  // shift elements up to remove item
  for (int index = loc + 1; index < length; index++)
    info[index - 1] = info[index];

  length--;
}

template <class ItemType>
void SortedType<ItemType>::ResetList()  
  // Post: current position has been initialized. 
{
  cPos = 0;
}

template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item) 
  // Returns the next element in list.
  // Pre:  Current position is defined.
  // Post: item is a copy of the element at the current position.
  //       After returning the current item, current position is updated 
  //       to the next position.
{
  item = info[cPos];
  cPos++;
}

template <class ItemType>
bool SortedType<ItemType>::AtEnd()
// Returns true if currentPos is at end of list.
// Pre:  Current position is defined.
{
  return cPos == length;  
}