#include<bits/stdc++.h>
using namespace std;

// Implementing Doubly Linked List same as in Doubly_Implement.cpp
class Node
{public:    
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

// At head (Start)
Node* insertBeforeHead(Node* head, int val){
    Node* newNode = new Node(val, head, NULL);
    // if(head!=NULL){
    //     head->prev = newNode;
    // }
    head->prev = newNode;

    return newNode;
}

// At tail (End) Before tail
Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL){
        return insertBeforeHead(head, val);
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->prev;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->prev = newNode;
    return head;
}

// At kth position
Node* insertBeforeKth(Node* head, int val, int k){
    if(k == 1){
        return insertBeforeHead(head, val);
    }
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        if(count==k)break;
        temp = temp->next;
    }
    Node* prev = temp->prev;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->prev = newNode;
    return head;
}

// Before given Node
void insertBeforeNode(Node* head, Node* givenNode, int val){
    Node* prev = givenNode->prev;
    Node* newNode = new Node(val, givenNode, prev);
    prev->next = newNode;
    givenNode->prev = newNode;
}