#include <cstdlib>
#include <iostream>
#include "hw5 TREE.H"

using namespace std;

int main()
{
	TreeType<int> t;

	cout << "# nodes = " << t.NumberOfNodes() << endl;

	t.InsertItem(25);
	t.InsertItem(20);
	t.InsertItem(35);
	t.InsertItem(30);

	cout << "tree (inorder) = ";
	t.PrintTree( cout );
	cout << endl;

	cout << "# nodes = " << t.NumberOfNodes() << endl;
	cout << "# leaves = " << t.LeafCount() << endl;

	t.InsertItem(40);
	t.InsertItem(27);
	t.InsertItem(15);
	t.InsertItem(10);
	t.InsertItem(31);
	t.InsertItem(33);
	t.InsertItem(32);

	cout << "# nodes = " << t.NumberOfNodes() << endl;
	cout << "# leaves = " << t.LeafCount() << endl;

	cout << "# nodes less than 30 = " << t.NumberLess(30) << endl;
	cout << "# nodes less than 40 = " << t.NumberLess(40) << endl;

	/*TreeType<int> tCopy(t);
	if (t.SameShape(tCopy))
		cout << "Tree and its copy are the same shape. As it should be. " << endl << endl;
	else
		cout << "Something's messed up. Fix it." << endl << endl;

	tCopy.InsertItem(50);
	if (t.SameShape(tCopy))
		cout << "After adding 50 to the tree, it is still the same shape as the original." 
		<< endl << "Something's messed up. Fix it." << endl << endl;
	else
		cout << "Adding new leaf 50 to the tree makes it a different shape." << endl
		<< "As it should be." << endl << endl;

	tCopy.DeleteItem(40);
	if (t.SameShape(tCopy))
		cout << "Tree and its copy are the same shape after deleting leaf 40." << endl << endl;
	else
		cout << "Tree and its copy are not the same shape after deleting leaf 40." << endl << endl;*/


	//cout << "Tree (inorder) = ";
	t.PrintTree( cout );
	cout << endl;
	//cout << "Mirror image of tree (inorder) = ";
	t.MirrorImage().PrintTree( cout );
	cout << endl;

	if (t.SameShape(t.MirrorImage()))
		cout << "Tree is symmetrical. " << endl;
	else
		cout << "Tree is not symmetrical. " << endl;

	TreeType<int> tCopy;

	//tCopy.MakeEmpty();
	tCopy.InsertItem(25);
	tCopy.InsertItem(10);
	tCopy.InsertItem(40);
	tCopy.InsertItem(5);
	tCopy.InsertItem(15);
	tCopy.InsertItem(35);
	tCopy.InsertItem(45);

	if (tCopy.SameShape(tCopy.MirrorImage()))
		cout << "New tree is symmetrical. " << endl;
	else
		cout << "New tree is not symmetrical. " << endl;

	return 0;
}