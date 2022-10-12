#pragma once

#ifdef DYNAMIC_LIB_IMPL

#define DECLSPEC __declspec(dllexport)

#else

#define DECLSPEC __declspec(dllimport)

#endif
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

    void push(char val);

    int size();

    bool empty();

    char top();

    char peek(int pos);

    void pop();

    bool find(char val);

    char& operator[](int i);
};