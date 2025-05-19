#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to insert a node in BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Your findPreSuc function
vector<Node*> findPreSuc(Node* root, int key) {
    Node* pred = NULL;
    Node* succ = NULL;
    while (root != NULL) {
        if (root->data == key) {
            if (root->left != NULL) {
                Node* temp = root->left;
                while (temp->right != NULL) temp = temp->right;
                pred = temp;
            }
            if (root->right != NULL) {
                Node* temp = root->right;
                while (temp->left != NULL) temp = temp->left;
                succ = temp;
            }
            return {pred, succ};
        }
        else if (root->data > key) {
            succ = root;
            root = root->left;
        }
        else {
            pred = root;
            root = root->right;
        }
    }
    return {pred, succ};
}

int main() {
    Node* root = NULL;
    vector<int> keys = {20, 8, 22, 4, 12, 10, 14};
    for (int key : keys) {
        root = insert(root, key);
    }

    int target = 10;
    vector<Node*> result = findPreSuc(root, target);
    Node* pred = result[0];
    Node* succ = result[1];

    if (pred)
        cout << "Predecessor of " << target << " is " << pred->data << endl;
    else
        cout << "No Predecessor for " << target << endl;

    if (succ)
        cout << "Successor of " << target << " is " << succ->data << endl;
    else
        cout << "No Successor for " << target << endl;

    return 0;
}
