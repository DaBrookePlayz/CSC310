#include "avl.h"

//PUBLIC (mostly task 1)
avl::avl() {
    root = NULL;
}

avl::~avl() {
    destroyTree(root);
}

void avl::insert(int key) {
    insert(root, key);
}

void avl::remove(int key) {
    remove(root, key);
}

void avl::print() {
    printTree(root, 10);
}


// PRIVATE
void avl::destroyTree(Node* node) {
    if (node) {
        destroyTree(node -> left);
        destroyTree(node -> right);
        delete node;
    }
}

int avl::height(Node* node) {
    if (node) {
        return node -> height;
    } else {
        return -1;
    }
}

int avl::balanceFactor(Node* node) {
    if (node) {
        return height(node ->right) - height(node -> left);
        
    } else {
        return 0;
    }
}

Node* avl::rotateRight(Node* y) {
    Node* x = y -> left;
    Node* z = x -> right;
    x -> right = y;
    y -> left = z;

    y -> height = max(height(y -> left), height(y -> right)) + 1;
    x -> height = max(height(x -> left), height(x -> right)) + 1;

    return x;

}

Node* avl::rotateLeft(Node* y) {
    Node* x = y -> right;
    Node* z = x -> left;
    x -> left = y;
    y -> right = z;

    // this **may** be incorrect
    y -> height = max(height(y -> left), height(y -> right)) + 1;
    x -> height = max(height(x -> left), height(x -> right)) + 1;

    return x;

}

Node* avl::insert(Node* node, int key) { // task 2
    
}

Node* avl::remove(Node* node, int key) { // task 3

}

Node* avl::minValueNode(Node* node) { // task 4

}

void avl::printTree(Node* root, int space) { // task 4
    
}

