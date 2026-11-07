
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Insert at beginning
void insertStart(int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    cout << "Inserted at beginning!\n";
}

// Insert at end
void insertEnd(int value) {
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

    cout << "Inserted at end!\n";
}

// Insert after a given value
void insertMiddle(int searchValue, int value) {
    Node* temp = head;

    while (temp != nullptr && temp->data != searchValue) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value not found!\n";
        return;
    }

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Inserted successfully!\n";
}

// Display linked list
void display() {
    Node* temp = head;

    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    cout << "Linked List: ";

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Free memory
void freeList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice, value, searchValue;

    do {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert in Middle\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertStart(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;

            case 3:
                cout << "Enter existing value: ";
                cin >> searchValue;

                cout << "Enter new value: ";
                cin >> value;

                insertMiddle(searchValue, value);
                break;

            case 4:
                display();
                break;

            case 5:
                freeList();
                cout << "Program exited!";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
