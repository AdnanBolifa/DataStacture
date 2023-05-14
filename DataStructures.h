#pragma once
#include <iostream>
using namespace std;

struct node
{
     
    int data;
    node* prev;
    node* next;

};
class DataStracture
{
    
public:
    void insert_at_front(node** head, int data) {


        node* new_node = new node();
        new_node->data = data;

        new_node->prev = NULL;
        new_node->next = (*head);

        // if the list is not empty, set the current head's previous pointer to new node
        if ((*head) != NULL) {
            (*head)->prev = new_node;
        }

        (*head) = new_node;

        return;

    }
};


/*int main() 
{
    node* head = NULL;
    node* end = NULL;

    // call the insert_at_front function four times
    ds.insert_at_front(&head, 1);
    ds.insert_at_front(&head, 2);
    ds.insert_at_front(&head, 3);
    ds.insert_at_front(&head, 4);

    // print the list in forward direction
    cout << "In forward direction:" << endl;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;

    return 0;
}*/

