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

// Removing from the head(Start)
Node* removeHead(Node* head){
    if(head == NULL){ //edge case, already empty
        return Head;
    }
    Node* temp = head;
    head = head->next;
    delete temp; // can use free(temp) also
    return head;
}

// Removing from the tail(End)
Node* removeTail(Node* head){
    if(head == NULL || head->next==NULL){ //edge case, already empty
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next; // can use free(temp->next) also
    temp->next = nullptr;
    return head;
}

//Removing from kth position
Node* removeKth(Node* head, int k){
    if(head==NULL){
        return head;
    }
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count=0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        count++;
        if(count==k){
            prev->next = temp->next; //or prev->next = prev->next->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next; 
    }
}

// Removing using the value
Node* reoveEl(Node* head, int x){
    if(head==NULL){
        return head;
    }
    if(head->data == x){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        if(temp->data == x){
            prev->next = temp->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
