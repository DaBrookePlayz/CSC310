#include "splay.h"

SplayTree::SplayTree() 
{
    root = nullptr; 
}

// aka Zig
SplayTree::Node* SplayTree::rotateRight(Node* x) { // doesn't require error handling
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// aka Zag
SplayTree::Node* SplayTree::rotateLeft(Node* x) { // doesn't require error handling
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

SplayTree::Node* SplayTree::splay(Node* root, int key) { // task 1
    if (root == NULL || root->key == key) { // if root is null or key is root 
        return root; 

    } else if (root -> key > key) { // Key in left subtree 
        if (root -> left == NULL) { // Key not in tree, we done
            return root; 

        } else if (root -> left -> key > key) { // Zig-Zig or left x2
            root -> left -> left = splay(root -> left -> left, key); // bring the key as root of left-left              
            root = rotateRight(root); // first rotation for root, second rotation is done below

        } else if (root -> left -> key < key) { // Zig-Zag or left-right
            root -> left -> right = splay(root -> left -> right, key); // bring key as root of left-right 
            
            if (root -> left -> right != NULL) // first rotation for root->left 
                root -> left = rotateLeft(root -> left); 
        } 

        return (root -> left == NULL)? root: rotateRight(root); // second rotation

    } else { // Key in right subtree 
        if (root -> right == NULL) { // Key not in tree, we done 
            return root; 

        } else if (root -> right->key > key) { // Zig-Zag or right-left
            root -> right -> left = splay(root -> right -> left, key); // Bring key as root of right-left 

            if (root -> right -> left != NULL) { // first rotation for root->right 
                root -> right = rotateRight(root -> right); 
            }
        } else if (root -> right -> key < key) { // Zag-Zag or right x2 
        
            root -> right -> right = splay(root -> right -> right, key); // Bring key as root of right-right and do first rotation 
            root = rotateLeft(root); 
        } 

        return (root -> right == NULL)? root: rotateLeft(root); // Do second rotation for root 
    } 
}

SplayTree::Node* SplayTree::insertNode(Node* root, int value) { // task 2
    // Simple Case: If tree is empty 
    if (root == NULL){
        Node* node1 = new Node(value);
        node1->left = node1->right = NULL; 
        return node1;
    } 

    // Bring the closest leaf node to root 
    root = splay(root, value); 

    // If key is already present, then return 
    if (root->key == value) return root; 

    // Otherwise allocate memory for new node 
    Node* node2 = new Node(value);
    node2->left = node2->right = NULL;
    Node* newnode = node2;

    // If root's key is greater, make 
    // root as right child of newnode 
    // and copy the left child of root to newnode 
    if (root->key > value) 
    { 
        newnode->right = root; 
        newnode->left = root->left; 
        root->left = NULL; 
    } 

    // If root's key is smaller, make 
    // root as left child of newnode 
    // and copy the right child of root to newnode 
    else
    { 
        newnode->left = root; 
        newnode->right = root->right; 
        root->right = NULL; 
    } 

    return newnode; // newnode becomes new root   
}

SplayTree::Node* SplayTree::deleteNode(Node* root, int key) { // task 2
    if (root == NULL) {
        return NULL;

    } else {
        root = splay(root, key); // Splay the key
        
        if (key != (root -> key)) { // If key not present
            return root;
        }
    
        Node* temp = root;

        // If root's left child does not exist, make root -> right as root
        if (!(root -> left)) {
            root = root -> right;
        } else { // left child exits
            root = splay(root->left, key);
            root -> right = temp -> right; // Make previous root's right child as new root's right child
        }
    
        free(temp); // free allocated space for deleted node
        return root; // return root of the new Splay Tree
    }
}


void SplayTree::insert(int key) { // helper function
    root = insertNode(root, key);
}


void SplayTree::remove(int key) { // helper function
    root = deleteNode(root, key);
}


bool SplayTree::search(int key) { // just in case...
    if (root != NULL) {
        root = splay(root, key);
        return (root && root->key == key);
    } else {
        return false;
    }
}


void SplayTree::printTree(Node* root, int space) { // same as BST
    const int COUNT = 10; 

    if (root == nullptr) {
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
    cout << root->key << endl;

    // Print the left child
    printTree(root->left, space);
}

void SplayTree::display() { // helper function
    printTree(root, 0);
    cout << endl;
}
