#ifndef DSW_H
#define DSW_H

#include <iostream>
#include <math.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
private: // just all helper functions (except root we allow them)
    Node* root;
    void rotateRight(Node*& node);
    void rotateLeft(Node*& node);
    void createVine(); // part 1
    void rebuildTree(int size);
    void performRotation(int count);
    void printTree(Node* root, int space);

    int countSize(Node* root); // for 1b
public:
    BST();
    ~BST();
    void deleteTree(Node*& node); // "helper" for deconstructor
    void insert(int val);
    void dswBalance();
    void display();
};

#endif