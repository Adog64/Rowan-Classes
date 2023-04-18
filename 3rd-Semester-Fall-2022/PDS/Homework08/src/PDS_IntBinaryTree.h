#pragma once
#include <iostream>

class IntBinaryTree
{
private:
   int nodeCount, sum;
   float mean;

   // The TreeNode struct is used to build the tree.
   struct TreeNode
   {
      int value;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int value1,
              TreeNode *left1 = nullptr,
              TreeNode *right1 = nullptr)
      {
         value = value1;
         left = left1;
         right = right1;
      }
   };

   TreeNode *root;     // Pointer to the root of the tree

    //**************************************************
    // This version of insert inserts a number into    *
    // a given subtree of the main binary search tree. *
    //**************************************************
    void insert(TreeNode * &tree, int num)
    {
       // If the tree is empty, make a new node and make it
       // the root of the tree. We are passing the node pointer by
       // reference so that if it is replaced like below, the
       // change will also impact the incoming argument.

       if (!tree)
       {
          tree = new TreeNode(num);
          nodeCount++;
          sum += num;
          mean = static_cast<float>(sum)/nodeCount;
          return; //Terminate the function
       }

       // If num is already in tree: return.
       if (tree->value == num)
          return;

       // The tree is not empty: insert the new node into the
       // left or right subtree.
       if (num < tree->value)
          insert(tree->left, num);
       else
          insert(tree->right, num);
    }
    
    /// @brief find the minimum value in an integer binary tree
    /// @param tree the binary tree to traverse
    /// @return the minimum value
    int findMin(TreeNode *tree)
    {
      if (!tree)
         throw std::length_error("Empty set has no min.");
      else
      {
         TreeNode *leftest = tree;
         while (leftest->left)
            leftest = leftest->left;
         return leftest->value;
      }
    }

   /// @brief find the maximum value in an integer binary tree
   /// @param tree the binary tree to traverse
   /// @return the maximum value
   int findMax(TreeNode *tree)
   {
      if (!tree)
        throw std::length_error("Empty set has no max.");
      else
      {
         TreeNode *rightest = tree;
         while (rightest->right)
         rightest = rightest->right;
         return rightest->value;
      }
   }

    
    //***************************************************
    // destroySubTree is called by the destructor. It   *
    // deletes all nodes in the tree.                   *
    //***************************************************
    void destroySubtree(TreeNode *tree)
    {
       if (!tree) return;
       destroySubtree(tree->left);
       destroySubtree(tree->right);
       // Delete the node at the root.
       delete tree;
    }
    
    //********************************************
    // remove deletes the node in the given tree *
    // that has a value member the same as num.  *
    //********************************************
    void remove(TreeNode *&tree, int num)
    {    
       if (tree == nullptr) return;
       if (num < tree->value)
          remove(tree->left, num);
       else if (num > tree->value)
          remove(tree->right, num);
       else
       {
          // We have found the node to delete.
         nodeCount--;
         sum -= num;
         mean = static_cast<float>(sum)/nodeCount;
         makeDeletion(tree);
       }
    }
    
    
    //***********************************************************
    // makeDeletion takes a reference to a tree whose root      *
    // is to be deleted. If the tree has a single child, the    *
    // the tree is replaced by the single child after the       *
    // removal of its root node. If the tree has two children   *
    // the left subtree of the deleted node is attached at      *
    // an appropriate point in the right subtree, and then      *
    // the right subtree replaces the original tree.            *
    //***********************************************************
    void makeDeletion(TreeNode *&tree)
    {
       // Used to hold node that will be deleted.
       TreeNode *nodeToDelete = tree;

       // Used to locate the  point where the
       // left subtree is attached.
       TreeNode *attachPoint;

       if (tree->right == nullptr)
       {
          // Replace tree with its left subtree.
          tree = tree->left;
       }
       else if (tree->left == nullptr)
       {
          // Replace tree with its right subtree.
          tree = tree->right;
       }
       else
          //The node has two children
       {
          // Move to right subtree.
          attachPoint = tree->right;

          // Locate the smallest node in the right subtree
          // by moving as far to the left as possible.
          while (attachPoint->left != nullptr)
             attachPoint = attachPoint->left;

          // Attach the left subtree of the original tree
          // as the left subtree of the smallest node
          // in the right subtree.
          attachPoint->left = tree->left;

          // Replace the original tree with its right subtree.
          tree = tree->right;
       }

       // Delete root of original tree
       delete nodeToDelete;
    }
    
    
    //*********************************************************
    // This function displays the values  stored in a tree    *
    // in inorder.                                            *
    //*********************************************************
    void displayInOrder(TreeNode *tree) const
    {
       if (tree)
       {
          displayInOrder(tree->left);
          std::cout << tree->value << "  ";
          displayInOrder(tree->right);
       }
    }
    

    //*********************************************************
    // This function displays the values stored in a tree     *
    // in inorder.                                            *
    //*********************************************************
    void displayPreOrder(TreeNode *tree) const
    {
       if (tree)
       {
          std::cout << tree->value << "  ";
          displayPreOrder(tree->left);
          displayPreOrder(tree->right);
       }
    }

    //*********************************************************
    // This function displays the values  stored  in a tree   *
    // in postorder.                                          *
    //*********************************************************
    void displayPostOrder(TreeNode *tree) const
    {
       if (tree)
       {
          displayPostOrder(tree->left);
          displayPostOrder(tree->right);
          std::cout << tree->value << "  ";
       }
    }

    /// @brief Displays the leaf values of a binary tree
    /// @param tree Binary tree being traced recursively
    void displayLeafNodes(TreeNode *tree) const
    {
      if (tree)
      {
         if(tree->left || tree->right)
         {
            displayLeafNodes(tree->left);
            displayLeafNodes(tree->right);
         }
         else
            std::cout << tree->value << ' ';
      }
      
    }
    
    

public:
   // These member functions are the public interface.
   IntBinaryTree()        // Constructor
   {
      root = nullptr;
      nodeCount = 0;
      sum = 0;
      mean = 0;
   }
   ~IntBinaryTree()        // Destructor
   {
      destroySubtree(root);
   }
   void insert(int num)
   {
      insert(root, num);
   }
   void remove(int num)
   {
      remove(root, num);
   }
   void showInOrder(void) const
   {
      displayInOrder(root);
   }
   void showPreOrder() const
   {
      displayPreOrder(root);
   }
   void showPostOrder() const
   {
      displayPostOrder(root);
   }
   void showLeafNodes() const
   {
      displayLeafNodes(root);
   }
   int getMin()
   {
      findMin(root);
   }
   int getMax()
   {
      findMax(root);
   }
   int getNodeCount()
   {
      return nodeCount;
   }
   int getSum()
   {
      return sum;
   }
   float getMean()
   {
      return mean;
   }
    //***************************************************
    // searchNode determines if a value is present in   *
    // the tree. If so, the function returns true.      *
    // Otherwise, it returns false.                     *
    //***************************************************
    bool search(int num) const
    {
       TreeNode *tree = root;

       while (tree)
       {
          if (tree->value == num)
             return true;
          else if (num < tree->value)
             tree = tree->left;
          else
             tree = tree->right;
       }
       return false;
    }
};