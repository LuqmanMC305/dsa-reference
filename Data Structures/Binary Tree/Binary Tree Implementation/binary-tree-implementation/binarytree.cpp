#include "binarytree.h"
#include <iostream>

BinaryTree::TreeNode* BinaryTree::createNode(int value)
{
    TreeNode* node = new TreeNode();
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    
    return node;
}

BinaryTree::TreeNode* BinaryTree::insert(TreeNode* root, int value)
{
    if (root == nullptr)
    {
        root = createNode(value);
    }
    else if (value <= root->value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
}

void BinaryTree::inOrderTraversal(TreeNode* root)
{
    if(root == nullptr)
    {
        return;
    }
    else
    {
       inOrderTraversal(root->left);
       std::cout << root->value << " ";
       inOrderTraversal(root->right);
    }
}