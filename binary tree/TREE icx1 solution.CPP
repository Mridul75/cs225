template<class ItemType>
int TreeType<ItemType>::NumberOfNodes() const
// Calls recursive function CountNodes to count the
// nodes in the tree.
{
  return CountNodes(root);
}

template<class ItemType>
int CountNodes(TreeNode<ItemType>* tree)
// Post: returns the number of nodes in the tree.
{
  if (tree == NULL)
    return 0;
  else
    return CountNodes(tree->left) +
      CountNodes(tree->right) + 1;
}

template<class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
  Retrieve(root, item, found);
}

template<class ItemType>
void Retrieve(TreeNode<ItemType>* tree, 
		 ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item’s, 
//       found is true and item is set to a copy of someItem; 
//       otherwise found is false and item is unchanged.
{
  if (tree == NULL)
    found = false;                      // item is not found.
  else if (item < tree->info)
    Retrieve(tree->left, item, found);  // Search left subtree.
  else if (item > tree->info)
    Retrieve(tree->right, item, found); // Search right subtree.
  else
  {
    item = tree->info;                   // item is found.
    found = true;
  }
}

template<class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
  Insert(root, item);
}

template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
  {// Insertion place found.
    tree = new TreeNode<ItemType>;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info)
	Insert(tree->left, item);    // Insert in left subtree.
  else
    Insert(tree->right, item);   // Insert in right subtree.
}

template<class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
    Delete(root, item);
}

template<class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
  if (item < tree->info)
    Delete(tree->left, item);   // Look in left subtree.
  else if (item > tree->info)
    Delete(tree->right, item);  // Look in right subtree.
  else
    DeleteNode(tree);           // Node found; call DeleteNode.
}

template<class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree)
// Deletes the node pointed to by tree.
// Post: The user’s data in the node pointed to by tree is no
//       longer in the tree. If tree is a leaf node or has only
//       one non-NULL child pointer, the node pointed to by tree is
//       deleted; otherwise, the user’s data is replaced by its
//       logical predecessor and the predecessor’s node is deleted.
{
  ItemType data;
  TreeNode<ItemType>* tempPtr;
  
  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
  else
  {
    GetPredecessor(tree, data);
    tree->info = data;
    Delete(tree->left, data);  // Delete predecessor node.
  }
}

template<class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

template<class ItemType>
void Print(TreeNode<ItemType>* tree, std::ostream& out)
// Prints info member of items in tree in sorted order on outFile.
// Assumes the << operator is overloaded as a friend in ItemType
{
  if (tree != NULL)
  {
    Print(tree->left, out);   // Print left subtree.
    out << tree->info << " "; // Print the current node, followed by a space
    Print(tree->right, out);  // Print right subtree.
  }
}

template<class ItemType>
void TreeType<ItemType>::PrintTree(std::ostream& out) const
// Calls recursive function Print to print items in the tree.
{
  Print(root, out);
}

template<class ItemType>
TreeType<ItemType>::TreeType()
{
    root = NULL;
}

template<class ItemType>
TreeType<ItemType>::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
  Destroy(root);
}

template<class ItemType>
void Destroy(TreeNode<ItemType>*& tree)
// Post: Tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

template<class ItemType>
TreeType<ItemType>::TreeType(const TreeType<ItemType>& originalTree)
// Calls recursive function CopyTree to copy tree pointed to by
// originalTree into self.
{
  CopyTree(root, originalTree.root);
}

template<class ItemType>
void TreeType<ItemType>::
operator=(const TreeType<ItemType>& originalTree)
// Calls recursive function CopyTree to copy tree pointed to by
// originalTree into self.
{
  if (&originalTree == this)
    return;                    // Ignore assigning self to self.
  Destroy(root);                 // Deallocate existing tree nodes.
  CopyTree(root, originalTree.root);
}

template<class ItemType>
void CopyTree(TreeNode<ItemType>*& copy,
    const TreeNode<ItemType>* originalTree)
// Post: copy is the root of a tree that is a duplicate
//       of tree pointed to by originalTree.
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new TreeNode<ItemType>;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}

int max( int x, int y)
{
	return x > y ? x : y;
	//if (x>y)
	//	return x;
	//else
	//	return y;
}

template<class ItemType>
int TreeType<ItemType>::NumLevels()
// Calls recursive function CountLevels to count the
// levels in the tree.
{
  return CountLevels(root);
}

template<class ItemType>
int CountLevels(TreeNode<ItemType>* tree)
// Post: returns the number of levels in the tree.
{
  if (tree == NULL)
    return 0;
  else
    return 1 + max( CountLevels(tree->left), CountLevels(tree->right) );
}

template<class ItemType>
void TreeType<ItemType>::PrintAncestorsDown( ItemType item )
// Pre:   Item occurs in some node in the tree
// Post:  Prints ancestors from the root down to item
{
	PADown( root, item );
}

template<class ItemType>
void PADown( TreeNode<ItemType>* tree, ItemType item )
{
	if (tree->info != item)
	{
		cout << tree->info << " ";
		if (item < tree->info)
		  PADown( tree->left, item );
		else
		  PADown( tree->right, item );
	}
}

template<class ItemType>
void TreeType<ItemType>::PrintAncestorsUp( ItemType item )
// Pre:   Item occurs in some node in the tree
// Post:  Prints ancestors from item up to the root
{
	PAUp( root, item );
}

template<class ItemType>
void PAUp( TreeNode<ItemType>* tree, ItemType item )
{
	if (tree->info != item)
	{
		if (item < tree->info)
		  PAUp( tree->left, item );
		else
		  PAUp( tree->right, item );
		cout << tree->info << " ";
	}
}

template<class ItemType>
bool TreeType<ItemType>::ShapeIsFull( )
// Post:  Returns whether the tree is full (all leaves are at the last level and every non-leaf node 
//           has two children).
//            Assume the empty tree is full.
{
	return ShapeFull( root );
}

template<class ItemType>
bool ShapeFull ( TreeNode<ItemType>* tree )
{
	if (tree->left == NULL && tree->right == NULL)
		return true;

	else if (ShapeFull(tree->left))
	{
		if (ShapeFull(tree->right))
			return true;
		else 
			return false;
	}
	else
		return false;
}

//bool ShapeIsSkewed( );
// Post:  Returns whether the tree is skewed (every node has one or no children).
//            Assume the empty tree is skewed.

