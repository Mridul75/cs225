template<class ItemType>
StackType<ItemType>::StackType()
{
  top = -1;
  MaxItems = MAX_ITEMS;
  items = new ItemType[MaxItems];
}

template<class ItemType>
StackType<ItemType>::StackType(int max)
{
  top = -1;
  MaxItems = max;
  items = new ItemType[MaxItems];
}

template<class ItemType>
StackType<ItemType>::~StackType()	// Class destructor
{
    delete [] items;
}

template<class ItemType>
void StackType<ItemType>::MakeEmpty()
{
  top = -1;
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
  return (top == -1);
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
  return (top ==  MaxItems-1);
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
  top++;
  items[top] = newItem;
}

template<class ItemType>
void StackType<ItemType>::Pop(ItemType& item)
{
  item = items[top];
  top--;
}

template<class ItemType>
ItemType StackType<ItemType>::Top()
{
  return items[top];
}