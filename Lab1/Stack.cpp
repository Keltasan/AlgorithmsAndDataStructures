#include "Stack.h"

void Stack::push(char val) {
	Node* temp = new Node;
	temp->value = val;
	temp->next = head;
	head = temp;

	stackSize++;
}

bool Stack::empty() {
	return head == nullptr;
}

void Stack::pop() {
	if (!empty()) 
	{
		Node* temp = head;
		head = head->next;
		delete temp;

		stackSize--;
	}
}

char Stack::top() {
	if (!empty())
	{
		return head->value;
	}
}

char Stack::peek(int pos) {
	if (!empty() && (pos < stackSize))
	{
		Node* temp = head;

		for (int i = 0; i < pos; ++i) 
		{
			temp = temp->next;
		}

		return temp->value;
	}
}

int Stack::size() {
	return stackSize;
}

bool Stack::find(char val) {
	if (!empty()) {
		Node* temp = head;
		
		for (int i = 0; i < size(); ++i) 
		{
			if (temp->value == val) {
				return true;
			}

			temp = temp->next;
		}

		return false;
	}
}

char& Stack::operator[](int pos) {
	Node* temp = head;

	for (int i = size() - 1; i >= pos; i--)
	{
		temp = temp->next;
	}

	return temp->value;
}