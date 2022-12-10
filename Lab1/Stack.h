#pragma once

class Stack {
private:
	struct Node {
		char value;
		Node* next = nullptr;
	};

	Node* head;
	unsigned stackSize = 0;
public:


	Stack() {
		head = nullptr;
	};

	~Stack() {
		while (!empty()) {
			pop();
		}
	};

	void push(char val) {
		Node* temp = new Node;
		temp->value = val;
		temp->next = head;
		head = temp;

		stackSize++;
	}

	int size() {
		return stackSize;
	}

	bool empty() {
		return head == nullptr;
	}

	char top() {
		if (!empty())
		{
			return head->value;
		}
	}

	char peek(int pos) {
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

	void pop() {
		if (!empty())
		{
			Node* temp = head;
			head = head->next;
			delete temp;

			stackSize--;
		}
	}

	bool find(char val) {
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

	char& operator[](int pos) {
		Node* temp = head;

		for (int i = size() - 1; i >= pos; i--)
		{
			temp = temp->next;
		}

		return temp->value;
	}
};