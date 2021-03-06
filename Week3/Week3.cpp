// Week3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// If a class would only have data members, convention is to call it a struct 
// If a class methods, it should stay a class
template <typename T>
struct Node {
	T data;
	Node *link{ nullptr };
};

template <typename T>
class LinkedList {
public:
	~LinkedList();
	void pushBack(const T& item);
	void pushFront(const T& item);
	void popFront();
	void popBack();
private:
	Node<T> * front{ nullptr };
	Node<T> * back{ nullptr };
	unsigned int size{ 0 };
};

template<typename T>
LinkedList<T>::~LinkedList() {
	Node<T> *temp = front;

	while (temp) {
		temp = temp->link;
		delete front;
		front = temp;
	}
}

template <typename T>
void LinkedList<T>::pushBack(const T& item) {

	//Scenarios, specific to general
	//Scenario 1: List is empty
	//Scenario 2: List has at least 1 item in it

	Node<T> * tempPtr = new Node<T>();
	tempPtr->data = item;
	if (front == nullptr) {
		front = tempPtr;
	}
	else {
		back->link = tempPtr;
	} 
	back = tempPtr;
	size++;

}

template <typename T>
void LinkedList<T>::pushFront(const T& item) {
	// Determine all scenarios early
	// Scenario: The list is empty
	//           The list has at least one item in it
	// Code most specific scenarios first
	// Most general scenarios first
	Node<T> *temp = new Node<T>();
	temp->data = item;
	if (!front) {
		// Scenario: The list is empty

		back = temp;
	} else {
		// Scenario: The list has at least one node in it
		temp->link = front;
	}
	front = temp;
	size++;

}

template<typename T>
void LinkedList<T>::popFront() {
	// Scenario: Empty
	// Scenario: One item
	// Scenario: Two or more items

	if (!front) {
		// Scenario: Empty
		cout << "The list was already wmpty" << endl;
		return;
	}
	else if (front == back) {
		// Scenario: One item
		delete front;
		front = nullptr;
		back = nullptr;
		size--;
	}
	else {
		// Scenario: Two or more items
		Node<T> *nodeToDelete = front;
		front = front->link;
		delete nodeToDelete;
		size--;
	}
}

template<typename T>
void LinkedList<T>::popBack() {
	// Scenario: Empty
	// Scenario: One item
	// Scenario: Two or more items
	if (!front) {
		// Scenario: Empty
		cout << "The list was already wmpty" << endl;
		return;
	}
	else if (front == back) {
		// Scenario: One item
		delete back;
		front = nullptr;
		back = nullptr;
		size--;
	}
	else {
		// Scenario: Two or more items
		// 1. Made the nodeToDelete
		// 2. Make a cur in advance it forward
		// 3. back = cur;
		// 4. delete nodeToDelete;
		// 5. Update the pointer
		// 6. Decrement size--;
		Node<T> *nodeToDelete = back;
		Node<T> *cur = front;
		while (cur->link != back) {
			cur = cur->link;
			// DO NOT USE cur++; <<<<<<<<<<<<
		}
		// Cur is now at the second to last node
		back = cur;
		delete nodeToDelete;
		back->link = nullptr;
		size--;
	}
	
}

int main() {
	{
		LinkedList<string> petNames;
		petNames.pushBack("Taboo");
		petNames.pushBack("Faro");
		petNames.pushBack("Clover");
		petNames.pushBack("Angus");
		/*petNames.pushFront("Zeke");
		petNames.pushFront("Zoloft");*/
	}
	/*petNames.popFront();
	petNames.popFront();
	petNames.popFront();
	petNames.popBack();
	petNames.popBack();
	petNames.popBack();
	petNames.popBack();
	petNames.popBack();*/
	
	 
	return 0;
}

// Arrays are FAST! Take advantage of locality (L1, L2, L3). Compact. 
// Short ints take up significantly less space 