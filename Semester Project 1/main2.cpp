#include "FloatAddition.h"

int main()
{
	//FloatAddition obj;
	//obj.IdentityOfHeaps();
	//obj.InPlaceHeapCreation();
	//obj.IdentityOfHeaps();
	//obj.ExtractFromHeap();
	//obj.IdentityOfHeaps();

	FloatAddition obj2(100000000);
	obj2.IdentityOfHeaps();
	obj2.InPlaceHeapCreation();
	obj2.IdentityOfHeaps();
	obj2.ExtractFromHeap();
	obj2.IdentityOfHeaps();

}
