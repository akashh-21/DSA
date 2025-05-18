#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Spiral traversal helper functions
void LeftToRight(Node* root, int level, int curr, vector<int>& ans) {
    if (root == nullptr) return;
    if (level == curr) {
        ans.push_back(root->data);
        return;
    }
    LeftToRight(root->left, level, curr + 1, ans);
    LeftToRight(root->right, level, curr + 1, ans);
}

void RightToLeft(Node* root, int level, int curr, vector<int>& ans) {
    if (root == nullptr) return;
    if (level == curr) {
        ans.push_back(root->data);
        return;
    }
    RightToLeft(root->right, level, curr + 1, ans);
    RightToLeft(root->left, level, curr + 1, ans);
}

int level(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(level(root->left), level(root->right));
}

void levelOrder(Node* root, int level, vector<int>& ans) {
    if (level == 0) return;
    for (int i = 0; i < level; i++) {
        if (i % 2 == 0) {
            RightToLeft(root, i, 0, ans);
        } else {
            LeftToRight(root, i, 0, ans);
        }
    }
}

vector<int> findSpiral(Node* root) {
    int levels = level(root);
    vector<int> ans;
    levelOrder(root, levels, ans);
    return ans;
}

// Main function
int main() {
    /*
          1
         / \
        2   3
       / \ / \
      7  6 5  4
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    vector<int> result = findSpiral(root);

    cout << "Spiral Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
