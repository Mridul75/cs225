//************************************************************
// Marissa Carson
// CS2 with Terry Hostetler
// Homework 4: Using Recursion To Solve A Maze
// April 5th, 2013
//************************************************************

#include <iostream>
#include <fstream>
using namespace std;

const int X_MAX = 10, Y_MAX = 10;
const char WALL = '*', OPEN = '.';

typedef char GridType[X_MAX][Y_MAX];
enum Direction { RIGHT, DOWN, LEFT, UP };

struct MazeType
{
	GridType g;    // Actual maze grid; 2d array to be filled with open and wall characters
	int NR, NC;    // Number of rows, number of columns
};

struct PointType
{
	int x, y;         // Dimensions on the grid
	Direction z;      // Direction taken to get to this point
	PointType* next;  // Next point on the path
	PointType* prev;  // Previous point on the path
};


//Function Prototypes
void StepFrom(/*inout*/PointType &p, /*in*/MazeType &maze, int /*out*/&status, PointType* solutions [], int n);
void GetMaze(/*in*/ifstream &inData, /*out*/MazeType & maze);
void PrintMaze(/*in*/MazeType & maze);
bool SolveMaze(/*inout*/MazeType &maze);
PointType Q(/*in*/PointType p, /*in*/int turn);
void DeletePath (/*inout*/PointType &p);
PointType CopyPath (/*inout*/PointType &p1, /*out*/PointType* &first);
void ClearMaze(MazeType &maze);


int main()
{
	ifstream inData("maze.in");
	MazeType maze;

	GetMaze(inData, maze);

	bool solved = SolveMaze(maze);
	PrintMaze(maze);
	if (!solved)
		cout << "No solution found!" << endl;
	
	return 0;
}

//*********************************************************************

void GetMaze(ifstream &inData, MazeType & maze)
// Preconditions:  input file with correct data for this program has been opened, 
//				   a 2d array has been declared and passed as a MazeType grid
// Postconditions: Grid has been filled with maze data from input file, NR and NC
//				   have been filled with dimension data
{
	inData >> maze.NR >> maze.NC;

	for (int x = 0; x < maze.NR; x++)
		for (int y = 0; y < maze.NC; y++)
			inData >> maze.g[x][y];
}

//*********************************************************************

void PrintMaze(MazeType & maze)
// Preconditions:  a Mazetype maze has been filled with open and wall characters,
//				   and, if possible, the solution path. NR and NC are the dimensions
//				   of the maze. 
// Postconditions: the maze has been printed to the display screen. 
{
	for (int x = 0; x < maze.NR; x++)
	{
		for (int y = 0; y < maze.NC; y++)
			cout << maze.g[x][y];
		cout << endl;
	}
}


//*********************************************************************

bool SolveMaze(MazeType &maze)
// Preconditions:  a maze has been filled with open and wall characters from the input file
//				   and has correct dimensions NR and NC
// Postconditions: either the maze has been solved and the solution path's spaces have been
//				   marked with letters in order, or the maze cannot be solved. Whether or not
//				   the maze has been solved is returned as true or false. 
{
	PointType* first = new PointType;
	first->x = 0;
	first->y = 0;
	first->z = RIGHT;
	first->next = NULL;
	first->prev = NULL;
	int status = 2;          // 0 means complete, 1 means dead end, 2 means path

	PointType* solutions[30];
	solutions[0] = first;
	int n = 0;  // solution number

	StepFrom(*solutions[0], maze, status, solutions, n);

	//if (status == 0)                 // If the maze has been solved,
	{
		PointType* p = solutions[0];
		char mark = 'a';               // mark the path with letters

		while (p != NULL)
		{
			maze.g[p->x][p->y] = mark;
			mark++;
			if (mark > 'z')
				mark = 'a';
			p = p->next;
		}
		ClearMaze(maze);
		return true;
	}

	//else 
	//	return false;
}

//*********************************************************************

