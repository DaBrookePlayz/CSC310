#include "dsw.h"
#include "customErrorClass.h"
#include<unistd.h>
/*
- exception handling should be in another file, an example may be in d2l
*/

int countRight = 0;

// private
void BST::rotateRight(Node*& node) { // used with left heavy tree
    if (!(node == NULL || node -> left == NULL)) { // i lazy
        // get node to rotate right
        Node* leftChild = node -> left; 
        node -> left = leftChild -> right; // node's right child is gonna become parent's left child
        leftChild -> right = node; // parent is gonna be right child of node that's rotated
        node = leftChild;
    } else {
        throw MyException("myerror");
    }
}


void BST::rotateLeft(Node*& node) { // used with right heavy tree
    if (!(node == NULL || node -> right == NULL)) {
        // get node to rotate left
        Node* rightChild = node -> right; 
        node -> right = rightChild -> left; // nightNode's left child is gonna become parent's right child
        rightChild -> left = node; // parent is gonna be left child of node that is rotated
        node = rightChild;
    } else {
        throw MyException("myerror");
    }
}

void BST::createVine() { // modify this one
    if (root != NULL) {
        Node* grandparent = NULL;
        Node* parent = root;
        Node* child = root -> left;
        int count = 0;
        Node* childRight = root -> right;

        while (parent != NULL) {
            if (countSize(childRight) >= 2) { // 1a
                rotateLeft(parent);
            }

            if (childRight != NULL) { // 1b
                if (parent == root)
                    return;
                rotateLeft(parent); 
                if ((grandparent == nullptr || grandparent == root) ) {
                    root = parent;
                } else {
                    grandparent->left = parent;
                }
                childRight = parent->right;
            } else {
                grandparent = parent;
                parent = parent->right;
                if (parent != nullptr) {
                    childRight = parent->left;
                }
            }
        }

        cout << "right rotations: " + to_string(count) << endl; // 2b
    } else {
        throw MyException("myerror");
    }
}

void BST::rebuildTree(int size) {
    // Init rotation
    int countInit = 0;
    int highPowTwo = 2*log2(size+1);
    int exNodes = (size + 1) - (1 << (highPowTwo / 2)); // 2c
    performRotation(exNodes);

    countInit++; // 2b
    cout << "init rotations: " + to_string(countInit) << endl;

    // other rotations
    for (size = (size - exNodes) / 2; size > 0; size /= 2) { // 2c
        performRotation(size);
    }

    cout << "Right rotations: " + to_string(countRight) << endl;
}

void BST::performRotation(int count) {
    Node* grandparent = NULL;
    Node* parent = root;
    Node* child = root -> left;

    for (int i = 0; i < count; i++) {
        if (child == NULL) {
            throw MyException("myerror");
            break; // may change
        }

        rotateRight(parent);
        countRight++;

        if (grandparent == NULL) {
            root = parent;
        } else {
            grandparent -> left = parent;
        }

        grandparent = parent;
        parent = parent -> left;
        if (parent != NULL) {
            child = parent -> left;
        }
    }
}

void BST::printTree(Node* root, int space) {
    const int COUNT = 10; 

    if (root == NULL) {
        return;
    }

    // Increase the distance between levels
    space += COUNT;

    // Print the right child first (to appear on top)
    printTree(root->right, space);

    // Print the current node after right child

    for (int i = COUNT; i < space; i++) {
        cout << " "; // Indentation for tree depth
    }
    cout << root->data << endl;

    // Print the left child
    printTree(root->left, space);
}

int BST::countSize(Node* root) { // 1b
    // recursively go down until reach leaf and count it
    if (root == NULL) { 
        return 0;
    } else {
        return 1 + countSize(root->left) + countSize(root->right);
    }

}

// public
BST::BST() {
    root = NULL;
}

BST::~BST() {
   deleteTree(root);
}

void BST::deleteTree(Node*& node) {
    if (node != NULL) {
        deleteTree(node -> left);
        deleteTree(node -> right);
    }
}

void BST::insert(int val) {
   Node* newNode = new Node(val);
   if (root == NULL) {
       root = newNode;
   } else {
       Node* current = root;
       Node* parent = NULL;

       while (current != NULL) {
           parent = current;
           if (val < current -> data) {
               current = current -> left;
           } else {
               current = current -> right;
           }
       }

       if (val < parent -> data) {
           parent -> left = newNode;
       } else {
           parent -> right = newNode;
       }
   }
}

void BST::dswBalance() {
    if (root != NULL) {
        createVine();

        cout << "after phase 1: ";
        display();

        int size = 0;
        Node* temp = root;
        while (temp != NULL) {
            size++;
            temp = temp -> left;
        }
       
        // phase 2
        rebuildTree(size);

        cout << "size: " + to_string(countSize(root)) << endl;
    } else {
        throw MyException("myerror");
    }
}

void BST::display() {
    cout << endl;
    printTree(root, 0);
    cout << endl;
}