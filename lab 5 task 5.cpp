
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = nullptr;
    Node* temp;
    Node* prev;
    Node* newNode;

    int n, value, searchValue;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Create linked list
    for (int i = 0; i < n; i++) {
        newNode = new Node;

        cout << "Enter value: ";
        cin >> newNode->data;

        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Search value
    cout << "Enter value before which to insert: ";
    cin >> searchValue;

    temp = head;
    prev = nullptr;

    while (temp != nullptr && temp->data != searchValue) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value not found!";
    } else {
        cout << "Enter new value: ";
        cin >> value;

        newNode = new Node;
        newNode->data = value;

        if (prev == nullptr) {
            // Insert before first node
            newNode->next = head;
            head = newNode;
        } else {
            // Insert before middle or last node
            prev->next = newNode;
            newNode->next = temp;
        }

        cout << "Value inserted successfully!";
    }

    // Display list
    cout << "\nLinked List: ";

    temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL";

    // Free memory
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
