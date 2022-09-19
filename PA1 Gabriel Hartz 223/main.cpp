#include <iostream>
#include "menu.h"
#include "wrap.h"
#include "linked_list.h"
#include "profileArray.h"

//“ADVANTAGES/DISADVANTAGES LINKED LIST:”. 
//Advantage: Dynamically Resizable
// Linked Lists have their nodes stored in the heap, meaning that it can grow and shrink at runtime,
// this can be seen in this application when the player decides to use option(4) - append an element to the list, or option(5) - remove an element from the list.
// 
//Disadvantage: Less efficient to access elements that are not the head pointer
// Direct access to an element is not possible in a linked list as in an array by index,
// to acess an element you must traverse through every element until you get to the one that your operation is looking for. The only way to get around that is treating the linked list like a stack which results in O(1) operations.
// An example of this situation in this application is the option(5) - to remove an element from the list, the algorithm has to traverse through all the elements that come before the one to be removed.

//“ADVANTAGES / DISADVANTAGES ARRAY : ”.
//Advantage: Efficient to acess elements
//It's possible to acess the elements in an array by their index, resulting in a O(1) time operation.
//An example of that in this application is in option(3) which asks for the variable score of a specific player in the list. 
//
//Disadvantage: Appending an element to the front requires shifting all other elements
//As seen in the function insertAtfront from the profileArray class, the algorithm for inserting at front in an array is extremely inneficient, and requires moving every element to the left so that
// the index(0) is empty for the new element.
//
//
int main()
{
	Wrap test;
	test.initialize();
	return 0;
}