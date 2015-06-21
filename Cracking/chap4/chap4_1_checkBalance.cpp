/*
* Implement a function to check if a tree is balanced. For the purposes of this question, 
* a balanced tree is defined to be a tree such that no two leaf nodes differ in distance 
* from the root by more than one.
*/

#include <iostream>
#include "BinarySearchTree.h"

void checkBalance(BinarySearchTree &BST){
	std::vector<int> depth;
	BST.getAllDepth(BST.root, 0, depth);
	int max = 0, min = depth[0];
	for (int i = 0; i != depth.size(); i++){
		max = (max < depth[i]) ? depth[i] : max;
		min = (depth[i] < min) ? depth[i] : min;
	}
	std::cout << "Min is:" << min << ", Max is: " << max << std::endl;
	if (max - min >= 2)
		std::cout << "BST is unblanced." << std::endl;
	else
		std::cout << "BST is balanced." << std::endl;
	return;
}

int main()
{
	BinarySearchTree BST;
	BST.insert(5); BST.insert(7); BST.insert(6);
	BST.insert(4); BST.insert(3); BST.insert(2);
	BST.insert(1); BST.insert(8);
	BST.print_as_sideways_tree();
	//BST.getHeight();
	checkBalance(BST);

	return EXIT_SUCCESS;
}

