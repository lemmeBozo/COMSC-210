// Specification file for the IntBinaryTree class
#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

// The IntBinaryTree class manages a binary tree of integers.
class IntBinaryTree {
private:
   // TreeNode is a private structure for IntBinaryTree nodes.
   struct TreeNode {
      int value;         // The value in the node
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   // root points to the topmost node of the tree.
   TreeNode *root;      

   // Private member functions for internal operations.
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(int, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;

public:
   // Constructor initializes the root to nullptr, indicating an empty tree.
   IntBinaryTree()     { root = nullptr; }

   // Destructor deallocates all nodes in the tree.
   ~IntBinaryTree()    { destroySubTree(root); }

   // Public interface for inserting, searching, and removing nodes.
   void insertNode(int);
   bool searchNode(int);
   void remove(int);

   // Public wrappers for tree traversal functions.
   void displayInOrder() const     {  displayInOrder(root); }
   void displayPreOrder() const    {  displayPreOrder(root); }
   void displayPostOrder() const   {  displayPostOrder(root); }
};

#endif // INTBINARYTREE_H