/************************************************************
* Author: Julian Proko										*
* Purpose: Data Structures Labs								*
* Description: Introductory C/C++ concepts (Pointers)		*
* Date Created: 13/04/2022									*
* Last Modified: 15/04/2022									*
*************************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifndef POINTERS_H
#define POINTERS_H

// This function is responsible for main pointers functionality
// exhibition.
void PointersFunctionality();

// This function is responsible for creating dynamically, at runTime,
// an array of floats, of length sizeX, and return it to the invoker.
float* CreateArrayOfFloats(int sizeX);

// This function is responsible for displaying an array of floats, 
// of length sizeX.
void DisplayArrayOfFloats(float* arr, int sizeX);

// This function is responsible for swapping 2 floats a and b.
// Therefore if a = 10 and b = 5, this function will make:
// a = 5 and b = 10.
void SwapFloatValues(float* a, float* b);

#endif