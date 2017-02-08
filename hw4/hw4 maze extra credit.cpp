//************************************************************
// Marissa Carson
// CS2 with Terry Hostetler
// Homework 4: Using Recursion To Solve A Maze
// Extra Credit: Finding The Shortest Path
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
};


//Function Prototypes
void GetMaze(/*in*/ifstream &inData, /*out*/MazeType & maze);
void PrintMaze(/*in*/MazeType & maze);
PointType Q(/*in*/PointType p, /*in*/int turn);
bool DLS (/*inout*/PointType &p, /*in*/MazeType &maze, int /*in*/depth); // Depth-limited search (recursive)
bool IDDFS(/*inout*/MazeType &maze); // Iterative deepening depth first search

int main()
{
	ifstream inData("maze.in");
	MazeType maze;
	bool solved;

	GetMaze(inData, maze);

	if (maze.g[0][0] == OPEN /*&& maze.g[maze.NC][maze.NR] == OPEN*/)   
		solved = IDDFS(maze);        // Only attempt to solve the maze if the first and last squares are open
	else
		solved = false;

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

//********************************************************************************

bool DLS (PointType &p, MazeType &maze, int depth)
// Preconditions:  PointType p has the coordinates to an open square on the grid,
//				   maze has a filled grid and correct dimensions NR and NC, 
//				   depth is given. 
// Postconditions: All possible paths of the given depth have been searched. 
//                 If there is a solution at the given depth, pointers connect the
//                 first point to the last. 
{
	bool found = false; 

	if (p.x == maze.NR - 1 && p.y == maze.NC - 1)
	{
		p.next = NULL;
		return true;
	}
	
	else if (depth > 0)
	{
		bool one = true, two = true, three = true, onGrid;

		PointType q = Q(p, 0);                  // 1. Try to continue in direction
		onGrid = (q.x >= 0 && q.x < X_MAX && q.y >= 0 && q.y < Y_MAX);

		if (maze.g[q.x][q.y] == OPEN && onGrid /*&& !q.visited*/)
		{
			found = DLS(q, maze, depth - 1);
			if (found)
				p.next = &q;
		}
		else
			one = false;	

		if (!found)
		{
			q = Q(p, 1);				          // 2. Try turning right
			onGrid = (q.x >= 0 && q.x < X_MAX && q.y >= 0 && q.y < Y_MAX);

			if (maze.g[q.x][q.y] == OPEN && onGrid /*&& !q.visited*/)
			{
				found = DLS(q, maze, depth - 1);
				if (found)
					p.next = &q;
			}
			else
				two = false;

			if (!found)
			{
				q = Q(p, 3);					        // 3. Try turning left
				onGrid = (q.x >= 0 && q.x < X_MAX && q.y >= 0 && q.y < Y_MAX);

				if (maze.g[q.x][q.y] == OPEN && onGrid /*&& !q.visited*/)
				{
					found = DLS(q, maze, depth - 1);
					if (found)
						p.next = &q;
				}
				else
					three = false;

				if (!found)
					if (one == false && two == false && three == false)
						return false;
			}
		}	
	}
	if (found)
		return true;
	else
		return false;
}

//**************************************************************************************

bool IDDFS(MazeType &maze)
// Preconditions:  a maze has been filled with open and wall characters from the input file
//				   and has correct dimensions NR and NC
// Postconditions: either the maze has been solved and the shortest solution path's spaces have 
//				   been marked with letters in order, or the maze cannot be solved. Whether or
//				   not the maze has been solved is returned as true or false. 
{
	int depth = 0;
	bool found = false;
	PointType* first = new PointType;
	first->x = 0;
	first->y = 0;
	first->z = RIGHT;
	first->next = NULL;

	while (!found && depth < (X_MAX * Y_MAX))
	{
		found = DLS(*first, maze, depth);

		depth++;
	}

	if (found)                 // If the maze has been solved,
	{
		PointType* p = first;
		char mark = 'a';               // mark the path with letters

		while (p != NULL)
		{
			maze.g[p->x][p->y] = mark;
			mark++;
			if (mark > 'z')
				mark = 'a';
			p = p->next;
		}
		return true;
	}

	else 
		return false;
}