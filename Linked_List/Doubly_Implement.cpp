#include<bits/stdc++.h>
using namespace std;

// Implementing Doubly Linked List
class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

// Convert Array to Doubly Linked List
Node* convertArr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// Display Doubly Linked List
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}