//----- LinkedList.h -----
#ifndef LINKEDLIST
#define LINKEDLIST
#include <string>
//Erik Ring-Walters
//10/26/2016
//Homework 8 CST - 238
//Linked List Homework
//A to B substring recorder
//ID: 00248407
#include <iostream>
using namespace std;

typedef int ElementType;

class LinkedList
{
public:
	LinkedList();   // constructor
	~LinkedList();  // destructor
	LinkedList(const LinkedList & original); //copy constructor
	void insert(ElementType item, int pos);
	void erase(ElementType item);
	void traverse();
	void LinkedList::checkSubstrings();
	void display(ostream & out) const;
	/*--------------------------------------------------------------------
	Display the contensts of this LinkedList.
	Precondition: ostream out is open
	Postcondition: Elements of this LinkedList have been output to out.
	--------------------------------------------------------------------*/

private:
	class Node
	{
	public:
		ElementType data;
		Node * next;
		//------ Node OPERATIONS
		//-- Default constrctor: initializes next member to
		Node()
			: next(NULL)
		{ }
		//-- Explicit-value constructor: initializes data member to dataValue
		//-- and next member to 0
		Node(ElementType dataValue)
			: data(dataValue), next(NULL)
		{ }
	};
	Node * first;
	int mySize;
};

#endif#pragma once
