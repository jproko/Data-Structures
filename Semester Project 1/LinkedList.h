/********************************************************************
* Author: Julian Proko                                              *
* Academic ID: p16119                                               *
* Purpose : (Grade Re - evaluation | Course Re - take               *
*           Data Structures Semester Project 1                      *
* Description : Task 1 - Histogram Creation                         *
* Due Date : 20 / 05 / 2022                                         *
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
/*
* This class is responsible for representing the node of
* the main Linked List H. It contains:
*		1. integer data
*		2. pointer address to the next L_Node in the Linked List L.
*/
class L_Node
{
	// Allow data member access by L_List
	friend class L_List;
private:
	int data;
	L_Node* next;
};

/*
* This class is responsible for representing the main
* Linked List L. It contains all the necessary functionality
* declaration for the desired performance.
*/
class L_List
{
private:
	L_Node* head;
	L_Node* tail;
	int valueCardinality;
	int maxCapacity;

	void ExtractHead();
public:
	// 1. Constructor
	L_List(int givenMaxCapacity);

	// 2. Destructor
	~L_List();

	// 3. Insert (Irrelevant Order) to the end
	void Insert(int x_value);

	// 4. Display List
	void ListIdentity();
};
#endif