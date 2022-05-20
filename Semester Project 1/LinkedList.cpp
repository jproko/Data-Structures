#include "LinkedList.h"

L_List::L_List(int givenMaxCapacity)
{
	// A. Reserve Memory in Heap 
	L_Node* node = new L_Node();

	// B. Associate node with head as well as tail
	head = node;
	tail = node;
	
	// C. Initialize Value Cardinality : How many elements are stored
	// in our linked list.
	valueCardinality = 0;

	// D. Initialize the maximum capacity of the linked list
	//     We demand that: 
	//         given that our List is initialized with 1 empty node, 
	//         maximum capacity can not be < 1. Therefore we demand our list to have
	//         (at least 0 to 1 values) AND (at least 1 node)
	if (givenMaxCapacity >= 1)
	{
		maxCapacity = givenMaxCapacity;
	}
	else
	{
		maxCapacity = 1;
	}
}

L_List::~L_List()
{
	// We will make use of a helper pointer to
	// iteratively perform all the necessary functionality
	L_Node* helper = 0;

	// A. Initialization Process
	//    Helper pointer will help us review if there is some next
	//    node which we will have to erase
	//        We first associate helper pointer to point to the next of 
	//        the head.
	helper = head->next;

	// B. Iteration Process
	while (helper)
	{
		// 1. Delete Memory of head Node.
		delete head;
		// 2. Make head to point where helper points
		//        This actually indicates that we iteratively delete the head node
		head = helper;
		// 3. Make helper point to the next node
		helper = head->next;
		// 4. Decrease value cardinality by 1
		valueCardinality--;
	}

	// C. Delete last remaining node
	//    Up untill this process, all nodes have successfully been deleted, except 
	//    head node. Therefore, we delete Head Node.
	// 1. Delete Memory of node
	delete head;
	// 2. Make head point to nothing
	head = 0;
	tail = 0;
}

void L_List::Insert(int x_value)
{
	if (valueCardinality == 0) 
	{
		head->data = x_value;
		valueCardinality++;
		return;
	}
	
	if ((valueCardinality == maxCapacity) && (maxCapacity == 1))
	{
		head->data = x_value;
		return;
	}

	if (valueCardinality == maxCapacity) 
	{
		this->ExtractHead();
	}

	L_Node* node = new L_Node();
	node->data = x_value;
	tail->next = node;
	tail = node;
	valueCardinality++;
}

void L_List::ExtractHead()
{
	// This function can be exclusively invoked iff our list has at least k>=2 nodes.
	// Use of helper variable pointing to second Node in the list
	L_Node* helper = head->next;
	// Release Heap-Memory of Head Node
	delete head;
	// Re-instate head to point to (previously) second node in the list
	head = helper;
	// Decrease value cardinality by 1
	valueCardinality--;
	return;
}

void L_List::ListIdentity()
{
	printf("L:");
	L_Node* k = head;
	while (k)
	{
		printf("%d, ", k->data);
		k = k->next;
	}
	printf("\n------------------------------\n");
}
