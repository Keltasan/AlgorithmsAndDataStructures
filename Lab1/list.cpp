#include <iostream>
#include <fstream>
#include "list.h"

List::List(size_t size = 1)
    : head(nullptr)
{
    if (size)
    {
        head = new Node{ 0, nullptr };
        Node* current = head;
        for (size_t i = 0; i < size - 1; i++)
        {
            current->next = new Node{ 0, nullptr };
            current = current->next;
        }
    }
}