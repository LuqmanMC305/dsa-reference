#ifndef BINARYTREE_
#define BINARYTREE_

class BinaryTree
{
    private:
      struct Node
      {
         int value;
         Node* left;
         Node* right;
      };
      

    public:
      BinaryTree() : root(nullptr) {}
      void inOrderTraversal(Node* root);
      void preOrderTraversal(Node* root);
      void postOrderTraversal(Node* root);
      void insert(int newValue);
      Node* insertNode(Node* root, int newValue);
      void deleteNode(int targetValue);
      Node* deleteNode(Node* &root, int targetValue);
      Node* inOrderSuccessor(Node* node);
      Node* invertTree(Node* root);
      void bfs(Node* root);


      Node* root;
};

#endif
