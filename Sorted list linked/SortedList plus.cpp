#include <iostream>

template <class ItemType>
struct NodeType
{
  ItemType info;
  NodeType* next;
};

template <class ItemType>
SortedType<ItemType>::SortedType()  // default constructor
{
  length = 0;
  xList = NULL;
}

template<class ItemType>	     // copy constructor
SortedType<ItemType>::SortedType( const SortedType<ItemType>& list2 )
{	
	NodeType<ItemType>* ptr1 ;
	NodeType<ItemType>* ptr2 ;
	if ( list2.xList == NULL )
		xList = NULL ;
	else			    // allocate memory for first node
	{	
		xList = new NodeType<ItemType> ;
		xList->info = list2.xList->info ;
		ptr1 = list2.xList->next ;
		ptr2 = xList ;
		while ( ptr1 != NULL )	// deep copy other nodes
		{	ptr2->next = new NodeType<ItemType> ;
			ptr2 = ptr2->next ;
			ptr2->info = ptr1->info ;
			ptr1 = ptr1->next ;
		}
		ptr2->next = NULL ;	
	}

	length = list2.length;
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
int SortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
  NodeType<ItemType>* tempPtr;

  while (xList != NULL) // traverse list, deallocating each node in turn
  {
    tempPtr = xList;
    xList = xList->next;
    delete tempPtr;
  }
  length = 0; // to agree with the fact that all nodes are deallocated
}

template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  NodeType<ItemType>* location = xList;
  NodeType<ItemType>* tempLocation;

  // Locate node to be deleted.
  if (item == xList->info)
  {
    tempLocation = location;
    xList = xList->next;		// Delete first node.
  }
  else
  {
    while (!(item==(location->next)->info))
      location = location->next;
    
    // Delete node at location->next
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
  length--;
}
 
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
  bool moreToSearch;
  NodeType<ItemType>* location;

  location = xList;
  found = false;
  moreToSearch = (location != NULL);

  while (moreToSearch && !found)
  {
    if (location->info < item)
    {
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else if (item == location->info)
    {
      found = true;
      item = location->info;
    }
    else
      moreToSearch = false;
  }
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
  NodeType<ItemType>* newNode;  // pointer to node being inserted
  NodeType<ItemType>* predLoc;  // trailing pointer
  NodeType<ItemType>* location; // traveling pointer
  bool moreToSearch;

  location = xList;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    if (location->info < item)
    {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else
      moreToSearch = false;
  }

  // Prepare node for insertion
  newNode = new NodeType<ItemType>;
  newNode->info = item;

  // Insert node into list.
  if (predLoc == NULL)         // Insert as first
  {
    newNode->next = xList;
    xList = newNode;
  }
  else
  {
    newNode->next = location;
    predLoc->next = newNode;
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
  // Function: returns true if cPos is at end of list (i.e., NULL).
  // Pre:  Current position is defined.
{
  return cPos == NULL;  
}