void StepFrom(PointType &p, MazeType &maze, int &status, PointType* solutions [], int n)
// Preconditions:  a PointType p has coordinates x and y that correspond to an open point on the maze,
//				   which is filled with open and wall characters and has dimensions NR and NC
// Postconditions: either the maze has reached the end or a dead end, in which case the function stops, 
//				   or the function has recursively called itself using some "next" point in the maze. 
//				   Status is 0 if the maze has been solved and 1 if it has not. 
{
	maze.g[p.x][p.y]= ',';                 // Mark visited space

	if (p.x == maze.NR - 1 && p.y == maze.NC - 1)
	{
		p.next = NULL;
		status = 0;
	}

	//if (status == 1)                 // If a dead end is reached, delete the path it is on. 
	//		DeletePath(p);
	//	status = 2;

	else if (status !=0)
	{
		bool one = true, two = true, three = true, onGrid;

		PointType q = Q(p, 0);                  // 1. Try to continue in direction
		onGrid = (q.x >= 0 && q.x < X_MAX && q.y >= 0 && q.y < Y_MAX);

		if (maze.g[q.x][q.y] == OPEN && onGrid /*&& !q.visited*/)
		{
			p.next = &q;
			q.prev = &p;
			StepFrom(*p.next, maze, status, solutions, n);
		}
		else
			one = false;	

		if (status != 0)
		{
			q = Q(p, 1);				          // 2. Try turning right
			onGrid = (q.x >= 0 && q.x < X_MAX && q.y >= 0 && q.y < Y_MAX);

			if (maze.g[q.x][q.y] == OPEN && onGrid /*&& !q.visited*/)
			{
				p.next = &q;
				q.prev = &p;
				StepFrom(*p.next, maze, status, solutions, n);
			}
			else
				two = false;

			if (status != 0)
			{
				q = Q(p, 3);					        // 3. Try turning left
				onGrid = (q.x >= 0 && q.x < X_MAX && q.y >= 0 && q.y < Y_MAX);

				if (maze.g[q.x][q.y] == OPEN && onGrid /*&& !q.visited*/)
				{
					p.next = &q;
					q.prev = &p;
					StepFrom(*p.next, maze, status, solutions, n);
				}
				else
					three = false;

				if (status != 0)
				{
					if (one == false && two == false && three == false)
					status = 1;
				}
			}
			//else
			//{
			//	q = Q(p, 3);					        // 3. Try turning left
			//	onGrid = (q.x >= 0 && q.x < X_MAX && q.y >= 0 && q.y < Y_MAX);

			//	// Do everything left but to p2
			//	if (maze.g[q.x][q.y] == OPEN && onGrid /*&& !q.visited*/)
			//	{
			//		n++;
			//		PointType p2 = CopyPath(p, solutions[n]);
			//		ClearMaze(maze);
			//		status = 2;

			//		p2.next = &q;
			//		q.prev = &p2;
			//		StepFrom(*p2.next, maze, status, solutions, n);
			//	}
			//	
			//	if (status == 1)
			//		n--;
			//}
		}	
		else
		{
			one = false; 

			q = Q(p, 1);				          // 2. Try turning right
			onGrid = (q.x >= 0 && q.x < X_MAX && q.y >= 0 && q.y < Y_MAX);

			// Do everything left but to p2
			if (maze.g[q.x][q.y] == OPEN && onGrid /*&& !q.visited*/)
			{
				n++;
				PointType p2 = CopyPath(p, solutions[n]);
				ClearMaze(maze);
				status = 2;

				p2.next = &q;
				q.prev = &p2;
				StepFrom(*p2.next, maze, status, solutions, n);
			}

			if (status == 1)
			{
				n--;
				two = false;
				status = 0;
			}

			q = Q(p, 3);					        // 3. Try turning left
			onGrid = (q.x >= 0 && q.x < X_MAX && q.y >= 0 && q.y < Y_MAX);

			// Do everything left but to p2
			if (maze.g[q.x][q.y] == OPEN && onGrid /*&& !q.visited*/)
			{
				n++;
				PointType p2 = CopyPath(p, solutions[n]);
				ClearMaze(maze);
				status = 2;

				p2.next = &q;
				q.prev = &p2;
				StepFrom(*p2.next, maze, status, solutions, n);
			}

			if (status == 1)
			{
				n--;
				three = false;
				status = 0;
			}
		}
	}
}

//*****************************************************************

PointType Q(PointType p, int turn)
// Preconditions:  a PointType p has dimensions x,y and a direction z already initialized, 
//				   and turn = 0 for straight, 1 for turn right, 2 for U turn, 3 for turn left
// Postconditions: a PointType q has been returned that goes from p and turns "turn" and steps
//				   one unit in the desired direction
{
	PointType q;        // Attempted point to step to
	q.next = NULL;

	p.z = Direction((p.z + turn) % 4);

	switch (p.z)
	{
		case RIGHT: q.x = p.x;
					q.y = p.y + 1;
					q.z = RIGHT;
					break;
		case DOWN:  q.x = p.x + 1;
					q.y = p.y;
					q.z = DOWN;
					break;
		case LEFT:  q.x = p.x;
					q.y = p.y - 1;
					q.z = LEFT;
					break;
		case UP:	q.x = p.x - 1;
					q.y = p.y;
					q.z = UP;
					break;
	}

	return q;
}

//***********************************************************************

void DeletePath (PointType &p)
// Precondition:  p is an intersection point that currently leads down a dead end
// Postcondition: all points after p have been deleted to free up memory
// Note: This function is never actually called in this program. I wrote it but couldn't
//		 find a place for it. I kept it because it is a good example of recursion, and I
//		 plan on using a modified version of this function as a CopyPath function in the
//		 extra credit version of this program. 
{
	if (p.next->next == NULL)        // If p is 2nd to the end of the path
	{
		delete p.next;               // Delete the point after p
	}

	else
	{
		DeletePath(*p.next);
	}
}

//*************************************************************************

PointType CopyPath (PointType &p1, PointType* &first)
// Precondition:  p1 is an intersection point 
// Postcondition: all points before p1 have been copied, making a new path, and the
//				  new p2 in that path, which is linked to a beginning, has been returned
{
	PointType p2;
	p2.x = p1.x;
	p2.y = p1.y;
	p2.z = p1.z;

	if (p1.prev == NULL) // If p1 is the first point in the path
	{
		p2.prev = NULL;
		first = &p2;
	}
	
	else
	{
		p2.prev = new PointType;
		*p2.prev = CopyPath(*p1.prev, first);
		p2.prev->next = &p2;
	}

	return p2;
}

//********************************************************************

void ClearMaze(MazeType &maze)
{
	for (int x = 0; x < maze.NR; x++)         // Change marked spaces back to normal
		for (int y = 0; y < maze.NC; y++)
			if (maze.g[x][y] == ',')
				maze.g[x][y] = '.';
}

//***************************************************************************************

