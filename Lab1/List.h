#pragma once
#include <iostream>

class List
{
    struct Node
    {
        int value;
        Node* next;

        Node(int val)
            :value(val)
            , next(nullptr)
        {}
    };

    Node* head;
    Node* tail;

    int listSize;

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
        tail = nullptr;
    }

public:
    List()
        :head(nullptr)
        , tail(nullptr)
        , listSize(0)
    {}

    List(size_t size)
        :head(nullptr)
        , tail(nullptr)
        , listSize(size)
    {
        if (size)
        {
            head = new Node{ 0 };
            Node* current = head;
            for (size_t i = 0; i < size - 1; i++)
            {
                current->next = new Node{ 0 };
                current = current->next;
            }
        }
    }

    bool empty() {//if list empty - true
        return head == nullptr;
    }

    void append(int val) {//pushing new element in list
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

    void remove() {//remove from list
        Node* temp = head->next;

        delete head;

        head = temp;

        listSize--;
    }

    void setAt(size_t index, int value) {//function for changing element at "index" pos
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
    int size() {//return listSize
        return listSize;
    }

    void del(int pos) {//delete Node at pos
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

    void output() {//output of List
        Node* out = head;

        while (out)
        {
            std::cout << out->value << ' ';
        }

        std::cout << std::endl;
    }

    ~List()
    {
        clear();
    }
};