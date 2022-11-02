#include "List.h"
#include <iostream>

bool List::empty(){
	return head == nullptr;
}

void List::append(int val){
	Node* temp = new Node(val);

	if (empty())
	{
		head = temp;
		tail = temp;
		return;
	}

	head->next = temp;
	head = temp;

	listSize++;
}

void List::setAt(size_t index, int value){
    size_t currentIndex = 0;
    Node* current = head;

    while (current)
    {
        if (index == currentIndex)
        {
            current->value = value;
            break;
        }
        
        ++currentIndex;
        current = current->next;
    }
}

void List::remove(){
	Node* temp = head->next;

	delete head;

	head = temp;

	listSize--;
}

int List::size() {
	return listSize;
}

void List::del(int pos) {
	Node* temp1 = head->next;
	Node* temp2 = nullptr;

	for (int i = 0; i < pos; ++i)
	{
		temp2 = temp1;
		temp1 = temp1->next;
	}

	if (temp2 != nullptr) {
		temp2 = temp1->next;
	}

	delete temp1;
}

void List::output() {
	Node* out = head;

	while (out) 
	{
		std::cout << out->value << ' ';
	}

	std::cout << std::endl;
}