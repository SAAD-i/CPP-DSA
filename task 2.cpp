#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == NULL) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = NULL;
        while (current !=NULL ) {
            parent = current;
            if (value < current->data) {
                current = current->left;
            } else if (value > current->data) {
                current = current->right;
            } else {
                
                delete newNode;
                return;
            }
        }

        if (value < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    void printLeftDescendants() {
        if (root == NULL) {
            cout << "The tree is empty." << endl;
            return;
        }

        cout << "Left descendants with a null value for the left pointer: ";
        printLeftDescendants(root);
        cout << endl;
    }

private:
    void printLeftDescendants(Node* node) {
        if (node == NULL) {
            return;
        }

        if (node->left != NULL && node->left->left == NULL) {
            cout << node->left->data << " ";
        }

        printLeftDescendants(node->left);
        printLeftDescendants(node->right);
    }
};

int main() {
    BST bst;

    bst.insert(20);
    bst.insert(10);
    bst.insert(25);
    bst.insert(5);
    bst.insert(15);
    bst.insert(17);
    bst.insert(22);
    bst.insert(30);

    bst.printLeftDescendants();

    return 0;
}

