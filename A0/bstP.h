#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <assert.h>
#include "customErrorClass.h"
using namespace std;

template<class Type>
struct Node {
	Type info;
	Node<Type> *llink;
	Node<Type> *rlink;
};

template <class Type>
class BST {
// taken from BinaryTree
public:
	// originally BinarySearch protected
    Node<Type> *root;

	// originally BinarySearch public
	BST();
	~BST();

	// originally BinarySearch private
	void inorder(Node<Type> *p);

	void preorder(Node<Type> *p);

	void postorder(Node<Type> *p);

	int height(Node<Type> *p);

	int nodeCount(Node<Type> *p);

    bool isBalanced();

	void clearTree(Node<Type>*& p);

 // BinarySearchTree
	bool searchNode (const Type& x);

	void insertNode(const Type& x);

	void deleteNode(const Type& x);

	void deleteFromTree(Node<Type>*& p);

	// from original code
	void printTree(Node<Type>* root, int space);
};

/* original code
#ifndef BSTP_H
#define BSTP_H

//...

struct node
{
    int data;
    struct node* leftChild;
    struct node* rightChild;

    node(int value);
};

class BST {
    public:
        node* root;

        BST();
        ~BST();
        void clearTree(node* node);

        void insertNode(node*& root, int data); 
        node* searchNode(node*& root, int data);
        void deleteNode(node*& root, int data);

        void preorder(node* root);
        void inorder(node* root);
        void postorder(node* root);

        
        int height(node* node);
        bool isBalanced(node* root);

        void printTree(node* root, int space);

};

#endif */