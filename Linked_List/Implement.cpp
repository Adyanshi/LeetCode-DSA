// Implementing the Linked List using struct


// Struct is a user-defined data type in C/C++. It is used to store a group of different data types together.

// A struct in C/C++ is a collection of variables (can be of different types) under a single name.It is defined using the keyword struct.

// Syntax:
// struct structure_name {
//     data_type member1;
//     data_type member2;
//     .
//     .
//     .
//     data_type memberN;
// };

// we can also create linked list using class, struct does not support object oriented programming concepts like inheritance, polymorphism etc.

// struct is used to create a simple linked list.

// A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers.

// In simple words, a linked list consists of nodes where each node contains a data field and a reference(link) to the next node in the list.

// The first node is called the head and the last node is called the tail. The tail points to NULL.

// The linked list is a dynamic data structure, which means that the size of the linked list can be changed during the execution of the program.

// The linked list is used to implement stacks, queues, graphs, etc.

#include<bits/stdc++.h>
using namespace std;

// Define the structure of the node
struct Node { //just change struct to class to make it a class
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


//Node and Node* Difference
// Node* is a pointer to a Node object. It is used to store the address of the Node object.It is used to traverse the linked list.
// Node is a Node object. It is used to create a new Node object. It is used to store the data and the address of the next Node object.


// Coverting the array to linked list
Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp; // or mover = mover->next;
    }
    return head; 
}

// Length of the linked list
int lengthLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

// Display the linked list
void displayLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Find if number is present in the linked list
int checkifPresent(Node* head, int x){
    Node* temp = head;
    while(temp){
        if(temp->data == x){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* y= new Node(arr[0]);
    cout<<y->data<<endl;
    Node* head = convertArr2LL(arr);
    Node* temp = head;

    displayLL(head); //for displaying linked list 
     
    cout<<lengthLL(head)<<endl; //for length of linked list

    cout<<checkifPresent(head, 3)<<endl; //for checking if number is present in linked list
    return 0;   
    
}