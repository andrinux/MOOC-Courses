/*
* Write code to partition a linked list around a value x, 
* such that all nodes less than x come before all nodes greater than or equal to x.
*/

#include <iostream>
#include "myList.h"
#include <vector>
//Question: x is unique?
void appendTo(Node*& head, Node*& cur);

//Version-1: Space O(n), time O(2n)[because of an extra copy]
//Not elegant at all.
void partitionList_v1(myList& my, int x){
	std::vector<int> res1, res2, res3;
	Node*p = my.head;
	while (p != NULL){
		if (p->value < x)
			res1.push_back(p->value);
		if (p->value == x)
			res2.push_back(p->value);
		if (p->value> x)
			res3.push_back(p->value);
		p = p->next;
	}
	//Copy to 'my'
	p = my.head;
	for (unsigned int i = 0; i != res1.size(); i++){
		p->value = res1[i];
		p = p->next;
	}
	for (unsigned int i = 0; i != res2.size(); i++){
		p->value = res2[i];
		p = p->next;
	}
	for (unsigned int i = 0; i != res3.size(); i++){
		p->value = res3[i];
		p = p->next;
	}

}

//Append a node to a list
void appendTo(Node*& head, Node*& cur){
	//std::cout<<"Append:"<<cur->value<<", ";
	if (head == NULL){
		//std::cout<<"head is NULL"<<std::endl;
		head = cur;
		head->next = NULL;
		return;
	}
	Node *tmp = head->next;
	head->next = cur;
	cur->next = tmp;
	/*
	std::cout << "Debug: head is " << head->value<< ", ";
	//WTF, Debug code was wrong, how funny.
	Node *p=head;
	while (p != NULL){
		std::cout << p->value<<"-";
		p = p->next;
	}
	std::cout << std::endl;
	*/
	return;
}

//version-2: Space O(1), time O(n^2)
//Repartition in place
//When met a large node, move it away to 'large list'
void partitionList_v2(myList& my, int x){
	Node *p = my.head;
	Node* small = NULL;
	Node* equal = NULL;
	Node * large = NULL;
	while (p != NULL){
		Node* tmp = p->next;
		if (p->value > x)
			appendTo(large, p);
		if (p->value == x)
			appendTo(equal, p);
		if (p->value < x)
			appendTo(small, p);
		p = tmp;
	}
	my.head = small;
	//This concatenation operation seems stupid, but, what up?
	p = small;
	while (p->next != NULL)
		p = p->next;
	p->next = equal;
	while (p->next != NULL)
		p = p->next;
	p->next = large;

}


int  main()
{
	myList mylist;
	mylist.push_back(0); mylist.push_back(6); mylist.push_back(2);
	mylist.push_back(3); mylist.push_back(7); mylist.push_back(4);
	mylist.push_back(5); mylist.push_back(2); mylist.push_back(7);
	mylist.push_back(1); mylist.push_back(2); mylist.push_back(9);
	mylist.push_back(10);
	mylist.printList();
	myList newlist(mylist);
	//partitionList_v1(mylist, 5);
	//std::cout << "Method-1: " << std::endl;
	//mylist.printList();
	////Another
	//partitionList_v2(newlist, 5);
	//std::cout << "Method-2:" << std::endl;
	//newlist.printList();
	mylist.reverse();
	mylist.printList();
	mylist.reverse();
	mylist.printList();

	//mylist.destroyList_Iter(mylist.head);
	//mylist.printList();
	return 1;
}