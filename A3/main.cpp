#include "avl.h"
#include "customErrorClass.h" // task 5

int main() {
    try {
        avl avl;
        
        avl.insert(10);
        avl.insert(14);
        avl.insert(23);
        avl.insert(8);
        avl.insert(7);
        avl.insert(9);
        avl.insert(20);
        avl.insert(25);

        cout << "AVL tree:" << endl;
        avl.print();
        avl.remove(8);

        cout << "AVL tree after removing 8: " << endl;
        avl.print();

    } catch ( MyException &e){
        cerr << e.what() << endl;
    }

    return 0;
}
