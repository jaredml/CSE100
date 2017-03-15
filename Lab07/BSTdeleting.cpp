
//Binary Search Tree Deletion

#include <iostream>
#include <stdlib.h>
#include "BST.h"

using namespace std;

int main(int argc,char **argv)
{
    //Create an empty Binary Search Tree
    BST Tree;
	
    //input string
    string input;
    
    //while string not "ENDINSERT"
    while(input != "ENDINSERT") {
        cin >> input;
	
	//if not "ENDINSERT", insert
        if(input != "ENDINSERT") {
	    Tree.Insert(input);
        }
    }

	////while string not "ENDINSERT"
 	while(input != "ENDDELETE") {
        cin >> input;
	
	//if string not "ENDINSERT", delete
        if(input != "ENDDELETE") {
	    Tree.Delete(input);
        }
    }

	//post
	Tree.Print("POST");
}
