
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

// Delete at start
void deleteAtStart() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;

    cout << "First node deleted successfully!\n";
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

    // First deletion
    deleteAtStart();

    cout << "After first deletion: ";
    display();

    // Second deletion
    deleteAtStart();

    cout << "After second deletion: ";
    display();

    return 0;
}
