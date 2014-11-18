#include "BinarySearchTree.h"
#include "BinaryTreeIterator.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }

   delete iter;
}

int main()
{
   //the unsorted ListArray of cds
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int numItems = cds->size();
   cout << numItems << endl;
   cout << endl;

   //test the binary search tree
   //insert all of the cds
   ListArrayIterator<CD>* iter = cds->iterator();
   BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
   while(iter->hasNext())
   {
      CD* cd = iter->next();
      bst->insert(cd);
   }
   delete iter;

   BinaryTreeIterator<CD>* bst_iter = bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->displayCD();
   }
   delete bst_iter;

   //DO THIS
   //display the height of the binary search tree (not minimum height)
   //display whether the binary search tree is balanced (should not be balanced)

   cout << endl;

   int height = bst -> getHeight();
   cout << "The height of this BST is: " << height << endl;

   bool balanced = bst -> isBalanced();
   if(balanced == true)
   {
      cout << "The BST is balanced." << endl;
   }

   if(balanced == false)
   {
      cout << "The BST is NOT balanced. Sorry." << endl;
   }

   cout << endl;

   //create a minimum height binary search tree
   BinarySearchTree<CD>* min_bst = bst->minimize();
   bst_iter = min_bst->iterator();

   //make sure that an inorder traversal gives sorted order
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->displayCD();
   }
   delete bst_iter;

   //DO THIS
   //display the height of the binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)

   cout << endl;

   int min_height = min_bst -> getHeight();
   cout << "The height of this BST is: " << min_height << endl;

   bool min_balanced = min_bst -> isBalanced();
   if(min_balanced == true)
   {
      cout << "The BST is balanced." << endl;
   }

   if(min_balanced == false)
   {
      cout << "The BST is NOT balanced. Sorry." << endl;
   }

   cout << endl;

   //create a complete binary search tree
   BinarySearchTree<CD>* complete_bst = bst->minimizeComplete();
   delete bst;

   //make sure that an inorder traversal gives sorted order
   bst_iter = complete_bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->displayCD();
   }
   delete bst_iter;

   //DO THIS
   //display the height of the complete binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)

   cout << endl;

   int complete_height = complete_bst -> getHeight();
   cout << "The height of this BST is: " << complete_height << endl;

   bool complete_balanced = complete_bst -> isBalanced();
   if(complete_balanced == true)
   {
      cout << "The BST is balanced." << endl;
   }

   if(complete_balanced == false)
   {
      cout << "The BST is NOT balanced. Sorry." << endl;
   }

   delete complete_bst;

   deleteCDs(cds);
   delete cds;
   return 0;
}
