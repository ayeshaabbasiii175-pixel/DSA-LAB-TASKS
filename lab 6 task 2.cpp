
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

// Delete at end
void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    cout << "Last node deleted successfully!\n";
}

// Delete at a given position
void deleteAtPosition(int position) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (position < 1) {
        cout << "Invalid position!\n";
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position not found!\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;

    delete delNode;

    cout << "Node deleted successfully!\n";
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

    // Delete last node
    deleteAtEnd();

    cout << "After deleting last node: ";
    display();

    // Delete node at position 2
    deleteAtPosition(2);

    cout << "After deleting position 2: ";
    display();

    return 0;
}
