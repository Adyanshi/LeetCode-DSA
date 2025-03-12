#include<bits/stdc++.h>
using namespace std;


// Making of Node is same as in Implement.cpp
class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Insert at the head(Start)
Node* insertHead(Node* head, int val){
    // Node* newNode = new Node(val, head);
    // return newNode;
    return new Node(val, head); // same as above
}

// Insert at the tail(End)
Node* insertTail(Node* head, int val){
    if (head == nullptr) {
        return new Node(val);
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

// Insert at kth position
Node* insertKth(Node* head, int val, int k) {
    if (head == nullptr) {
        if(k==1) return new Node(val);
        else return NULL;
    }
    if (k == 1) {
        return new Node(val, head);
    }
    Node* temp = head;
    int count = 0;
    while(temp!=NULL) {
        count++;
        if(count == k-1) {
            temp->next = new Node(val, temp->next);
            break;
        }
        temp = temp->next;
    }
    return head;
}

// Insert element before the given value
Node* insertBefore(Node* head, int val, int x) {
    if (head == nullptr) {
        return NULL;
    }
    if (head->data == x) {
        return new Node(val, head);
    }
    Node* temp = head;
    while(temp->next!=NULL) {
        if(temp->next->data == x) {
            temp->next = new Node(val, temp->next);
            break;
        }
        temp = temp->next;
    }
    return head;
}