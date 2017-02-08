// SortedType.cpp

#include <iostream>
#include <iomanip>

template <class ItemType>
struct NodeType
{
  ItemType info;
  NodeType* next;
};

template <class ItemType>
SortedType<ItemType>::SortedType()  // Class constructor
{
  length = 0;
  xList = NULL;
}

template <class ItemType>
SortedType<ItemType>::~SortedType() 
// Post: List is empty; all items have been deallocated.
{
  MakeEmpty();
}

template <class ItemType>
bool SortedType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType 
// object on the free store; false otherwise.
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
int SortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
  NodeType<ItemType>* p;

  while (xList != NULL) // traverse list, deallocating each node in turn
  {
    p = xList;
    xList = xList->next;
    delete p;
  }
  length = 0; // to agree with the fact that all nodes are deallocated
}

template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  NodeType<ItemType>* p = xList;
  NodeType<ItemType>* q;

  // Locate node to be deleted.
  if (item == xList->info)
  {
    q = p;
    xList = xList->next;		// Delete first node.
  }
  else
  {
    while (!(item==(p->next)->info))
      p = p->next;
    
    // Delete node at location->next
    q = p->next;
    p->next = (p->next)->next;
  }
  delete q;
  length--;
}
 
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
  bool more;
  NodeType<ItemType>* p = xList;

  found = false;
  more = (p != NULL);
  while (more && !found)
  {
    if (p->info < item)
    {
      p = p->next;
      more = (p != NULL);
    }
    else if (item == p->info)
    {
      found = true;
      item = p->info;
    }
    else
      more = false;
  }
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
  NodeType<ItemType>* q = NULL;  // trailing pointer
  NodeType<ItemType>* p= xList;  // traveling pointer
  bool more;

  more = (p != NULL);

  // Find insertion point.
  while (more)
  {
    if (p->info < item)
    {
      q = p;
      p = p->next;
      more = (p != NULL);
    }
    else
      more = false;
  }

  // Prepare new node for insertion
  NodeType<ItemType>* n = new NodeType<ItemType>;
  n->info = item;

  // Insert node into list.
  if (q == NULL)         // Insert as first
  {
    n->next = xList;
    xList = n;
  }
  else
  {
    n->next = p;
    q->next = n;
  }
  length++;
}

template <class ItemType>
void SortedType<ItemType>::ResetList()
  // Function: Initializes current position for an iteration through the list.
  // Post: Current position is initialized.
{
  cPos = xList; 
}

template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
  // Function: Gets the next element in list.
  // Pre:  Current position is defined.
  // Post: item is a copy of the element at the current position.
  //       After returning the current item, current position is updated 
  //       to the next position.
{
  item = cPos->info;
  cPos = cPos->next;
}

template <class ItemType>
bool SortedType<ItemType>::AtEnd()
  // Function: returns true if current position is at end of list (i.e., NULL).
  // Pre:  Current position is defined.
{
  return cPos == NULL;  
}

template <class ItemType>
void SortedType<ItemType>::Print( ostream& out )
  // Function:	Prints items in the list from beginning to end.  Items are 
  //            printed in rows of 10 (the last line may contain fewer than 10 items), 
  //            lined up in columns.  Terminates each line (including last line) with endl.
  // Preconditions: 	List has been initialized.
  // Postconditions:	List is unchanged.
{
	ResetList();
	int columnCount;
	ItemType item;

	while (!AtEnd())
	{
		columnCount = 1;
		while (columnCount <= 10 && !AtEnd())
		{
			GetNextItem(item);
			out << setw(4) << item;
			columnCount++;
		}
		out << endl;
	}
}

template <class ItemType>
void SortedType<ItemType>::RemoveEven()
  // Function:	Removes all even values from list.
  // Preconditions: 	List has been initialized.
  // Postconditions:	List = list after removing all even values.
{
	ResetList();
	ItemType item;

	while (!AtEnd())               
	{                              // Until end of list is reached,
		GetNextItem(item);         // go through each item in the list.
		if (item % 2 == 0)         // If the item is even,
			DeleteItem(item);      // delete it from the list.
	}
}

template <class ItemType>
void SortedType<ItemType>::RemoveDuplicates( )
  // Function:	Removes all duplicated values from list (i.e., if a value occurs 
  //            more than once, only one occurance of the value will remain in 
  //            the list when this function returns).
  // Preconditions: 	List has been initialized.
  // Postconditions:	List = list after removing all duplicated values.
{
	ResetList();
	ItemType item;
	ItemType previous;

	GetNextItem(previous);

	while (!AtEnd())
	{                              // Until end of list is reached,
		GetNextItem(item);         // go through each item in the list.
		if (item == previous)      // If an item is the same as the previous item,
			DeleteItem(item);      // delete it from the list.
		previous = item;           // Then update the previous item. 
	}
}