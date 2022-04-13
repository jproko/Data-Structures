#include "Structures.h"

void StructureFunctionality()
{
	// Structure declaration : visible inside the scope of StructureFunctionality scope
	struct Rectangle r1;

	// Structure initialization
	r1 = { 10.5f, 5.5f };

	// Size of Structure
	// Passing as parameter address value of r1
	// Result is being consisted of the size of members of the structure
	DisplayRecSize(&r1);

	// Structure Members
	DisplayRecMembers(&r1);

	// Modify Structure Members
	SetLength(&r1, 8.5f);
	SetBreadth(&r1, 4.2f);

	// Display new Structure Members
	DisplayRecMembers(&r1);


}

void DisplayRecSize(struct Rectangle* r) 
{
	printf("Size of the given Rec Structure is: %lu bytes.\n",sizeof(*r));
}

void DisplayRecMembers(struct Rectangle* r) 
{
	// r -> member : (*r).member
	printf("Length:%.2f\n",r->length);
	printf("Breadth:%.2f\n", r->breadth);
}

void SetLength(struct Rectangle* r, float l) 
{
	r->length = l;
}

void SetBreadth(struct Rectangle* r, float b) 
{
	r->breadth = b;
}