#include "bstP.h" 
MyException excp("My Error");
// I could NOT get the #ifndef thing to work with Types so I renamed bstP.cpp to bstPo.h
// this wont affect the result at all but its sort of not what was asked in the assignment so... idk
// theres still 3 files and at least one header file though :D

template <class Type>
BST<Type>::BST() {
	root = NULL;
}

template <class Type>
BST<Type>::~BST() {
    clearTree(root);
}

template <class Type>
void BST<Type>::inorder(Node<Type> *p) { 
		if (p != NULL)
		{
			inorder(p->llink);
			cout << p->info << " ";
			inorder(p->rlink);
		} else if (root == NULL) {
            throw MyException("Binary tree is empty!");
        }
        //cout << endl;
	}

template <class Type>
void BST<Type>::preorder(Node<Type> *p) {
    if (p != NULL) {
        cout << p->info << " ";
        preorder(p->llink);
        preorder(p->rlink);
    } else if (root == NULL) {
        throw MyException("Binary tree is empty!");
    }
    //cout << endl;
}

template <class Type>
void BST<Type>::postorder(Node<Type> *p) {
    if (p != NULL) {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->info << " ";
    } else if (root == NULL) {
        throw MyException("Binary tree is empty!");
    }
    //cout << endl;
}

template <class Type>
int BST<Type>::height(Node<Type> *p) {
    if (p == NULL) { 
        return 0;
    } else if (root == NULL) {
        throw MyException("Binary tree is empty!");
    } else {
        int leftHeight = height(p->llink);
        int rightHeight = height(p->rlink);

        if (leftHeight >= rightHeight) {
            return 1 + leftHeight;
        } else {
            return 1 + rightHeight;
        }
    }
}

template <class Type>
int BST<Type>::nodeCount(Node<Type> *p) {
    if (p == NULL) {
        return 0;
    } else if (root == NULL) {
        throw MyException("Binary tree is empty!");
    } else {
        return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
    }
}

template <class Type>
bool BST<Type>::isBalanced() { 
    if (nodeCount(root -> llink) > nodeCount(root -> rlink)) {
        cout << "tree heavier on left" << endl;
        return false;
    } else if (nodeCount(root -> llink) > nodeCount(root -> rlink)) {
        cout << "tree heavier on right" << endl;
        return false;
    } else {
        cout << "your'e did it" << endl;
        return true;
    }
}

template <class Type>
void BST<Type>::clearTree(Node<Type>*& p) {
    if (p != NULL) {
        clearTree(p->llink);
        clearTree(p->rlink);
        delete p;
        p = NULL;
    } else if (root == NULL) {
        throw MyException("Binary tree is already empty!");
    }
}

template <class Type>
bool BST<Type>::searchNode(const Type& x) {
		Node<Type> *current;
		bool found = false;

		if (this -> root == NULL) {
            throw MyException("Binary tree is empty!");
			return NULL;
		} else {
			current = this -> root;

			while (current != NULL && !found) {
				if (current -> info == x) {
					found = true;
				} else if (current -> info > x) {
					current = current -> llink;
				} else {
					current = current -> rlink;
				}
			}
		}
		return found;
	}

template <class Type>
void BST<Type>::insertNode(const Type& x)
{
    Node<Type>* current, *prevCurrent=NULL, *newNode;
    newNode = new Node<Type>;
    assert(newNode != NULL);
    newNode->info = x;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (this->root == NULL)
        this->root = newNode;
    else
    {
        current = this->root;
        while (current != NULL)
        {
            prevCurrent = current;
            if (current->info == x)
            {
                //cout << "Item is already in the list!" << endl;
                throw MyException("Item is already in the list!");
                return;
            }
            else
                if (current->info > x)
                    current = current->llink;
                else
                    current = current->rlink;
        }
        
        if (prevCurrent->info > x)
            prevCurrent->llink = newNode;
        else
            prevCurrent->rlink = newNode;
    }
}

template <class Type>
void BST<Type>::deleteNode(const Type& x)
{
    Node<Type>* current;
    Node<Type>* prevCurrent;
    bool found = false;
    if (this->root == NULL)
        //cout << "Cannot delete from an empty tree!" << endl;
        throw MyException("Cannot delete from an empty tree!");
    else
    {
        current = this->root;
        prevCurrent = this->root;
        while (current != NULL && !found)
        {
            if (current->info == x)
                found = true;
            else
            {
                prevCurrent = current;
                if (current->info > x)
                    current = current->llink;
                else
                    current = current->rlink;
            }
        }
        if (current == NULL)
            //cout << "The item is not in the tree!" << endl;
            throw MyException("The item is not in the tree!");
        else if (found)
        {
            if (current == this->root)
                deleteFromTree(this->root);
            else
                if (prevCurrent->info > x)
                    deleteFromTree(prevCurrent->llink);
                else
                    deleteFromTree(prevCurrent->rlink);
        }
    }

}

template <class Type>
void BST<Type>::deleteFromTree(Node<Type>*& p) {
		Node<Type>* current, *prevCurrent, *temp;
		if (p == NULL)
			//cout << "The node to be deleted is NULL!" << endl;
            throw MyException("The node to be deleted is NULL!");
		else if (p->llink == NULL && p->rlink == NULL) //p points to a leaf
		{
			temp = p;
			p = NULL;
			delete temp;
		}
		else if (p->llink == NULL) //p points to a node with only a right child  
		{
			temp = p;
			p = temp->rlink;
			delete temp;
		}
		else if (p->rlink == NULL) //p points to a node with only a left child 
		{
			temp = p;
			p = temp->llink;
			delete temp;
		}
		else //p points to a node with two children
		{
			current = p->llink;
			prevCurrent = NULL;
			while (current->rlink != NULL)
			{
				prevCurrent = current;
				current = current->rlink;
			}
			p->info = current->info;
			if (prevCurrent == NULL)   //current did not move, current = p->llink, adjust p
				p->llink = current->llink;
			else
				prevCurrent->rlink = current->llink;
			delete current;
		}
	}

/*
node::node(int value)
{
    data = value;
    leftChild = nullptr;
    rightChild = nullptr;
}

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    clearTree(root);
    // or call deleteNode
}

void BST::clearTree(node* node)
{
    if (root == nullptr)
        return;

    clearTree(node->leftChild);
    clearTree(node->rightChild);
    delete node;
}

void BST:: insertNode(node*& root, int data)
{
    // complete this
}

node* BST:: searchNode(node*& root, int data)
{
    // complete this
}

void BST:: deleteNode(node*& root, int data)
{
    // complete this
}


void BST::preorder(node* root)
{
    // complete this
}
void BST::inorder(node* root)
{
    // complete this
}
void BST::postorder(node* root)
{
    // complete this
}

int BST::height(node* node)
{
    // complete this
}
bool BST:: isBalanced(node* root)
{
    // complete this
}*/

template <class Type>
void BST<Type>::printTree(Node<Type>* root, int space) {
    const int COUNT = 10; 

    if (root == NULL) {
        //throw MyException("Binary tree is empty!");
        // above exception causes recursion to fail due to how root is used here
        return;
    }

    // Increase the distance between levels
    space += COUNT;

    // Print the right child first (to appear on top)
    printTree(root->rlink, space);

    // Print the current node after right child

    for (int i = COUNT; i < space; i++) {
        cout << " "; // Indentation for tree depth
    }
    cout << root->info << endl;

    // Print the left child
    printTree(root->llink, space);
}


