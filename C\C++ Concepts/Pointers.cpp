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

	// Create a 2-D array of floats and swap their values
	// Create a 2-D array
	printf("Swap Functionality\n");
	float* B = CreateArrayOfFloats(2);
	B[0] = 1.0f;
	B[1] = 2.0f;

	// Display Array Values
	printf("Original array.\n");
	DisplayArrayOfFloats(B, 2);

	//Swap values
	SwapFloatValues(&B[0], &B[1]);

	// Display Swapped Array Values
	printf("Swapped array.\n");
	DisplayArrayOfFloats(B, 2);


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

void SwapFloatValues(float* a, float* b) 
{
	// temp value is = [value] of [float - address] b
	float tempValue = *b;
	
	//[value] of [float - address] b is = [value] of [float - address] a
	*b = *a;

	//[value] of [float - address] a is = temp value
	*a = tempValue;
}