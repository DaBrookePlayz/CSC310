#include "splay.h"

int main() {
    SplayTree tree;

    tree.insert(57);
    tree.insert(30); // changed from 31
    tree.insert(72);
    tree.insert(40); // changed from 44
    tree.insert(69);
    tree.insert(83);

    cout << "Tree after insertions: \n";
    tree.display();

    tree.search(40);
    cout << "Tree after splaying 40: \n";
    tree.display();

    tree.remove(30);
    cout << "Tree after deleting 30: \n";
    tree.display();

    return 0;
}
