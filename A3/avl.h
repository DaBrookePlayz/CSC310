#ifndef AVL_H
#define AVL_H

#include <iostream>
using namespace std;

struct Node {
    int key, height;
    Node* left, *right;

    Node (int value) {
        key = value;
        left = right = NULL;
        height = 0;
    }
};

class avl {
    private:
        Node* root;

        Node* insert(Node* node, int key);
        Node* remove(Node* node, int key);
        Node* minValueNode(Node* node);

        int height(Node* node);
        int balanceFactor(Node* node);

        Node* rotateRight(Node* y);
        Node* rotateLeft(Node* y);

        void printTree(Node* root, int space);
        void destroyTree(Node* node);

    public:
        avl();
        ~avl();

        void insert(int key);
        void remove(int key);
        void print();
};

#endif