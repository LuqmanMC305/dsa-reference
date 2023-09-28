#include "binarytree.h"
#include <iostream>

void BinaryTree::preOrderTraversal(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    else
    {
        std::cout << root->value << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}


void BinaryTree::inOrderTraversal(Node* root)
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

void BinaryTree::postOrderTraversal(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    else
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->value << " ";
    }
}

void BinaryTree::insert(int newValue)
{
    root = insertNode(root, newValue); //Updating the tree when inserting nodes
}

BinaryTree::Node* BinaryTree::insertNode(Node* root, int newValue)
{
    if(root == nullptr) //Create a new node 
    {
        Node* newNode = new Node;
        newNode->value = newValue;
        newNode->left = nullptr;
        newNode->right = nullptr;

        return newNode;
    }

    if(newValue > root->value)
    {
        root->right = insertNode(root->right, newValue);
    }
    else if(newValue < root->value)
    {
        root->left = insertNode(root->left, newValue);
    }

    return root;

}

void BinaryTree::deleteNode(int targetValue)
{
    root = deleteNode(root, targetValue);
}

BinaryTree::Node* BinaryTree::inOrderSuccesor(Node* node)
{
    while(node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

BinaryTree::Node* BinaryTree::deleteNode(Node* &root, int targetValue)
{
    if(root == nullptr)
    {
        std::cout << "Node not found." << std::endl;
        return root;
    }

    if(targetValue < root->value)
    {
        root->left = deleteNode(root->left, targetValue);
    }
    else if(targetValue > root->value)
    {
        root->right = deleteNode(root->right, targetValue);
    }
    else //If found
    {
       // Case 1: node with one or no child

       Node* temp;
       
       if(root->left == nullptr)
       {
         temp = root->right;
         delete root;
         return temp;
       }
       else if(root->right == nullptr)
       {
         temp = root->left;
         delete root;
         return temp;
       }

       // Case 2: node with two children

       temp = inOrderSuccesor(root->right);

       root->value = temp->value;

       root->right = deleteNode(root->right, temp->value);


    }

    return root;
    
}








