#pragma once
#include <iostream>
#include <algorithm>

struct avlNode
{
    int value;
    int height;
    avlNode* left;
    avlNode* right;

    avlNode(int v)
    {
        value = v;
        left = right = nullptr;
        height = 1;
    }
};
class AVL
{
private:
    int* nodes = 0;
    int i;

    void orderEvent(int value)
    {
        nodes[i] = value;
        ++i;
    }

    void preOrder(avlNode* a)
    {
        if (a)
        {
            orderEvent(a->value);
            preOrder(a->left);
            preOrder(a->right);
        }
    }

    void inOrder(avlNode* a)
    {
        if (a)
        {
            inOrder(a->left);
            orderEvent(a->value);
            inOrder(a->right);
        }
    }

    void postOrder(avlNode* a)
    {
        if (a)
        {
            postOrder(a->left);
            postOrder(a->right);
            orderEvent(a->value);
        }
    }

    int getHeight(avlNode* a)
    {
        return a ? a->height : 0;
    }

    int getBalanceFactor(avlNode* a)
    {
        return getHeight(a->right) - getHeight(a->left);
    }

    void editHeight(avlNode* a)
    {
        int heightLeft = getHeight(a->left);
        int heightRight = getHeight(a->right);
        a->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
    }

    avlNode *rightRotate(avlNode* a)
    {
        avlNode* q = a->left;
        a->left = q->right;
        q->right = a;

        editHeight(a);
        editHeight(q);

        return q;
    }

    avlNode *leftRotate(avlNode* a)
    {
        avlNode* b = a->right;
        a->right = b->left;
        b->left = a;

        editHeight(a);
        editHeight(b);

        return b;
    }

    avlNode *balance(avlNode* a)
    {
        editHeight(a);

        if (getBalanceFactor(a) == 2)
        {
            if (getBalanceFactor(a->right) < 0)
            {
                a->right = rightRotate(a->right);
            }
            return leftRotate(a);
        }

        if (getBalanceFactor(a) == -2)
        {
            if (getBalanceFactor(a->left) > 0)
            {
                a->left = leftRotate(a->left);
            }
            return rightRotate(a);
        }

        return a;
    }

    avlNode *findMin(avlNode* a)
    {
        return a->left ? findMin(a->left) : a;
    }

    avlNode *removeMin(avlNode* a)
    {
        if (a->left == 0)
        {
            return a->right;
        }
        a->left = removeMin(a->left);

        return balance(a);
    }

    avlNode *insert(avlNode* a, int value)
    {
        if (!a)
        {
            return new avlNode(value);
        }

        if (value < a->value)
        {
            a->left = insert(a->left, value);
        }
        else
        {
            a->right = insert(a->right, value);
        }

        return balance(a);
    }

    avlNode *remove(avlNode* a, int value)
    {
        if (!a)
        {
            return 0;
        }

        if (value < a->value)
        {
            a->left = remove(a->left, value);
        }
        else
        {
            if (value > a->value)
            {
                a->right = remove(a->right, value);
            }
            else
            {
                avlNode* b = a->left;
                avlNode* c = a->right;
                delete a;
                if (!c)
                {
                    return b;
                }
                avlNode* min = findMin(c);
                min->right = removeMin(c);
                min->left = b;

                return balance(min);
            }
        }

        return balance(a);
    }

public:
    avlNode* root;
    int counter;

    AVL()
    {
        root = nullptr;
        nodes = nullptr;
        counter = 0;
        i = 0;
    }

    void add(int value)
    {
        root = insert(root, value);
        ++counter;
    }

    void del(int value)
    {
        root = remove(root, value);
        counter--;
    }

    int* preOrder()
    {
        if (root)
        {
            delete []nodes;
            nodes = new int[counter];
            preOrder(root);
            i = 0;
            return nodes;
        }
    }

    int* inOrder()
    {
        if (root)
        {
            delete[]nodes;
            nodes = new int[counter];
            inOrder(root);
            i = 0;
            return nodes;
        }
    }

    int* postOrder()
    {
        if (root)
        {
            delete[]nodes;
            nodes = new int[counter];
            postOrder(root);
            i = 0;
            return nodes;
        }
    }
};

void printAVL(avlNode* a, int level)
{
    if (a)
    {
        printAVL(a->right, level + 1);
        for (int i = 0; i < level; i++)
        {
            std::cout << "   ";
        }
        std::cout << a->value << "-<\n";
        printAVL(a->left, level + 1);
    }
}