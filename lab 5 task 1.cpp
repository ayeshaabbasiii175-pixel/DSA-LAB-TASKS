
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = nullptr;
    Node* temp;
    Node* newNode;
    int n, value;

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

    // Insert at beginning
    cout << "Enter value to insert at beginning: ";
    cin >> value;

    newNode = new Node;
    newNode->data = value;

    newNode->next = head;
    head = newNode;

    // Display linked list
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
