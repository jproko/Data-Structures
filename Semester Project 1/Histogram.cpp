#include "Histogram.h"

H_List::H_List(int givenMaxCapacity) 
{
	printf("Constructor of H Linked List invoked.\n");
	// A. Reserve Memory in Heap 
	H_Node* node = new H_Node();

	// B. Associate node with head
	head = node;
	head->dataCardinality = 0;
	
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
		printf("Succesfull Creation of Linked List with MAX_CAPACITY = %d.\n",maxCapacity);
		printf("------------------------------\n");
	}
	else 
	{
		printf("The maximum capacity of the list should be >=1.\n");
		printf("Succesfull Creation of Linked List with MAX_CAPACITY = 1.\n");
		printf("------------------------------\n");
		maxCapacity = 1;
	}
}

H_List::~H_List() 
{
	printf("Destructor of H Linked List invoked.\n");
	// We will make use of a helper pointer to
	// iteratively perform all the necessary functionality
	H_Node* helper = 0;
	
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
	printf("Destructor Terminated.\n");
	printf("------------------------------\n");

}

void H_List::InsertAscend(int x_value) 
{
	printf("Insertion of %d value in ascending order invoked.\n",x_value);
	// We must cover 4 Main Scenarios (which will be further diversified uppon expansion)
	
	// Scenario 0: Initialize the first node with value
	//     Invoked when valueCardinality == 0 -> meaning its the first value to be ever inserted
	if (valueCardinality == 0) 
	{
		insertSc0(x_value);
		printf("Value Insertion Terminated.\n");
		printf("------------------------------\n");
		return;
	}

	// Scenario 1: Max Cardinality ==1
	//     Invoked when we are able to store at most 1 histogram element
	if (maxCapacity == 1) 
	{
		insertSc1(x_value);
		printf("Value Insertion Terminated.\n");
		printf("------------------------------\n");
		return;
	}

	// Scenario 2: Main Scenario, valueCardinality < maxCardinality
	//     Invoked when we are able to insert or update any given x value without worrying about capacity
	if (valueCardinality < maxCapacity) 
	{
		insertSc2(x_value);
		printf("Value Insertion Terminated.\n");
		printf("------------------------------\n");
		return;
	}

	// Scenario 3: valueCardinality == maxCardinality (both>1)
	if (valueCardinality==maxCapacity) 
	{
		insertSc3(x_value);
		printf("Value Insertion Terminated.\n");
		printf("------------------------------\n");
		return;
	}
	
}

void H_List::ExtractHead()
{
	// This function can be exclusively invoked iff our list has at least k>=2 nodes.
	printf("Extract Head Invoked.\n");

	// Use of helper variable pointing to second Node in the list
	H_Node* helper = head->next;
	// Release Heap-Memory of Head Node
	printf("Head node of value: %d, and data cardinality:%d will be deleted.\n", head->data, head->dataCardinality);
	delete head;
	// Re-instate head to point to (previously) second node in the list
	head = helper;
	printf("New head node, node with value: %d\n", head->data);
	// Decrease value cardinality by 1
	valueCardinality--;
	return;
}

void H_List::insertSc0(int x_value) 
{
	printf("Scenario 0 invoked.\n");
	printf("Initialization of first node of the histogram list.\n");
	head->data = x_value;
	head->dataCardinality = 1;
	valueCardinality++;
	return;
}

void H_List::insertSc1(int x_value)
{
	printf("Scenario 1 invoked.\n");
	printf("Max capacity/cardinality of list equals to 1.\n");

	if (head->data == x_value) 
	{
		head->dataCardinality ++;
		printf("Already seen value.\n");
		printf("Data cardinality of head node increased by 1.\n");
	}
	else 
	{
		head->data = x_value;
		head->dataCardinality = 1;
		printf("New value.\n");
		printf("Re-initialization of head node.\n");
	}
	return;
}

void H_List::insertSc2(int x_value)
{
	printf("Scenario 2 invoked.\n");
	printf("Value cardinality of list < Max capacity/cardinality.\n");
	// We can review 2 main insertion scenarios:
	//     A. Insertion before the head
	//     B. Insertion after any given existing node
	// Furthemore we have to take care of the possibility that our value already exists

	// We are going to make use of 2 additional pointers:
	// Helper pointer will serve as index of node currently traversing
	// Following pointer will serve as index to the previously traversed node

	// Initialization
	H_Node* helper = head;
	H_Node* following =0 ;

	// Main traverse
	//     while there exists a node where our helper pointer points at
	//     as well as its value is < to our x_value -> traverse
	while ((helper) && (helper->data < x_value)) 
	{
		following = helper;
		helper = helper->next;
	}

	// At this point, there are 2 possibilities
	// 1. Either our helper->data >= x_value
	// 2. Or our helper pointer points at nothing

	// Subcase 1. : Our helper->data > x_value
	//     This indicates that:
	//         a. Either, we have to insert a new node before head
	//         b. or, we have to insert a new node before helper
	// Subcase 2. : Our helper->data == x_value
	//     This indicates that we have to update the dataCardinality 
	//     of node pointed by helper pointer

	// Subcase 2.
	if ((helper)&&(helper->data == x_value)) 
	{
		helper->dataCardinality++;
		printf("Already seen value.\n");
		printf("Data cardinality of node containing data: %d increased by 1.\n", helper->data);
		return;
	}

	// Subcase 1.a.
	if (helper == head) 
	{
		H_Node* node = new H_Node();
		node->data = x_value;
		node->dataCardinality = 1;
		node->next = head;
		head = node;
		valueCardinality++;
		printf("New value.\n");
		printf("A new node containing data: %d, is re-instated as head node.\n", head->data);
		return;
	}
	else 
	{
		// Subcase 1.b.
		H_Node* node = new H_Node();
		node->data = x_value;
		node->dataCardinality = 1;
		node->next = helper;
		following->next = node;
		valueCardinality++;
		printf("New value.\n");
		printf("A new node containing data: %d, is entered after exisitng node containing data: %d.\n", node->data, following->data);
		return;
	}
}

void H_List::insertSc3(int x_value)
{
	printf("Scenario 3 invoked.\n");
	printf("Value cardinality of list = Max capacity/cardinality (both >1).\n");

	// First, we have to review whether or not the given value already exists, therefore
	// the fact that valueCardinality == maxCardinality is not an issue 

	H_Node* helper = head;
	while (helper) 
	{
		if (helper->data == x_value) 
		{
			helper->dataCardinality++;
			printf("Already seen value.\n");
			printf("Data cardinality of node containing data: %d increased by 1.\n", helper->data);
			return;
		}
		helper = helper->next;
	}

	printf("New value.\n");
	printf("Head node must be deleted and the insertion process will re-start with the given value: %d", x_value);
	// Given that we have checked all our existing nodes and there is no update to be performed,
	// we chose to delete the first value in an F.I.F.O. - alike matter, and then insert the given
	// value via the use of Scenario 2 insertion
	ExtractHead();
	insertSc2(x_value);
	return;
}

void H_List::ListIdentity() 
{
	printf("Display List Identity invoked.\n");
	printf("H:");
	H_Node* k = head;
	while (k)
	{
		printf("(Data: %d, Cardinality: %d), ", k->data, k->dataCardinality);
		k = k->next;
	}
	printf("\n------------------------------\n");
}