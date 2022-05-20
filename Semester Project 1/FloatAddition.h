/********************************************************************
* Author: Julian Proko                                              *
* Academic ID: p16119                                               *
* Purpose : (Grade Re - evaluation | Course Re - take               *
*           Data Structures Semester Project 1                      *
* Description : Task 2 - Floating Point Addition                    *
* Due Date : 20 / 05 / 2022                                         *
*********************************************************************/

//Library declaration
#include <stdio.h>
#include <math.h>

// * This header introduces random number generation facilities.
// * https://www.cplusplus.com/reference/random/
#include <random>

#ifndef FLOAT_ADDITION_H
#define FLOAT_ADDITION_H

/*
* FloatAddition class, is the class which performs the necessary
* functionality for floating point addition. For exhibition purposes, 
* it contains a heap of min, as well as a heap of max. The default construct
* (with no parameters), performs the functionality with a fixed 7 sized array,
* whereas the overloaded constructor, (with parameter N), expects an N value where 
* N>=10,000,000, which performs the functionality for an array of N values.  
*/
class FloatAddition
{
	private:
		float* heap_min;
		float* heap_max;
		int heap_size;
		int max_heap_size;
		float totalSum_min;
		float totalSum_max;

		void insertHeapOfMin();
		void insertHeapOfMax();
		void extractFromHeapOfMin();
		void extractFromHeapOfMax();
	public:
		//1. Base Constructor
		FloatAddition();

		//2. Overloaded Constructor
		FloatAddition(int N);

		//3. This function is responsible for creating
		//   in-place (both) heap of min (and heap of max)
		//   from the existing tables.
		void InPlaceHeapCreation();

		//4. This function is responsible for extracting the
		//   root of the heap, adding it to the sum accordingely (whether it is heap of 
		//   mins or heap of max)and re-regulating it (applied in both heaps). 
		void ExtractFromHeap();

		//5. Display Heaps
		void IdentityOfHeaps();
};
#endif
