/************************************************************
* Author: Julian Proko										*
* Purpose: Data Structures Labs								*
* Description: Introductory C/C++ concepts (Pointers)		*
* Date Created: 13/04/2022									*
* Last Modified: 13/04/2022									*
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

// Display an array of floats, of length sizeX.
void DisplayArrayOfFloats(float* arr, int sizeX);
#endif