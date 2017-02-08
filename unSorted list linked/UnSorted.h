// File UnSorted.h: Header file for Unsorted List ADT.
// Templated linked list implementation
 
template <class ItemType>
struct NodeType;

// Assumption:  ItemType is a type for which the operators "<" and "==" are // defined
// either an appropriate built-in type or a class that overloads these operators.

template <class ItemType>
class UnSortedType   
{
public:
  UnSortedType();		// Class constructor
  ~UnSortedType();   	// Class destructor
  
  bool IsFull() const;
  // Determines whether list is full.
  // Post: Function value = (list is full)
  
  int  LengthIs() const;
  // Determines the number of elements in list.
  // Post: Function value = number of elements in list.
  
  void MakeEmpty();
  // Initializes list to empty state.
  // Post:  List is empty.
  
  void RetrieveItem(ItemType& item, bool& found);
  // Retrieves list element whose key matches item's key (if present).
  // Pre:  Key member of item is initialized.
  // Post: If there is an element someItem whose key matches item's key,
  //       then found = true and item is a copy of someItem; otherwise
  //       found = false and item is unchanged.
  //       List is unchanged.
  
  void InsertItem(const ItemType& item);
  // Adds item to list.
  // Pre:  List is not full.
  //       item is not in list.
  // Post: item is in list.
  
  void DeleteItem(const ItemType& item);
  // Deletes the element whose key matches item's key.
  // Pre:  Key member of item is initialized.
  //       One and only one element in list has a key matching item's key.
  // Post: No element in list has a key matching item's key.
  
  void ResetList();
  // Initializes current position for an iteration through the list.
  // Post: Current position is initialized.
  
  void GetNextItem(ItemType& item);
  // Returns the next element in list.
  // Pre:  Current position is defined.
  // Post: item is a copy of the element at the current position.
  //       After returning the current item, current position is updated 
  //       to the next position.
  
  bool AtEnd();
  // Returns true if currentPos is at end of list.
  // Pre:  Current position is defined.
  
 private:
  NodeType<ItemType>* xList;   // external pointer
  int length;
  NodeType<ItemType>* cPos;    // current position pointer
};

#include "UnSorted.cpp"

