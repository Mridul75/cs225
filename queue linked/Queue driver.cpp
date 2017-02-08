#include <iostream>

#include "Queue linked.h"
#include <string>

int main()
{
  using namespace std;

  string item;
  QueType<string> q; 

  if (q.IsEmpty()) 
	  cout << "q is empty" << endl;
  else 
	  cout << "q is not empty" << endl;

  q.Enqueue("Scott");
  q.Enqueue("Adam");
  q.Enqueue("Daniel");
  q.Dequeue(item);
  cout << "dequeued item = " << item << endl;
  q.Enqueue("Michael");
  q.Enqueue("Andrew");
  q.Enqueue("Lilly");

  if (q.IsFull()) 
	  cout << "q is full" << endl;
  else 
	  cout << "q is not full" << endl;

  q.Dequeue(item);
  cout << "dequeued item = " << item << endl;
  q.Dequeue(item);
  cout << "dequeued item = " << item << endl;
  q.Enqueue("Sean");
  q.Enqueue("Scott");
  
  if (q.IsFull()) 
	  cout << "q is full" << endl;
  else 
	  cout << "q is not full" << endl;

  while (!q.IsEmpty())
  {
	  q.Dequeue(item);
	  cout << "dequeued item = " << item << endl;
  }

    QueType<float> gpas(32000); 


  return 0;
}




