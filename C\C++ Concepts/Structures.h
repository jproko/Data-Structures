/************************************************************
* Author: Julian Proko										*
* Purpose: Data Structures Labs								*
* Description: Introductory C/C++ concepts (Structures)		*
* Date Created: 13/04/2022									*
* Last Modified: 13/04/2022									*
*************************************************************/

#include <stdio.h>

#ifndef STRUCTURES_H
#define STRUCTURES_H

// Structure Definition
//		Definition does not consume memory, till the
//		time instance it is initialized. Uppon initialization,
//		the size of the structure will be: 4bytes + 4bytes = 8bytes
// Variables:
//		float length
//		float breadth
struct Rectangle
{
	float length;
	float breadth;
};

// This function, will perform the basic functionality
// needed for this lab, on structures. 
void StructureFunctionality();

// This function is responsible for receiving an address of a struct  
// Rectangle and return its size in memory (bytes).
void DisplayRecSize(struct Rectangle* r);

// This function is responsible for receiving an address of a struct  
// Rectangle and return its member values
void DisplayRecMembers(struct Rectangle* r);

// This function is responsible for receiving an address of a struct 
// Rectangle, as well as its associated new desired length, and modify it.
void SetLength(struct Rectangle* r, float l);

// This function is responsible for receiving an address of a struct 
// Rectangle, as well as its associated new desired breadth, and modify it.
void SetBreadth(struct Rectangle* r, float b);
#endif