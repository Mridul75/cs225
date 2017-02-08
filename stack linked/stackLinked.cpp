template <class ItemType>
struct NodeType
{
  ItemType info;
  NodeType<ItemType>* next;
};

template<class ItemType>
StackType<ItemType>::StackType()
{
  xTop = NULL;
}

template <class ItemType>
StackType<ItemType>::~StackType()
{
  MakeEmpty();
}

template <class ItemType>
void StackType<ItemType>::MakeEmpty() 
{
  NodeType<ItemType>* p;
  
  while (xTop != NULL)
  {
    p = xTop;
    xTop = xTop->next;
    delete p;
  }
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
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
bool StackType<ItemType>::IsEmpty() const
{
  return xTop == NULL;
}

template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
  NodeType<ItemType>* p = new NodeType<ItemType>;
  p->info = newItem;
  p->next = xTop;
  xTop = p;
}

template<class ItemType>
void StackType<ItemType>::Pop(ItemType& item)
{
  NodeType<ItemType>* p = xTop;
  item = xTop->info;
  xTop = xTop->next;
  delete p;
}

template<class ItemType>
ItemType StackType<ItemType>::Top()
{
  return xTop->info;
}
