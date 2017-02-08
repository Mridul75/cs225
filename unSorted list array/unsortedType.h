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

  void RetrieveItem( /* inout */ ItemType& item, /* out */ bool& found);
  // Pre: Key member(s) of item is initialized. 
  // Post: If found, item's key matches an element's key in the 
  // list and a copy of that element has been stored in item; 
  // otherwise, item is unchanged.   
  
  void InsertItem(ItemType item);
  // Pre: item's key has been initialized. 
  //      Room exists in list for a new item.
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

private:
  int length;
  ItemType info[MAX_ITEMS];
  int currentPos;
};

#include "unSortedType.cpp"
