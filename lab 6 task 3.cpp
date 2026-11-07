
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Insert at end
void insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

// Delete by value
void deleteByValue(int value) {
    if (head == nullptr) {
        cout << "Value not found\n";
        return;
    }

    // Case 1: Value is in first node
    if (head->data == value) {
        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "Value deleted successfully!\n";
        return;
    }

    // Case 2: Value is in middle or at end
    Node* temp = head;

    while (temp->next != nullptr &&
           temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value not found\n";
        return;
    }

    Node* delNode = temp->next;

    temp->next = delNode->next;

    delete delNode;

    cout << "Value deleted successfully!\n";
}

// Display list
void display() {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    // Create linked list
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    cout << "Original List: ";
    display();

    // Delete first node
    deleteByValue(10);

    cout << "After deleting 10: ";
    display();

    // Delete middle node
    deleteByValue(30);

    cout << "After deleting 30: ";
    display();

    // Delete last node
    deleteByValue(50);

    cout << "After deleting 50: ";
    display();

    // Try deleting a value that does not exist
    deleteByValue(100);

    cout << "Final List: ";
    display();

    return 0;
}
