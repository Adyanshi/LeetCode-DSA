#include<bits/stdc++.h>
using namespace std;

// Implementing Doubly Linked List same as in Doubly_Implement.cpp
class Node
{
public:
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
Node *removeHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;

    return head;
}

// At tail (End)
Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    temp->prev = NULL;
    delete temp;
    return head;
}

// At kth position
Node *removeKth(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int count = 0;
    Node *kNode = head;
    while (kNode != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        kNode = kNode->next;
    }
    Node *prev = kNode->prev;
    Node *front = kNode->next;

    if (prev == NULL && front == NULL)
    {
        delete kNode;
        return NULL;
    }

    else if (prev == NULL)
    {
        return removeHead(head);
    }

    else if (front == NULL)
    {
        return removeTail(head);
    }

    prev->next = front;
    front->prev = prev;
    kNode->next = NULL;
    kNode->prev = NULL;
    delete kNode;
    return head;
}

// At Node, Node!=head
void deletNode(Node* temp){
    Node* next = temp->next;
    Node* prev = temp->prev;

    if(next == NULL){
        prev->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    prev->next = next;
    next->prev = prev;
    temp->next = NULL;
    temp->prev = NULL;

    delete temp;
    
}