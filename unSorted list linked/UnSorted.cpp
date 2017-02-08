// Implementation file for Unsorted List ADT.
// Class is templated.

template <class ItemType>
struct NodeType
{
  ItemType info;
  NodeType* next;
};

template <class ItemType>		
UnSortedType<ItemType>::UnSortedType()	// Class constructor
{
    length = 0;
    xList = NULL;
}

template <class ItemType>
UnSortedType<ItemType>::~UnSortedType()
// Post: List is empty; all items have been deallocated.
{
  MakeEmpty();
}

template <class ItemType>
bool UnSortedType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType on the free store;
// false otherwise.
{
  NodeType<ItemType>* p;

  p = new NodeType<ItemType>;
  if (p == NULL)
    return true;
  else
  {
    delete p;
    return false;
  }
}

template <class ItemType>
int UnSortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}

template <class ItemType>
void UnSortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
  NodeType<ItemType>* p;
  
  while (xList != NULL)
  {
    p = xList;
    xList = xList->next;
    delete p;
  }
  length = 0;
}

template <class ItemType>
void UnSortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
// Pre:  Key member(s) of item is initialized.

// Post: If found, item's key matches an element's key in the list and
//       a copy of that element has been stored in item; otherwise,
//       item is unchanged.
{
  bool more;
  NodeType<ItemType>* p;
  
  p = xList;
  found = false;
  more = (p != NULL);
  
  while (more && !found)
  {
    if (item == p->info)
    {
      found = true;
      item = p->info;
    }
    else
    {
      p = p->next;
      more = (p != NULL);
    }
  }
}

template <class ItemType>
void UnSortedType<ItemType>::InsertItem(const ItemType& item)
// item is in the list; length has been incremented.
{
  NodeType<ItemType>* p;

  p = new NodeType<ItemType>;
  p->info = item;  // (*p).info = item;
  p->next = xList;
  xList = p;
  length++;
}

template <class ItemType>
void UnSortedType<ItemType>::DeleteItem(const ItemType& item)
// Pre: item's key has been initialized.
//      An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  NodeType<ItemType>* p = xList;
  NodeType<ItemType>* q;
  
  // Locate node to be deleted.
  if (item == xList->info)
  { 
	// delete the first node as a special case
    q = p;        // point to the first node
    xList = xList->next;		// skip list over this node.
  }
  else
  {
    // set location to point to the node before the node containing item
    while (item!=(p->next)->info)
      p = p->next;
    
    q = p->next;            // point to the node containing item
    p->next = (p->next)->next;  // skip list over this node
  }

  delete q;  // deallocate the node containing item
  length--;
}

template <class ItemType>
void UnSortedType<ItemType>::ResetList()
// Initializes current position for an iteration through the list.
// Post: Current position is initialized.
{
  cPos = xList; 
}
 
template <class ItemType>
void UnSortedType<ItemType>::GetNextItem(ItemType& item) 
// Returns the next element in list.
// Pre:  Current position is defined.
// Post: item is a copy of the element at the current position.
//       After returning the current item, current position is updated 
//       to the next position.
{
  item = cPos->info;
  cPos = cPos->next;
} 

template <class ItemType>
bool UnSortedType<ItemType>::AtEnd()
// Returns true if currentPos is at end of list (i.e., NULL).
// Pre:  Current position is defined.
{
  return cPos == NULL;  
}