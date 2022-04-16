/************************************************************
* Author: Julian Proko										*
* Purpose: Data Structures Labs								*
* Description: Introductory C/C++ concepts (Class)			*
* Date Created: 15/04/2022									*
* Last Modified: 16/04/2022									*
*************************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifndef CLASS_H
#define CLASS_H

// This function is responsible for performing the necessary tasks to display 
// the desired class functionality. 
void ClassFunctionality();

// Rectangluar class declaration
class Rectangular 
{
	// Private data members
	private:
		float length;
		float breadth;

	// Public functionality
	public:
		// Base Default - Constructor
		Rectangular();

		// Overloaded - Constructor
		Rectangular(float length, float breadth);

		// Return the surface area of the rectangle
		float Area(){return length * breadth;}

		// Return the perimeter of the rectangle
		float Perimeter(){return 2 * (length + breadth);}

		// Setters
		void setLength(float length) { this->length = length; }

		void setBreadth(float breadth) { this->breadth = breadth; }

		// Getters
		float getLength() { return length; }

		float getBreadth() { return breadth; }

		// Destructor
		~Rectangular(){printf("Dealocating class memory of object: %.2f, %.2f\n",length,breadth);}
};
#endif