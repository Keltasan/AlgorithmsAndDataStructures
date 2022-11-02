#pragma once

class List
{
    struct Node
    {
        int value;
        Node* next;

        Node(int val)
            :value(val)
            ,next(nullptr)
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
        ,tail(nullptr)
        ,listSize(0)
    {}

    List(size_t size)
        :head(nullptr)
        ,tail(nullptr)
        ,listSize(size)
    {
        if (size)
        {
            head = new Node{0};
            Node* current = head;
            for (size_t i = 0; i < size - 1; i++)
            {
                current->next = new Node{0};
                current = current->next;
            }
        }
    }

    bool empty();//if list empty - true

    void append(int val);//pushing new element in list

    void remove();//remove from list

    void setAt(size_t index, int value);//function for changing element at "index" pos

    int size();//return listSize

    void del(int pos);//delete Node at pos

    void output();//output of List

    ~List()
    {
        clear();
    }
};