#ifndef BINARYTREE_
#define BINARYTREE_


class BinaryTree
{
    private:
      struct TreeNode
      {
         int value;
         TreeNode* left;
         TreeNode* right;
      };
      TreeNode* root;

    public:
      BinaryTree() : root(nullptr) {}
      void preOrderTraversal(TreeNode* root);
      void inOrderTraversal(TreeNode* root);
      void postOrderTraversal(TreeNode* root);
      TreeNode* createNode(int value);
      TreeNode* insert(TreeNode* root, int value);
};



#endif