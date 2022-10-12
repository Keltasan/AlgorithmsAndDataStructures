#pragma once

char priority(char op);

bool isOperator(char op);

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