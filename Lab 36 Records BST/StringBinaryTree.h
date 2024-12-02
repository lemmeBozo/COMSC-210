#ifndef STRINGBINARYTREE_H
#define STRINGBINARYTREE_H

#include <string>

class StringBinaryTree {
// Private:
    struct TreeNode {
        std::string value;
        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* root;

   // Private member functions for internal operations.
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(std::string, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;

public:
   // Constructor initializes the root to nullptr, indicating an empty tree.
   StringBinaryTree()     { root = nullptr; }

   // Destructor deallocates all nodes in the tree.
   ~StringBinaryTree()    { destroySubTree(root); }

   // Public interface for inserting, searching, and removing nodes.
   void insertNode(std::string);
   bool searchNode(std::string);
   void remove(std::string);

   // Public wrappers for tree traversal functions.
   void displayInOrder() const     {  displayInOrder(root); }
   void displayPreOrder() const    {  displayPreOrder(root); }
   void displayPostOrder() const   {  displayPostOrder(root); }

};


#endif // STRINGBINARYTREE_H