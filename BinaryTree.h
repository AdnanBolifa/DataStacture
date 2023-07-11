#pragma once
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
Node* FindMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}
Node* FindMax(Node* root) {
    while (root->right != nullptr)
        root = root->right;
    return root;
}
Node* DeleteNode(Node* root, int data) {
    if (root == nullptr) return root;
    if (data < root->data)
        root->left = DeleteNode(root->left, data);
    else if (data > root->data)
        root->right = DeleteNode(root->right, data);
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete(root);
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else
        {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
        }
    }
    return root;
}
int copyLevelToArr(Node* root, int level, int* arr) {
    if (root == nullptr || level < 1)
        return 0;

    int cLvl = 1;
    int size = 0;
    queue<Node*> q;
    q.push(root);

    while (cLvl != level) {
        int nodesInLevel = q.size();

        for (int i = 0; i < nodesInLevel; i++) {
            Node* currentNodePtr = q.front();
            q.pop();

            if (currentNodePtr->left)
                q.push(currentNodePtr->left);
            if (currentNodePtr->right)
                q.push(currentNodePtr->right);
        }

        cLvl++;
    }

    while (!q.empty()) {
        arr[size++] = q.front()->data;
        q.pop();
    }

    return size;
}
void TreeTraversal(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);
    Node* node;
    while (!q.empty()) {
        node = q.front();
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
        cout << q.front()->data;
        q.pop();
    }
}
void TreeOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    // Traverse left subtree
    TreeOrderTraversal(root->left);

    // Visit node
    cout << root->data << " ";

    // Traverse right subtree
    TreeOrderTraversal(root->right);
}
