#include <iostream>

using namespace std ;


void enqueue ( char queue[], int& in, int& full )
{
	// If queue count is four then the program will say it's full...
	if (full==4)
	{
		cout << endl << "Queue is full." << endl;
	}
	else
	{
		// Read value into empty array slot
		cout << "Enqueue: ";
		cin >> queue[in];

		// Circular array, we are at the end, so move to beginning
		if(in==3)
		{
			in=0;
		}
		else
		{
			// Move to next open space in queue
			in++;
		}

		// Increase queue count
		full++;
	}
}

void dequeue ( char queue[], int& out, int& in, int& full )
{
	// If there is nothing in the queue...
	if (full==0)
	{
		cout << endl << "Queue is empty." << endl;
	}
	else
	{
		// If we are at end of circular array move to beginning
		if (out==3)
		{
			out=0;
		}
		else
		{
			out++;
		}

		// Decrease size of queue
		full--;
	}
}

void display ( char queue[], int& full, int& out, int& in)
{
	int cursor = out;
	for(int i = 0; i < full; i++)
	{
		cout << queue[cursor] << " ";
		cursor = (cursor == 3) ? 0 : cursor + 1;
	}

	cout << endl;
}


main ()
{
	char prompt ;
	char mainqueue[4] ;
	
	int E=0, D=0, F=0, empt=0;
	cout << endl ;
	cout << "Enter e to enqueue, d to dequeue or q to quit." ;
	cout << endl << endl << "e, d or q: " ;

	cin >> prompt ;
	while ( ( prompt == 'e' ) || ( prompt == 'd' ) )
	{
		switch ( prompt )
		{
			case 'e' : enqueue ( mainqueue, E, F ) ;
				break ;
			case 'd' : dequeue ( mainqueue, D, E, F ) ;
				break ;
		}
		display ( mainqueue, F, D, E);
		cout << "e, d or q: " ;
		cin >> prompt ;
	}
}

