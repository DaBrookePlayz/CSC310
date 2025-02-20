#include "bstPo.h"
#include <stdio.h>
using namespace std;
// Feel free to modify this

int main (int argc, char *argv[])
{
    if (argc != 2) {
        cerr << "Usage: ./a <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    BST<int> tree;

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        int command, data;

        iss >> command;

        switch (command) {
            case 0:
                cout << "Exiting...!\n";
                return 0;
            case 1:
                try {
                    iss >> data;
                    tree.insertNode(data);
                    cout << "Insert: " << data << endl;
                } catch (MyException &e) {
                    cerr << e.what() << endl;
                }
                break;
            case 2:
                try {
                    iss >> data;
                    cout << tree.searchNode(data) << endl;
                } catch (MyException &e) {
                    cerr << e.what() << endl;
                }
                break;
            case 3:
                try {
                    iss >> data;
                    tree.deleteNode(data);
                } catch (MyException &e) {
                    cerr << e.what() << endl;
                }
                break;
            case 4:
                try {
                    cout << "Inorder traversal: ";
                    tree.inorder(tree.root);
                    cout << endl;
                } catch (MyException &e) {
                    cerr << e.what() << endl;
                }
                break;
            case 5:
                try {
                    cout << "Preorder traversal: ";
                    tree.preorder(tree.root);
                    cout << endl;
                } catch (MyException &e) {
                    cerr << e.what() << endl;
                }
                break;
            case 6:
                try {
                    cout << "Postorder traversal: ";
                    tree.postorder(tree.root);
                    cout << endl;
                } catch (MyException &e) {
                    cerr << e.what() << endl;
                }
                break;
            case 7:
                try {
                    cout << "Binary Search Tree" << endl;
                    tree.printTree(tree.root, 0);
                    cout<<endl;
                } catch (MyException &e) {
                    cerr << e.what() << endl;
                }
                break;
            default:
                cout << "Invalid command." << endl;
        }
    }

    return 0;
}