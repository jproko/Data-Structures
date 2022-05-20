#include "FloatAddition.h"

FloatAddition::FloatAddition() 
{
	printf("Base constructor of FloatAddition Class invoked.\n");
	// Fixed heap of mins and heap of max-es initialization for 
	// exhibition purposes.

	// Dynamically allocate memory
	heap_min = new float[7];
	heap_max = new float[7];

	heap_min[0] = 5.4678f;
	heap_max[0] = 5.4678f;
	//---------------------
	heap_min[1] = 4.58734f;
	heap_max[1] = 4.58734f;
	//---------------------
	heap_min[2] = 1.6973f;
	heap_max[2] = 1.6973f;
	//---------------------
	heap_min[3] = 9.13458f;
	heap_max[3] = 9.13458f;
	//---------------------
	heap_min[4] = 2.731985f;
	heap_max[4] = 2.731985f;
	//---------------------
	heap_min[5] = 3.168537f;
	heap_max[5] = 3.168537f;
	//---------------------
	heap_min[6] = 7.28569f;
	heap_max[6] = 7.28569f;
	//---------------------
	heap_size = 1;
	max_heap_size = 7;
	totalSum_min = 0.0f;
	totalSum_max = 0.0f;
	printf("Base constructor of FloatAddition Class terminated.\n");
	printf("----------------------------\n");
}
FloatAddition::FloatAddition(int N)
{
	printf("Overloaded constructor of FloatAddition Class invoked.\n");
	heap_min = new float[N];
	heap_max = new float[N];
	// A random number generator that produces non-deterministic random numbers, if supported.
	// Unlike the other standard generators, this is not meant to be an engine that generates pseudo - random numbers, 
	// but a generator based on stochastic processes to generate a sequence of uniformly distributed random numbers.
	// https://www.cplusplus.com/reference/random/random_device/
	std::random_device randomDevice;

	// This is a random number engine class that generates pseudo-random numbers.
	// It is the library implemention's selection of a generator that provides at least acceptable 
	// engine behavior for relatively casual, inexpert, and/or lightweight use.
	// https://www.cplusplus.com/reference/random/default_random_engine/
	std::default_random_engine randomEngine(randomDevice());

	// This distribution (also know as rectangular distribution) produces random numbers in a range [a,b) 
	// where all intervals of the same length within it are equally probable.
	// https://www.cplusplus.com/reference/random/uniform_real_distribution/
	std::uniform_real_distribution<> rectangularDistribution(0, 50);

	for (int i = 0; i < N; i++) 
	{
		float number = rectangularDistribution(randomEngine);
		heap_min[i] = number;
		heap_max[i] = number;
	}
	heap_size = 1;
	max_heap_size = N;
	totalSum_min = 0.0f;
	totalSum_max = 0.0f;
	printf("Overloaded constructor of FloatAddition Class terminated.\n");
	printf("----------------------------\n");
}
void FloatAddition::InPlaceHeapCreation() 
{
	// The main logic behind this functionality is the itterative process
	// of considering left part of an array as acceptable heap and right
	// part of an array as raw data. Therefore, by iteratively inserting 
	// 1 element of raw part into heap, we make any given array a heap of min or
	// heap of max (accordingely).
	while (heap_size < max_heap_size) 
	{
		heap_size++;
		this->insertHeapOfMin();
		this->insertHeapOfMax();
	}
}
void FloatAddition::insertHeapOfMin()
{
	float temp = heap_min[heap_size-1];
	int i = heap_size-1;
	int parent = ceilf((float)i / 2)-1;
	while (heap_min[parent] > temp && parent>=0) 
	{
		heap_min[i] = heap_min[parent];
		i = parent;
		parent = ceilf((float)i / 2) - 1;
	}
	heap_min[i] = temp;
}
void FloatAddition::insertHeapOfMax()
{
	float temp = heap_max[heap_size - 1];
	int i = heap_size - 1;
	int parent = ceilf((float)i / 2) - 1;
	while (heap_max[parent] < temp && parent >=0)
	{
		heap_max[i] = heap_max[parent];
		i = parent;
		parent = ceilf((float)i / 2) - 1;
	}
	heap_max[i] = temp;
}
void FloatAddition::ExtractFromHeap() 
{
	printf("Complete addition process invoked.\n");
	while (this->heap_size>0) 
	{
		this->extractFromHeapOfMin();
		this->extractFromHeapOfMax();
		heap_size--;
		//printf("(sum_min: %f, sum_max: %f),\n",totalSum_min, totalSum_max);
	}
	printf("\nComplete addition process terminated.\n");
	printf("----------------------------\n");
}
void FloatAddition::extractFromHeapOfMin()
{
	totalSum_min += heap_min[0];
	heap_min[0] = heap_min[heap_size - 1];
	heap_min[heap_size - 1] = 0;
	int i = 0;
	int child = 2 * i + 1;
	while (child < (heap_size - 1) - 1)
	{
		if (heap_min[child] > heap_min[child + 1])
		{
			child++;
		}
		if (heap_min[i] > heap_min[child])
		{
			float helper = heap_min[i];
			heap_min[i] = heap_min[child];
			heap_min[child] = helper;
			i = child;
			child = 2 * i + 1;
		}
		else 
		{
			break;
		}
	}

}
void FloatAddition::extractFromHeapOfMax()
{
	totalSum_max += heap_max[0];
	heap_max[0] = heap_max[heap_size - 1];
	heap_max[heap_size - 1] = 0;
	int i = 0;
	int child = 2 * i + 1;
	while (child < (heap_size - 1) - 1)
	{
		if (heap_max[child] < heap_max[child + 1])
		{
			child++;
		}
		if (heap_max[i] < heap_max[child])
		{
			float helper = heap_max[i];
			heap_max[i] = heap_max[child];
			heap_max[child] = helper;
			i = child;
			child = 2 * i + 1;
		}
		else
		{
			break;
		}
	}

}
void FloatAddition::IdentityOfHeaps() 
{
	printf("Size of both heaps equals: %d\n",heap_size);
	
	//printf("\nDisplay heap of minimums\n");
	//printf("Heap_min:");
	//for (int i = 0; i < heap_size; i++) 
	//{
		//printf("%f, ", heap_min[i]);
	//}
	//printf("\nDisplay heap of maximums\n");
	//printf("Heap_max:");
	//for (int i = 0; i < heap_size; i++)
	//{
		//printf("%f, ", heap_max[i]);
	//}
	printf("\n\nTotal sum of heap of minimums:%f\n",totalSum_min);
	printf("\nTotal sum of heap of maximums:%f\n", totalSum_max);
	printf("\n----------------------------\n");
}