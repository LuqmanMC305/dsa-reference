#include "binarytree.h"
#include <iostream>

int main() {
    BinaryTree tree;
    
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.deleteNode(20);

    std::cout << "Pre-Order Traversal: " << std::endl;
    tree.preOrderTraversal(tree.root);

    std::cout << "\nIn-Order Traversal: " << std::endl;
    tree.inOrderTraversal(tree.root);

    std::cout << "\nPost-Order Traversal: " << std::endl;
    tree.postOrderTraversal(tree.root);
   
    
    return 0;
}

