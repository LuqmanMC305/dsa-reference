#include "binarytree.h"
#include <iostream>

int main() {
    BinaryTree tree1;

    tree1.insert(4);
    tree1.insert(2);
    tree1.insert(7);
    tree1.insert(1);
    tree1.insert(3);
    tree1.insert(6);
    tree1.insert(9);


    std::cout << "\nIn-Order Traversal: " << std::endl;
    tree1.preOrderTraversal(tree1.root);
    std::cout << std::endl;

    std::cout << "\n BFS Search (from left to right):"  << std::endl;
    tree1.bfs(tree1.root);
    std::cout << std::endl;
    
    tree1.invertTree(tree1.root);
    tree1.preOrderTraversal(tree1.root);

    


    return 0;
}

