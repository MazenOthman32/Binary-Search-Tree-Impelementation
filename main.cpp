#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left, *right;

    node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    node *root = nullptr;

public:
    void insert(int value) {
        node *newNode = new node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        node *current = root;
        node *parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    bool search(int value) {
        node *current = root;

        while (current != nullptr) {
            if (value == current->data)
                return true;
            else if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }

        return false;
    }

    void inorder(node *begin) {
        if (begin == nullptr) return;
        inorder(begin->left);
        cout << begin->data << " ";
        inorder(begin->right);
    }

    node* getRoot() {
        return root;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(100);
    tree.insert(10);
    tree.insert(60);
    tree.insert(580);
    tree.insert(2);

    if (tree.search(60))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    tree.inorder(tree.getRoot());
}
