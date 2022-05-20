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

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

/*
* This class is responsible for representing the node of 
* the histogram Linked List H. It contains:
*		1. integer data
*		2. cardinality of data in the L_List
*		3. pointer address to the next H_Node in the Linked List H.
*/
class H_Node
{
	// Allow data member access by H_List
	friend class H_List;
	private:
		int data;
		int dataCardinality;
		H_Node* next;
};

/*
* This class is responsible for representing the histogram 
* Linked List H. It contains all the necessary functionality
* declaration for the desired performance. 
*/
class H_List 
{
	private:
		H_Node* head;
		int valueCardinality;
		int maxCapacity;

		void ExtractHead();
		void insertSc0(int x_value);
		void insertSc1(int x_value);
		void insertSc2(int x_value);
		void insertSc3(int x_value);
	public:
		// 1. Constructor
		H_List(int givenMaxCapacity);
		
		// 2. Destructor
		~H_List();

		// 3. Insert in Ascending Order
		void InsertAscend(int x_value);

		// 4. Display List
		void ListIdentity();
};
#endif
