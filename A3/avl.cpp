#include "avl.h"
#include "customErrorClass.h"

// PUBLIC
avl::avl() { // in class
    root = NULL;
}

avl::~avl() { // in class
    destroyTree(root);
}

void avl::insert(int key) { // task 1
    root = insert(root, key);
}

void avl::remove(int key) { // task 1
    root = remove(root, key);
}

void avl::print() { // task 1
    cout << endl;
    printTree(root, 0);
    cout << endl;
}


// PRIVATE
void avl::destroyTree(Node* node) { // in class
    if (node) {
        destroyTree(node -> left);
        destroyTree(node -> right);
        delete node;
    }
}

int avl::height(Node* node) { // in class
    if (node == NULL) {
        return 0;
    }
    
    return node -> height;
}

int avl::balanceFactor(Node* node) { // in class
    if (node == NULL) {
        return 0;
    }

    return height(node -> left) - height(node -> right);
}

Node* avl::rotateRight(Node* y) { // in class
    if (root == NULL) {
        throw MyException("myerror");
    }

    Node* x = y -> left;
    Node* z = x -> right;
    x -> right = y;
    y -> left = z;

    y -> height = max(height(y -> left), height(y -> right)) + 1;
    x -> height = max(height(x -> left), height(x -> right)) + 1;

    return x;
}

Node* avl::rotateLeft(Node* y) { // in class
    if (root == NULL) {
        throw MyException("myerror");
    }

    Node* x = y -> right;
    Node* z = x -> left;
    x -> left = y;
    y -> right = z;

    y -> height = max(height(y -> left), height(y -> right)) + 1;
    x -> height = max(height(x -> left), height(x -> right)) + 1;

    return x;
}

Node* avl::insert(Node* node, int key) { // task 2
    // Perform the normal BST insertion
    if (node == nullptr)
            return new Node(key);

        if (key < node->key) 
            node->left = insert(node->left, key); 
        else if (key > node->key) 
            node->right = insert(node->right, key); 
        else // Equal keys are not allowed in BST 
            return node; 

        // Update height of this ancestor node 
        node->height = 1 + max(height(node->left),
                            height(node->right)); 

        // Get the balance factor of this ancestor node 
        int balance = balanceFactor(node);; 

        // fixing unbalanced tree
        if (balance > 1) { // left...
            if (key < node->left->key) { // left
                return rotateRight(node); 
            } else if (key > node->left->key) { // right
                node->left = rotateLeft(node->left); 
                return rotateRight(node); 
            }
        } else if (balance < -1) { // right...
            if (key > node->right->key) { // right
                return rotateLeft(node);  
            } else if (key < node->right->key) { // left
                node->right = rotateRight(node->right); 
                return rotateLeft(node); 
            }
        }

    // Return the (unchanged) node pointer 
    return node; 

}

Node* avl::remove(Node* node, int key) { // task 3
    // generic BST deletion
    if (root == NULL) {
        throw MyException("myerror");
    } else if (node == NULL) {
        return node;

    } else if (key < node -> key) {
        node -> left = remove(node -> left, key);

    } else if (key > node -> key) {
        node -> right = remove(node -> right, key);

    } else { // we found the key, bois
        if ((node -> left == NULL) || (node -> right == NULL)) { // Node with only one child or no child
            Node* temp = node -> left ? node -> left : node -> right; // cool trick
            if (temp == NULL) {
                temp = node;
                node = NULL;

            } else {
                *node = *temp;
            }

            delete temp;

        } else { // node with 2 children
            Node* temp = minValueNode(node -> right);
            node -> key = temp -> key;
            node -> right = remove(node -> right, temp -> key);

        }
    }

    if (node == NULL)
        return node;

    // Update height of current node
    node->height = 1 + max(height(node->left), height(node->right));
    // Get the balance factor of this node
    int balance = balanceFactor(node);

    // if node is unbalanced, then go through cases
    if (balance > 1) {
        if (balanceFactor(node->left) >= 0) { // Left Left Case
            return rotateRight(node);

        } else if (balanceFactor(node->left) < 0) { // Left Right Case
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    } else if (balance < -1) {
        if (balanceFactor(node->right) <= 0) { // Right Right Case
            return rotateLeft(node);

        } else if (balanceFactor(node->right) > 0) { // Right Left Case
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

Node* avl::minValueNode(Node* node) { // task 4
    Node* current = node;
    if (current == NULL) {
        throw MyException("myerror");
    }
    
    while (current -> left != NULL) {
        current = current -> left;
    }

    return current;
}

void avl::printTree(Node* root, int space) { // task 4
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
    cout << root -> key << endl;

    // Print the left child
    printTree(root->left, space);
}

