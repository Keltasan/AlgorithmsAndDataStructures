#pragma once
#include <string>
#include "Stack.h"

char priority(char op) {
    switch (op) {
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return op;
        break;
    }
}

bool isOperator(char op) {
    if (op == '-' || op == '+' || op == '*' || op == '/' || op == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

class DynamicArray
{
public:
    int* head = nullptr;
    int size = 0;

    DynamicArray(int arraySize = 0)
    {
        if (arraySize > 0)
        {
            head = new int[arraySize];
            size = arraySize;
        }
    }

    void resize(int arraySize)
    {
        if (arraySize > 0)
        {
            int* tmp = new int[arraySize];

            for (int i = 0; i < arraySize; i++)
            {
                if (i < size)
                {
                    tmp[i] = head[i];
                }
            }

            delete[] head;
            head = tmp;
            size = arraySize;
        }
    }

    ~DynamicArray()
    {
        delete[] head;
    }

    int& operator[](int i)
    {
        return head[i];
    }
};