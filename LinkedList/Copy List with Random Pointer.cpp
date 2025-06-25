#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Step 1: Create a duplicate list with only 'val' and 'next'
        Node* dummy = new Node(-1);
        Node* temp = head;
        Node* dtemp = dummy;
        while(temp != NULL) {
            Node* newNode = new Node(temp->val);
            dtemp->next = newNode;
            temp = temp->next;
            dtemp = dtemp->next;
        }

        // Step 2: Map original nodes to their corresponding copied nodes
        unordered_map<Node*, Node*> nodeMap;
        Node* original = head;
        Node* copy = dummy->next;
        while(original != NULL) {
            nodeMap[original] = copy;
            original = original->next;
            copy = copy->next;
        }

        // Step 3: Set random pointers using the map
        for(auto pair : nodeMap) {
            Node* originalNode = pair.first;
            Node* copiedNode = pair.second;
            if(originalNode->random != NULL) {
                copiedNode->random = nodeMap[originalNode->random];
            }
        }

        return dummy->next;
    }
};

// Sample usage
int main() {
    // Example: create a list with nodes and random pointers manually
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    Solution sol;
    Node* copiedHead = sol.copyRandomList(head);

    // Output the copied list to verify correctness
    while(copiedHead != NULL) {
        cout << "Val: " << copiedHead->val << ", Random: ";
        if(copiedHead->random) cout << copiedHead->random->val << endl;
        else cout << "NULL" << endl;
        copiedHead = copiedHead->next;
    }
    return 0;
}
