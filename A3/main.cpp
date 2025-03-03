#include "avl.h"
#include "customErrorClass.h" // task 5

int main() {
    avl avl;
    avl.insert(10);
    avl.insert(14);
    avl.insert(23);
    avl.insert(8);
    avl.insert(7);
    avl.insert(9);
    avl.insert(20);
    avl.insert(25);

    avl.print();
    avl.remove(8);
    avl.print();

    return 0;
}
