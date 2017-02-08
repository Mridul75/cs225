const int MAX_ITEMS = 10;

template <class ItemType>
class UnsortedType 
{
public:
  UnsortedType();     // default constructor

  void MakeEmpty();
  // Post: list is empty 

  bool IsFull() const;
  // returns true if list if full; else returns false

  int LengthIs() const;
  // returns the number of items in the list

  void RetrieveItem(ItemType& item, bool& found);
// Pre: Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
// list and a copy of that element has been stored in item; 
// otherwise, item is unchanged.   
  
  void InsertItem(ItemType item);
  // Pre: item's key has been initialized. 
  // Post: item is in the list. 

  void DeleteItem(ItemType item);
  // Pre: item's key has been initialized. 
  // An element in the list has a key that matches item's. 
  // Post: No element in the list has a key that matches item's. 

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

  void Print( ostream& out );
  // Prints items in the list from beginning to end.  
  // Items are printed on a single line of output with one space between each item.  
  // Terminates the line with endl.
  // Pre: List has been initialized.
  // Post: List is unchanged.

  UnsortedType Merge( UnsortedType list2 );
  // Merges two unsorted lists (list and list2) into a third unsorted list.
  // Pre: Lists have been initialized.
  //      list and list2 are different lists.
  //      Merged list does not exceed the maximum size for a list.
  // Post: Function value = list that contains all of the items from list and list2.  
  //       list and list2 are unchanged.

  void Split( ItemType item, UnsortedType& list1, UnsortedType& list2 );
  // Divides list into two lists (list1 and list2) according to the key of item.  
  // Pre: List has been initialized and is not empty.
  //      List, list1, and list2 are different lists.
  // Post: list1 contains all of the items of list whose keys are less than or equal to item’s key.  
  //       These will be the only items in list1.
  //       list2 contains all of the items of list whose keys are greater than item’s key.
  //       These will be the only items in list2.
  //       List is empty.

private:
  int length;
  ItemType info[MAX_ITEMS];
  int currentPos;
};

#include "hw1 unSortedType.cpp"
