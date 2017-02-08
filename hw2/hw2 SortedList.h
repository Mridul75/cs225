// SortedList.h
// Header file for Sorted List ADT.  

template <class ItemType>
struct NodeType;

// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined-either an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType>
class SortedType
{
public:
  SortedType();
  ~SortedType();

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
  // Retrieves list element whose key matches item's key 
  // (if present).
  // Pre:  Key member of item is initialized.
  // Post: If there is an element someItem whose key matches 
  //       item's key, then found = true and item is a copy 
  //       of someItem; otherwise found = false and item is 
  //       unchanged. 
  //       List is unchanged.

  void InsertItem(ItemType item); 
  // Adds item to list.
  // Pre:  List is not full.
  //       item is not in list. 
  // Post: item is in list.

  void DeleteItem(ItemType item);
  // Deletes the element whose key matches item's key.
  // Pre:  Key member of item is initialized.
  //       One and only one element in list has a key matching
  //       item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Function: Initializes current position for an iteration through the list.
  // Post: Current position is initialized.

  void GetNextItem(ItemType&);
  // Function: Gets the next element in list.
  // Pre:  Current position is defined.
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

  bool AtEnd();
  //Post: returns true if currentPos is at end of list

  void Print( ostream& out );
  // Function:	Prints items in the list from beginning to end.  Items are 
  //            printed in rows of 10 (the last line may contain fewer than 10 items), 
  //            lined up in columns.  Terminates each line (including last line) with endl.
  // Preconditions: 	List has been initialized.
  // Postconditions:	List is unchanged.

  void RemoveEven( );
  // Function:	Removes all even values from list.
  // Preconditions: 	List has been initialized.
  // Postconditions:	List = list after removing all even values.

  void RemoveDuplicates( );
  // Function:	Removes all duplicated values from list (i.e., if a value occurs 
  //            more than once, only one occurance of the value will remain in 
  //            the list when this function returns).
  // Preconditions: 	List has been initialized.
  // Postconditions:	List = list after removing all duplicated values.

 private:
  NodeType<ItemType>* xList;
  int length;
  NodeType<ItemType>* cPos;
};

#include "hw2 SortedList.cpp"
