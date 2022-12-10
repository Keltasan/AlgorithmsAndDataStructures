#pragma once
#include <iostream>
#include <algorithm>

struct node
    {
        int value;
        node* left;
        node* right;

        node(int v)
        {
            value = v;
            left = right = nullptr;
        }
    };

class BinTree
{
private:
    int* nodes;
    int i = 0;

    void orderEvent(int value)
    {
        nodes[i] = value;
        ++i;
    }

    void preOrder(node* a)
    {
        if (a)
        {
            orderEvent(a->value);
            preOrder(a->left);
            preOrder(a->right);
        }
    }

    void inOrder(node* a)
    {
        if (a)
        {
            inOrder(a->left);
            orderEvent(a->value);
            inOrder(a->right);
        }
    }

    void postOrder(node* a)
    {
        if (a)
        {
            postOrder(a->left);
            postOrder(a->right);
            orderEvent(a->value);
        }
    }
    
    bool isNumber(char a)
    {
        return a >= '0' && a <= '9';
    }

    node* parsing(node* a, std::string s, int& i)//in progress of normal realization
    {
        if (s[i] == '(')
        {
            std::string valueStr;
            i++;
            while (isNumber(s[i]))
            {
                valueStr += s[i];
                i++;
            }

            if (valueStr.size() != 0)
            {
                int valueTmp = stoi(valueStr);
                a->left = new node(valueTmp);
                ++counter;
            }
            else
            {
                return nullptr;
            }

            if (s[i] == '(')
            {
                parsing(a->left, s, i);
            }

            if (s[i] != ')')
            {
                return nullptr;
            }
            i++;
        }

        if (s[i] == '(')
        {
            std::string valueStr;
            i++;
            while (isNumber(s[i]))
            {
                valueStr += s[i];
                i++;
            }

            if (valueStr.size() != 0)
            {
                int valueTmp = stoi(valueStr);
                a->right = new node(valueTmp);
                ++counter;
            }
            else
            {
                return nullptr;
            }

            if (s[i] == '(')
            {
                parsing(a->right, s, i);
            }

            if (s[i] != ')')
            {
                return nullptr;
            }
            i++;
        }

        return a;
    }

    node* findMin(node* a)
    {
        return a->left ? findMin(a->left) : a;
    }

    node* removeMin(node* a)
    {
        if (a->left == 0)
        {
            return a->right;
        }
        a->left = removeMin(a->left);

        return a;
    }

    node* insert(node* a, int value)
    {
        if (!a)
        {
            return new node(value);
        }

        if (value < a->value)
        {
            a->left = insert(a->left, value);
        }
        else
        {
            a->right = insert(a->right, value);
        }

        return a;
    }

    node *remove(node *a, int value)
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
                node* b = a->left;
                node* c = a->right;
                delete a;
                if (!c)
                {
                    return b;
                }
                node* min = findMin(c);
                min->right = removeMin(c);
                min->left = b;

                return min;
            }
        }

        return a;
    }

public:
    node* root;
    int counter = 0; //counts number of nodes

    BinTree()
    {
        root = nullptr;
        nodes = nullptr;
        counter = 0;
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

    void strToTree(std::string s)
    {
        bool error = 0;
        int brackets = 0;
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                brackets++;;
            }
            else if (s[i] == ')')
            {
                brackets--;
            }
            else if (!isNumber(s[i]))
            {
                error = 1;
                break;
            }
        }

        if (s.size() != 0 && !error && !brackets)
        {
            int i = 0;
            std::string tmp;
            while (isNumber(s[i]))
            {
                tmp += s[i];
                i++;
            }
            add(stoi(tmp));
            root = parsing(root, s, i);
        }
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

void printTree(node* a, int lvl)
{
    if (a)
    {
        printTree(a->right, lvl + 1);
        for (int i = 0; i < lvl; i++)
        {
            std::cout << "   ";
        }
        std::cout << a->value << "-<\n";
        printTree(a->left, lvl + 1);
    }
}