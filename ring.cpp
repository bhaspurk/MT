#include "ring.h"
#include <stdio.h>
#include <thread>
#include <iostream>

using namespace std;

Ring::Ring(int n)
:size(n)
{
	full = false;
	head = tail = 0;
	for(int i=0; i< size; i++)
	{
		buffer.push_back(0);
	}
}

Ring::~Ring()
{
	
}

int Ring::AddToRing(int val)
{
	buffer[head] = val;

	if( (head == tail) && full)
	{
		//move tail
		tail = (tail + 1)%size;
	}

	head = (head+1)%size;
	full = (head==tail);
	
	return 0;
}

int Ring::DeleteFromRing(int &val)
{	
	if( (head == tail) && !full)
		return -1;//empty

	val = buffer[tail];
	tail = (tail +1)%size;
	full = false;		
	return 0;
}

int Ring::Traverse()
{
	//empty
	if(!full && (head == tail))
		return 0;

	//traverse from tail to head
	int tmp = tail;
	do
	{
		cout<<buffer[tmp]<<endl;
		tmp = (tmp + 1)%size;
	}while(tmp != head);

	return 0;
}


int main()
{
	int val_del = 0;
	Ring r(5);
	for(int i=0; i< 15; i++)
		r.AddToRing(i);

	r.DeleteFromRing(val_del);
	r.DeleteFromRing(val_del);
	r.Traverse();
	return 0;
}
