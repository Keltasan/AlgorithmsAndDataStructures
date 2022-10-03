#pragma once

class List {

	struct Node
	{
		int value;
		Node *next;
	};

	Node* head;

    void clear()//function to clear the list
    {
        Node* current = head;
        while (current)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

public:

    List(size_t size = 1);

};