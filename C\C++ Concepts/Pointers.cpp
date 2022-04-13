#include "Pointers.h"

void PointersFunctionality() 
{
	// The first thing we are going to do through this 
	// function, is to create dynamically an array of floats 
	// of len x.
	float* A = CreateArrayOfFloats(3);
	A[0] = 2.5f;
	A[1] = 3.5f;
	A[2] = 4.5f;

	// Pass the address of the newly created dynamic function and 
	// display its values.
	// Tip: An alternative passing argument, would have been:
	//		DisplayArrayOfFloats(A,3)
	DisplayArrayOfFloats(&A[0], 3);

	// Release resources
	free(A);
}

float* CreateArrayOfFloats(int sizeX) 
{
	float* arr;
	arr = (float* )malloc(sizeX * sizeof(float));
	return arr;
}

void DisplayArrayOfFloats(float* arr, int sizeX) 
{
	for (int i = 0; i < sizeX; i++) 
	{
		printf("Element %d of array: %.2f\n",i,arr[i]);
	}
}