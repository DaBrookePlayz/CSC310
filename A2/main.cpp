#include "dsw.h"
#include "customErrorClass.h"

int main() {
    try {
        BST bst;
        bst.insert(10);
        bst.insert(14);
        bst.insert(23);
        bst.insert(8);
        bst.insert(7);
        bst.insert(9);
        bst.insert(20);
        bst.insert(25);
        
        cout << "Original BST: ";
        bst.display();

        bst.dswBalance();

        cout << "DSW balanced BST: ";
        bst.display();
        
    }  catch (MyException &e){
        cerr<<e.what()<<endl;
    }

    return 0;
}

