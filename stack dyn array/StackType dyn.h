// Dynamically allocated array version

const int MAX_ITEMS = 5;

template<class ItemType>
class StackType
{
public:
  StackType();            // MAX_ITEMS == size of dyn allocated array
  StackType(int max);     // max == size of dyn allocated array

  ~StackType();
  // Class destructor.

  void MakeEmpty();
  // Function:  Sets stack to an empty state.
  // Post: Stack is empty.

  bool IsEmpty() const;
  // Function: Determines whether the stack is full.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is empty)

  bool IsFull() const;
  // Function: Determines whether the stack is full.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is full)

  void Push(ItemType newItem);
  // Function: Adds newItem to the top of the stack.
  // Pre:  Stack has been initialized and is not full.
  // Post: newItem is at the top of the stack.

  void Pop(ItemType& item);
  // Function: Removes top item from the stack and returns it in item.
  // Pre:  Stack has been initialized and is not empty.
  // Post: Top element has been removed from stack.
  //       item is a copy of the removed item.

  ItemType Top();
  // Function: Returns a copy of the top item from the stack.
  // Pre:  Stack has been initialized and is not empty.
  // Post: Copy of the top element is returned.

private:
  int top;
  int MaxItems;
  ItemType* items;   // points to dyn allocated array
};

#include "StackType dyn.cpp"


