#include <iostream>
using namespace std;

// Node structure for a singly linked list
struct Node {
    int data;
    Node* next;
};

// Linked list structure
struct LinkedList {
    Node* head;

    LinkedList() { 
        head = nullptr;
    }
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(LinkedList& list, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = list.head;
    list.head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(LinkedList& list, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (list.head == nullptr) {
        list.head = newNode;
        return;
    }
    Node* temp = list.head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with a given value from the list
void deleteNode(LinkedList& list, int data) {
    if (list.head == nullptr) {
        return;
    }
    if (list.head->data == data) {
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
        return;
    }
    Node* prev = nullptr;
    Node* current = list.head;
    while (current != nullptr && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        return;
    }
    prev->next = current->next;
    delete current;
}

// Function to display the elements of the list
void display(const LinkedList& list) {
    Node* temp = list.head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code to test the implementation
int main() {
    LinkedList linkedList;
    insertAtBeginning(linkedList, 3);
    insertAtBeginning(linkedList, 2);
    insertAtEnd(linkedList, 4);
    insertAtEnd(linkedList, 5);

    cout << "Linked list: ";
    display(linkedList);

    deleteNode(linkedList, 2);
    deleteNode(linkedList, 5);

    cout << "Updated linked list: ";
    display(linkedList);

    return 0;
}
