//Erik Ring-Walters
//10/26/2016
//Homework 8 CST - 238
//Linked List Homework
//A to B substring recorder
//ID: 00248407
#include <iostream>
using namespace std;
#include "LinkedList.h"

int main()
{
	LinkedList a;
	string textString;
	cout << "Please enter a text string: \n";
	cin >> textString;
	for (int i = 0; i < textString.length(); i++)
	{
		a.insert(textString[i], i);
	}
	a.checkSubstrings();
}