#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int FindMaxTime(Node* root, Node* target, unordered_map<Node*, Node*>& mp) {
    queue<Node*> q;
    q.push(target);
    unordered_map<Node*, bool> vis;
    vis[target] = true;
    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        bool fired = false;
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();
            if (temp->left != nullptr && !vis[temp->left]) {
                vis[temp->left] = true;
                fired = true;
                q.push(temp->left);
            }
            if (temp->right != nullptr && !vis[temp->right]) {
                vis[temp->right] = true;
                fired = true;
                q.push(temp->right);
            }
            if (mp[temp] != nullptr && !vis[mp[temp]]) {
                vis[mp[temp]] = true;
                fired = true;
                q.push(mp[temp]);
            }
        }
        if (fired) time++;
    }
    return time;
}

Node* mapToParent(Node* root, int target, unordered_map<Node*, Node*>& mp) {
    queue<Node*> q;
    q.push(root);
    Node* trg = nullptr;
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->data == target)
            trg = temp;
        if (temp->left != nullptr) {
            mp[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right != nullptr) {
            mp[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return trg;
}

int minTime(Node* root, int target) {
    unordered_map<Node*, Node*> mp;
    Node* trg = mapToParent(root, target, mp);
    int time = FindMaxTime(root, trg, mp);
    return time;
}

int main() {
    // Constructing the tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 2;

    int result = minTime(root, target);

    cout << "Minimum time to burn the entire tree from node " << target << " is: " << result << " seconds." << endl;

    // Optional: clean up allocated nodes here if you want

    return 0;
}
