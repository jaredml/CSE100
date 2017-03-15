
//Binary Search Tree

#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

/****************************************************************
 * CONSTRUCTOR #1 
 *   Creates an binary tree
 ****************************************************************/
BST::BST() {
	
    //set root null
    root = NULL;
}

/****************************************************************
 * DECONSTRUCTOR
 *   Empty constructor
 ****************************************************************/
BST::~BST() {
}

void BST::Insert(string toInsert) {
    
    // Write your codes here

    //3 new nodes
    Node *z = new Node;
    Node *y = new Node;
    Node *x = new Node;
    
    //val to insert
    z->val = toInsert;

    //left,right, parent
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;
    
    
    y = NULL;
    x = root;
    
    //Move Down the tree, Left or Right(while x node does not point to null)
    while(x != NULL) {
	
	//set x's parent to y node
        y = x;
        
	//if value to insert is smaller than (the point in the tree), go left
        if(z->val < x->val) {
            x = x->left;
        }

	//else go right
        else {
            x = x->right;
        }
    }
    
    //set parent of inserted value,  to y node
    z->parent = y;
    
    //if tree empty, make inserted value to root
    if(y == NULL) {
        root = z;
    }

    //set value, left or right compared to y node
    else if(z->val < y->val) {
        y->left = z;
    }
    else {
        y->right = z;
    }
}

void BST::Delete(string toDelete) {

    // Write your codes here
    Node *z;
    Node *y;
    
    Node *r = root;
    
    //while root exist, and delete val !=root
    while(r != NULL && toDelete != r->val) {
	
	//if delete.val smaller than (point at), go left
        if(toDelete < r->val) {
            r = r->left;
        }
	
	//else go right
        else {
            r = r->right;
        }
    }
    
    //not found
    if(r == NULL) {
        return;
    }

    //else set the node to z
    else {
        z = r;
    }
    
    //if left NULL
    if(z->left == NULL) {
        Transplant(z,z->right);
    }

    //if right NULL
    else if(z->right == NULL) {
        Transplant(z,z->left);
    }
    
    //if right and left not NULL of delete val
    else {
        y = Minimum(z->right);
        
        if(y->parent != z) {
            Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        
        Transplant(z, y);
        
        y->left = z->left;
        y->left->parent = y;
    }
}

void BST::Transplant(Node *u, Node *v) {
  // Write your codes here

    //if deleting root
    if(u->parent == NULL) {
        root = v;
    }

    //if deleting on the left side of tree
    else if(u == u->parent->left) {
        u->parent->left = v;
    }
	
    //if deleting on the right side of the tree
    else {
        u->parent->right = v;
    }

    //set the new parent
    if(v != NULL) {
        v->parent = u->parent;
    }
}

Node *BST::Successor(Node *x) {
  // Write your codes here
    
    Node *y = new Node;
    Node *r = root;
    
    if(r == NULL) {
        return 0;
    }
    else {
        x = r;
    }
    
    if(x->right != NULL) {
        return Minimum(x->right);
    }
    
    y = x->parent;
    
    while(y != NULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    
    return y;
}

Node *BST::Minimum(Node *x) {
  // Write your codes here
    if(x->left == NULL) {
        return x;
    }
    Minimum(x->left);
}

Node *BST::Maximum(Node *x) {
  // Write your codes here
    if(x->right == NULL) {
        return x;
    }
    Maximum(x->right);
}

Node *BST::Search(string toFind) {
  // Write your codes here
    Node *x = root;
    while(x != NULL && toFind != x->val) {
        if(toFind < x->val) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    
    return x;
}

void BST::Print(string Order) {
  if(Order=="IN")
    InOrder(root);
  else if(Order=="PRE")
    PreOrder(root);
  else if(Order=="POST")
    PostOrder(root);
}

void BST::PreOrder(Node *x) {
  // Write your codes here
    if(x != NULL) {
        cout << x->val << endl;
        PreOrder(x->left);
        PreOrder(x->right);
    }
}

void BST::InOrder(Node *x) {
  // Write your codes here
    if(x != NULL) {
        InOrder(x->left);
        cout << x->val << endl;
        InOrder(x->right);
    }
}

void BST::PostOrder(Node *x) {
  // Write your codes here
    if(x != NULL) {
        PostOrder(x->left);
        PostOrder(x->right);
        cout << x->val << endl;
    }
}
