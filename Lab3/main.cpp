#include <iostream>
#include <string>
#include "AVL.h"
#include "BinTree.h"
#include "fileFunc.h"

int main(int argc, char* argv[]) {
    BinTree tree;
    std::string s;

    int choose = 0;
    std::cout << "What type of insert do you want:" << std::endl
              << "1 - constant string" << std::endl
              << "2 - string from console" << std::endl
              << "3 - string from file" << std::endl;
    std::cin >> choose;

    if (choose == 1)
    {
        s = "6 (2(1)(4(3)(5))) (7(9(8)))";
    }
    else if (choose == 2)
    {
        std::cout << "Insert tree(without first and last brackets and spaces):" << std::endl;
        std::cin >> s;
    }
    else if (choose == 3)
    {
        char filename[] = "input.txt";
        std::cout << "Standart name of file is 'input.txt'" << std::endl;
        readingFromFile(filename, s);
        std::cout << "Your string is:" << std::endl << s << std::endl;
    }

    tree.strToTree(s);
    AVL avlTree;
    int* treeNodes = tree.preOrder();

    for (int i = 0; i < tree.counter; ++i)
    {
        avlTree.add(treeNodes[i]);
    }

    std::cout << "Tree:\n";

    printTree(tree.root, 1);

    std::cout << "\n\nAVL Tree:\n";

    printAVL(avlTree.root, 1);

    std::cout << "\n\n";

    int *avlTreeNodes = avlTree.preOrder();
    std::cout << "Preorder - ";
    for (int i = 0; i < avlTree.counter; i++)
    {
        std::cout << avlTreeNodes[i] << " ";
    }

    avlTreeNodes = avlTree.inOrder();
    std::cout << "\nInorder - ";
    for (int i = 0; i < avlTree.counter; i++)
    {
        std::cout << avlTreeNodes[i] << " ";
    }

    avlTreeNodes = avlTree.postOrder();
    std::cout << "\nPostorder - ";
    for (int i = 0; i < avlTree.counter; i++)
    {
        std::cout << avlTreeNodes[i] << " ";
    }

    std::cout << "\n";
    system("pause");
}