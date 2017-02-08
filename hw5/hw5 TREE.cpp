//******************************************************************
// Marissa Carson
// CS2 Homework 5: Binary Tree
// Terry Hostetler
// 4/26/13
//******************************************************************

template<class ItemType>
TreeType<ItemType>::TreeType()
// Constructor
{
    root = NULL;
}

template<class ItemType>
TreeType<ItemType>::TreeType(const TreeType<ItemType>& originalTree)
// Copy constructor:  copies tree pointed to by originalTree to itself.
{
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

template<class ItemType>
TreeType<ItemType>::~TreeType()
// Destructor
{
  MakeEmpty();
}

template<class ItemType>
void TreeType<ItemType>::MakeEmpty()
// Remove all nodes of the tree.
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
bool TreeType<ItemType>::IsEmpty() const
// Returns whether the tree is empty.
{
  return root == NULL;
}

template<class ItemType>
bool TreeType<ItemType>::IsFull() const
// Returns whether the tree is full.
{
  return false;
}

template<class ItemType>
int TreeType<ItemType>::NumberOfNodes() const
// Post: returns the number of nodes in the tree.
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
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);  // Delete predecessor node.
  }
}

template<class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
// Sets data to the info member of the  t node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

template<class ItemType>
void TreeType<ItemType>::PrintTree(std::ostream& out) const
// Calls recursive function Print to print items in the tree.
{
  Print(root, out);
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
void TreeType<ItemType>::
operator=(const TreeType<ItemType>& originalTree)
// Calls recursive function CopyTree to copy tree pointed to by
// originalTree into self.
{
  if (&originalTree == this)
    return;                      // Ignore assigning self to self.
  Destroy(root);                 // Deallocate existing tree nodes.
  CopyTree(root, originalTree.root);
}

//******************************************************************************************************

template<class ItemType>
int TreeType<ItemType>:: LeafCount() const
// Function: Returns the number of leaf nodes in the tree.
// Pre:  Tree has been initialized.
// Post: Function value = number of leaf nodes in the tree.
//       Tree is unchanged.
{
	return CountLeaves(root);
}

template<class ItemType>
int CountLeaves(TreeNode<ItemType>* tree)
{
	if (tree == NULL)        // Ends (branches of leaves, which do not exist) 
		return 0;           // add nothing, and 
	else if (CountLeaves(tree->left) == 0 && CountLeaves(tree->right) == 0)
		return 1;       // For leaves, 
	else
		return CountLeaves(tree->left) + CountLeaves(tree->right);
}

template<class ItemType>
int TreeType<ItemType>:: NumberLess( ItemType item ) const
// Function: Returns the number of nodes in the tree with values less than item.
// Pre:  Tree has been initialized.
// Post: Function value = number of nodes in the tree with values less than item.
//       Tree is unchanged.
{
	return LessThan(root, item);
}

template<class ItemType>
int LessThan(TreeNode<ItemType>* tree, ItemType const &item)
{
	if (tree == NULL)
		return 0;
	else if (tree->info < item)
		return LessThan(tree->right, item) + LessThan(tree->left, item) + 1;
	else if (tree->info >= item)
		return LessThan(tree->right, item) + LessThan(tree->left, item);
	else
		return 0;
}

template<class ItemType>
bool TreeType<ItemType>:: SameShape( const TreeType<ItemType>& otherTree ) const
// Function: Returns whether this tree and otherTree have the same shape (i.e., each 
//           corresponding node has the same number of left children and right children.
// Pre:  Tree and otherTree have been initialized.
// Post: Function value = whether this tree and otherTree have the same shape.
//       Tree and otherTree are unchanged.
{
	return ShapeAlike(root, otherTree.root);
}

template<class ItemType>
bool ShapeAlike(TreeNode<ItemType>* tree1, TreeNode<ItemType>* tree2)
{
	if (tree1 == NULL)
	{
		if (tree2 == NULL)      // If both null, they are the same. 
			return true;
		else
			return false;
	}                           // If only one is null, they are not. 
	else if (tree2 == NULL)
		return false;
                                // If neither is null, recursively 
                                // search the rest of the tree. 
	
	else if (ShapeAlike(tree1->left, tree2->left))
	{
		if (ShapeAlike(tree1->right, tree2->right))
			return true;
		else
			return false;
	}

	else
		return false;

}

template<class ItemType>
TreeType<ItemType> TreeType<ItemType>:: MirrorImage() const
// Function: Creates and returns a mirror image of tree.
// Pre:  Tree has been initialized.
// Post: Function value = a mirror image of tree.
//       Tree is unchanged.
{
	TreeType<ItemType> flipped;
	FlipCopy(flipped.root, root);
	return flipped; 
}

template<class ItemType>
void FlipCopy(TreeNode<ItemType>*& mirror, const TreeNode<ItemType>* tree)
{
	if (tree == NULL)
		mirror = NULL;
	else
	{
		mirror = new TreeNode<ItemType>;
		mirror->info = tree->info;
		FlipCopy(mirror->right, tree->left);
		FlipCopy(mirror->left, tree->right);
	}
}