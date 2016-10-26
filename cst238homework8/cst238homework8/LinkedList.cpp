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
	Node * predPtr = first;
	Node * ptr = first;
	const int size = mySize;
	string substring[1000];
	string tempSubstring;
	bool isThereAnA = false;
	//while (isThereAnA == true) {}
	int i = 0;
	while (ptr != NULL)
	{
		if (ptr->data == 'A')
		{
			isThereAnA = true;
			while (isThereAnA = true)
			{
				cout << "found an A\n";
				predPtr = ptr;
				substring[i] = ptr->data;
				ptr = ptr->next;
			continuingString:
				if (ptr->data != 'B' || ptr->data != NULL)
				{
					substring[i] += ptr->data;
					ptr = ptr->next;
				}
				if (ptr->data == 'B')
				{
					cout << "Found a B\n";
					//gotta check whether this string already exists
					for (int q = 1; q < i; q++)
					{
						if (substring[i] == substring[q])
						{
							//want to start the while loop over
							ptr = ptr->next;
							goto continuingString;
						}
						else
						{
							cout << "Substring " << i << ": " << substring[i] << endl;
						}
					}
				}
				if (ptr->data == NULL)
				{
					substring[i] = "";
					i++;
					ptr = first;
					isThereAnA = false;
					continue;
				}
			}
		}
		else
		{
			ptr = ptr->next;
		}
	}
	return;
}