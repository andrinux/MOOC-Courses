/*
* **********************L C A Problem**********************************
* Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. 
* Avoid storing additional nodes in a data structure. 
* NOTE: This is not necessarily a binary search tree.
*/

//Use an array to generate a minimal height Tree. Input given is the node pointer of root.
#include <iostream>
#include "BinaryTree.h"

#define BSTree 0
#define BTree 1

Node *findLCA_BST(Node *root, Node *p1, Node* p2);
Node *findLCA_BT(Node *root, Node *p1, Node* p2);
Node *findLCA_BT_2(Node *root, Node *p1, Node* p2);

Node* ArrayToTree(int a[], Node * parent, int start, int end){
	//base case.
	if (start > end)
		return NULL;
	BinaryTree * BST = new BinaryTree();
	int mid = (start + end) / 2;
	//general case
	BST->root = new Node(a[mid]);
	BST->root->parent = parent;
	BST->root->left = ArrayToTree(a, BST->root, start, mid - 1);
	BST->root->right = ArrayToTree(a, BST->root, mid + 1, end);
	return BST->root;
}

//Do an in order DFS.
Node * findNode(Node * p, int val){
	Node * res =  NULL;
	if (p == NULL)
		return NULL;
	if (p->data == val){
		return p;
	}
	if (p->left){
		if (res = findNode(p->left, val))
			return res;
	}
	if (p->right){
		if (res = findNode(p->right, val))
			return res;
	}
	return NULL;
}


//FInd the LCA of two nodes
//type=0: BST     ; type=1, ordinary Binary tree
Node * findLCA(Node * root, int v1, int v2, int type){
	//Find location of v1, v2
	Node *p1, *p2;
	Node * res;
	p1 = findNode(root, v1);
	p2 = findNode(root, v2);
	std::cout << p1->data << ", " << p2->data << std::endl;
	//Find the LCA:
	if (type == 0)
		res = findLCA_BST(root, p1, p2);
	else
		res =  findLCA_BT_2(root, p1, p2);
	if (res != NULL)
		std::cout << "LCA is: " << res->data << std::endl;
	return res;
}

//For Binary Search Tree
//Comment: a long boolean euqation is not good, try to change it.
Node *findLCA_BST(Node *root, Node *p1, Node* p2){
	Node *p = root;
	if (root ==NULL ||p1 == NULL || p2 == NULL){
		return NULL;
	}
	Node *big, *small;
	if (p1->data > p2->data){
		big = p1; small = p2;
	}
	else{
		big = p2; small = p1;
	}
	//p should be between p1, p2. Note that p may be == big.
	while (!(p->data > small->data && p->data <= big->data)){
		if (p->data > big->data)
			p = p->left;
		if (p->data < small->data)
			p = p->right;
	}
	return p;
		
}

//For ordinary Binary Tree LCA.
//Cannot use extra data structs to store something.
//parent node or not?
Node *findLCA_BT(Node *root, Node *p1, Node* p2){
	//base cases
	if (root == NULL || p1 == NULL || p2 == NULL){
		return NULL;
	}
	if (root == p1 || root == p2)
		return root;
	//general cases
	Node *p = root;
	Node *left = findLCA_BT(p->left, p1, p2);
	Node * right = findLCA_BT(p->right, p1, p2);

	if (left != NULL && right != NULL)
		return p;
	else if (left != NULL)
		return left;
	else if (right != NULL)
		return right;
	else
		return NULL;

}

//Check if p is p2's parent.
bool isParent(Node *p, Node *p2){
	if (p == NULL || p2 == NULL)
		return false;
	if (p == p2)
		return true;
	if (p->left)
		if (isParent(p->left, p2))
			return true;
	if (p->right)
		if (isParent(p->right, p2))
			return true;
	return false;
}

//Method-2: for each level parent of p1, check for p2
Node *findLCA_BT_2(Node *root, Node *p1, Node* p2){
	if (root == NULL || p1 == NULL || p2 == NULL){
		return NULL;
	}
	if (root == p1 || root == p2)
		return root;
	Node * p = p1;
	while (p != root){
		if (isParent(p, p2))
			return p;
		else
			p = p->parent;
	}

	return root;

}

int main()
{
	int data[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	BinaryTree myTree;
	myTree.root = ArrayToTree(data, NULL, 0, 14);
	myTree.print();

	int src[15] = { 4, 5, 7, 3, 1, 2, 14, 11, 10, 9, 8, 15, 6, 12, 13 };
	BinaryTree newTree;
	newTree.root = ArrayToTree(src, NULL, 0, 14);
	newTree.print();

	//test cases:
	findLCA(myTree.root, 5, 2, BSTree);
	findLCA(newTree.root, 4, 14, BTree);


	return 0;
}