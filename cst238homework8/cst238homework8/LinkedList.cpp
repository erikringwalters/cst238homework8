//Erik Ring-Walters
//10/26/2016
//Homework 8 CST - 238
//Linked List Homework
//A to B substring recorder
//ID: 00248407
#include <iostream>
using namespace std;

#include "LinkedList.h"

//-- Default constructor
LinkedList::LinkedList()
{
	mySize = 0;
	first = NULL;
}

//-- Definition of the copy constructor
LinkedList::LinkedList(const LinkedList & origList)
{
	mySize = origList.mySize;
	first = NULL;

	if (mySize == 0)
		return;

	Node * origPtr, *lastPtr;
	first = new Node(origList.first->data); // copy first node
	lastPtr = first;
	origPtr = origList.first->next;
	while (origPtr != NULL)
	{
		lastPtr->next = new Node(origPtr->data);
		origPtr = origPtr->next;
		lastPtr = lastPtr->next;
	}
}


//-- Definition of the destructor
LinkedList::~LinkedList()
{
	Node * prev = first;
	Node * ptr;

	while (prev != NULL)
	{
		ptr = prev->next;
		delete prev;
		prev = ptr;
	}
}

// Traverse the LinkedList and process data in each node
void LinkedList::traverse()
{
	Node * ptr = first;
	ElementType sum = 0;

	while (ptr != NULL)
	{
		// Process part of data
		// For example find sum of all data.
		sum += ptr->data;
		ptr = ptr->next;
	}
	return;
}


//-- Definition of insert()
void LinkedList::insert(ElementType dataVal, int index)
{
	if (index < 0 || index > mySize)
	{
		cerr << "Illegal location to insert -- " << index << endl;
		return;
	}

	mySize++;
	Node * newPtr = new Node(dataVal);
	Node * predPtr = first;
	if (index == 0)
	{
		newPtr->next = first;
		first = newPtr;
	}
	else
	{
		for (int i = 1; i < index; i++)
			predPtr = predPtr->next;
		newPtr->next = predPtr->next;
		predPtr->next = newPtr;
	}
}


//-- Definition of erase()
void LinkedList::erase(int index)
{
	if (index < 0 || index >= mySize)
	{
		cerr << "Illegal location to delete -- " << index << endl;
		return;
	}

	mySize--;
	Node * ptr;
	Node * predPtr = first;
	if (index == 0)
	{
		ptr = first;
		first = ptr->next;
		delete ptr;
	}
	else
	{
		for (int i = 1; i < index; i++)
			predPtr = predPtr->next;
		ptr = predPtr->next;
		predPtr->next = ptr->next;
		delete ptr;
	}
}



//-- Definition of display()
void LinkedList::display(ostream & out) const
{
	Node * ptr = first;
	while (ptr != 0)
	{
		out << char(ptr->data);
		ptr = ptr->next;
	}
}

//-- Definition of checkSubstrings()
void LinkedList::checkSubstrings()
{
	Node * aPtr = first;//this pointer is used for holding an A's position
	Node * bPtr = first;//This is used for holding a B's position
	Node * cPtr = first;//This is used to add the characters to the substring once a valid substring is found
	const int CAPACITY = 1000;//just to be safe
	string substring[CAPACITY] = { "" };
	int i = 0;//increases substring[i];
	while (aPtr != NULL)
	{
		if (aPtr->data == 'A')
		{
			bPtr = aPtr;//Once an A is found, the B pointer is put int the same position as A
			while (bPtr != NULL)//until its out of bounds
			{			
				if (bPtr->data == 'B')//Until it finds a B
				{
					for (cPtr = aPtr; cPtr != bPtr->next; cPtr = cPtr->next)//<3
						//So the recorder pointer (cPtr) starts where the A is and goes until it reaches where the B is.
					{
						substring[i] += cPtr->data;//adds the data (character) to the substring[i]
					}
					i++;//once this ^^^ substring is complete, starts a new one using i
				}
				bPtr = bPtr->next;//bPtr increases in order to find any other B's
			}
		}
		aPtr = aPtr->next;//A's pointer increases once it knows there are no more B's to find.
	}
	for (int q = 0; q < i; q++)
	{
		cout << "Substring " << q+1 << ": " << substring[q] << endl;//prints out all substrings.
	}
	cout << "Total substrings: " << i << endl;
	return;
	
}