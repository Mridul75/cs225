// File: StackLinked.h

// This is the header file for Stack ADT using a templated linked list
// implementation.

template <class ItemType>
struct NodeType;
//  struct NodeTYpe is defined in StackLinked.cpp

template<class ItemType>
class StackType
{
public:
  StackType();
  ~StackType();
  
  void MakeEmpty();
  // Function:  Sets stack to an empty state.
  // Post: Stack is empty.
  
  bool IsFull() const;
  // Function: Determines whether the stack is full.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is full)
  
  bool IsEmpty() const;
  // Function: Determines whether the stack is empty.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is empty)
  
  void Push(ItemType item);
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
  NodeType<ItemType>* xTop;
};

#include "stackLinked.cpp"

