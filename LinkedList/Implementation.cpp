#include<iostream>
using namespace std;
class Node{
    public:
        int val;
        Node* next;
        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};
int getSize(Node* head){
    int size = 0;
    Node* temp = head;
    while(temp!=NULL){
        size++;
        temp = temp->next;
    }
    return size;
}
void insertNodeAtEnd(Node* head,int x){
    Node* newNode = new Node(x);
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
Node* insertNodeAtHead(Node* head,int x){
    Node* newNode = new Node(x);
    Node* temp = head;
    head = newNode;
    newNode->next = temp;
    return head;
}
void insertNodeAtK(Node* head,int x,int k){
    int size = getSize(head);
    if(k==1) head = insertNodeAtHead(head,x);
    else if(size==k) insertNodeAtEnd(head,x);
    else{
        Node* newNode = new Node(x);
        Node* temp = head;
        while(temp!=NULL && k>2){
            temp = temp->next;
            k--;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
Node* deleteNodeAtHead(Node* head){
    head = head->next;
}
void deleteNodeAtEnd(Node* head){
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
void deleteNodeAtK(Node* head,int k){
    if(k==1) head = deleteNodeAtHead(head);
    else if(getSize(head)==k) deleteNodeAtEnd(head);
    else{
        // Node* temp = head;
        // int t = 1;
        // while(temp!=NULL && t<k-1){
        //     temp = temp->next;
        //     t++;
        // }
        // temp->next = temp->next->next;
        // using slow fast pointers
        Node* slow = head;
        Node* fast = head;
        while(k>0){
            fast = fast->next;
            k--;
        }
        while(fast!=NULL && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
    }
}
int getKthElementFromEnd(Node* head,int k){
    if(k==1) return head->val;
    Node* slow = head;
    Node* fast = head;
    while(k--){
        fast = fast->next;
    }
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->next->val;

}
int getKthElement(Node* head,int k){
    Node* temp = head;
    while(k--){
        temp = temp->next;
    }
    return temp->val;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 8;
    Node* head = new Node(arr[0]);
    for(int i=1;i<n;i++){
        insertNodeAtEnd(head,arr[i]);
    }
    cout<<"Inserting the Nodes........"<<endl;
    head = insertNodeAtHead(head,0);
    insertNodeAtK(head,-1,5);
    insertNodeAtEnd(head,9);
    print(head);
    
    cout<<endl<<"deleting the Nodes.........."<<endl;
    head = deleteNodeAtHead(head);
    deleteNodeAtEnd(head);
    deleteNodeAtK(head,4);
    print(head);
    cout<<endl<<getKthElementFromEnd(head,5);
    cout<<endl<<getKthElement(head,5);
    
    return 0;
}