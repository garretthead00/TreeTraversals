// StringTraversals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>                          
#include <iostream>


/* A binary tree node containing data; a left child pointer; and a right child pointer
*/
struct node
{
	char data;
	struct node* left;
	struct node* right;
};

// Identifier for the search function
int search(char arr[], int strt, int end, char value);
// Identifier for the newNode
struct node* newNode(char data);


/* This function builds a tree based on the inOrder and preOrder arrays passed into the parameter and the
indexes (start and end) for the Inorder array to build the left and right subtrees
*/
struct node* buildTree(char in[], char pre[], int start, int end)
{
	static int indexCounter = 0;

	if (start > end)
		return NULL;

	/* Pick current Node from Preorder traversal using Index of the preOrder traversal
	and increment IndexCounter */
	struct node *Node = newNode(pre[indexCounter++]);

	/* If this node has no children then return the node */
	if (start == end)
		return Node;

	/* Else find the index of this node in Inorder traversal */
	int inIndex = search(in, start, end, Node->data);

	/* Using indexes in the Inorder traversal to construct the left and right subtrees */
	Node->left = buildTree(in, pre, start, inIndex - 1);
	Node->right = buildTree(in, pre, inIndex + 1, end);

	return Node;
}



/* Adds a new node to the tree
Sets the data and the children
*/
struct node* newNode(char data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}




/* This function will get the PostOrder traversal of the tree built by the BuildTree function
* using recursion.
*/
void getPostOrder(struct node* node)
{
	if (node == NULL)
		return;

	// Recurse down the left subtree
	getPostOrder(node->left);

	// Recurse down right subtree
	getPostOrder(node->right);

	// Visit the Node
	printf("%c ", node->data);
}

/* This function will get the PostOrder traversal of the tree built by the BuildTree function
* using recursion.
*/
void getInOrder(struct node* node)
{
	if (node == NULL)
		return;

	// Recurse down the left subtree
	getInOrder(node->left);
	// Visit the Node
	printf("%c ", node->data);

	// Recurse down right subtree
	getInOrder(node->right);


}

/* This function will get the PreOrder traversal of the tree built by the BuildTree function
* using recursion.
*/
void getPreOrder(struct node* node)
{
	if (node == NULL)
		return;

	// Visit the Node
	printf("%c ", node->data);

	// Recurse down the left subtree
	getPreOrder(node->left);

	// Recurse down right subtree
	getPreOrder(node->right);

}

int main(void)
{
	// Initialize both preOrder and inOrder arrays
	char in[] = { 'B', 'X', 'R', 'D', 'S', 'A', 'P', 'C', 'T', 'Q', 'Y' };
	char pre[] = { 'A', 'X', 'B', 'D', 'R', 'S', 'C', 'P', 'Q', 'T', 'Y' };
	int length = sizeof(pre) / sizeof(pre[0]); // Find the length of either array to find the end index which is (length -1)

	// Builds the tree from both pre and inOrder arrays and passing the root node back
	struct node *root = buildTree(in, pre, 0, length - 1);

	printf("\n\nGarrett Head\nTree Traversals\n2015\n\n");
	printf("This program will build a tree from the two inOrdered and preOrdered lists,\nthen display the PostOrdered list back to the user along with the PreOrder\nand InOrder traversals\n\n");


	// Prints the results of the traversals
	printf("----------------TRAVERSALS---------------------");
	printf("\n\n PostOrder Traversal: ");
	getPostOrder(root);
	printf("\n\n PreOrder Traversal:  ");
	getPreOrder(root);
	printf("\n\n InOrder Traversal:   ");
	getInOrder(root);

	// Wait for user input before terminating
	getchar();
	return 0;

}

/* This function will find the matching index value (data) in the x[start...end] array
*/
int search(char x[], int start, int end, char data)
{
	int i;
	for (i = start; i <= end; i++)
	{
		if (x[i] == data)
			return i;
	}
}