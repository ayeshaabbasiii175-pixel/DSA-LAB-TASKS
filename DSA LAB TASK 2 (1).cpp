#include <iostream>
using namespace std;
 
struct Node {
    int data;          // the value
    Node* next;        // address of the next node
};
 
Node* front = NULL;    // points to the first node
Node* rear = NULL;     // points to the last node
 
bool isEmpty() {
    return front == NULL;
}
//In the array queue, we checked front > rear.
//In the linked list queue, we check front == NULL.

 
void enqueue(int value) {
    Node* newNode = new Node;      // 1. create a new node
    newNode->data = value;
    newNode->next = NULL;
 
    if (isEmpty()) {               // 2. first node: front = rear
        front = newNode;
        rear = newNode;
    } else {                       // 3. link it after the last node
        rear->next = newNode;        //Connects the old last node to the new node.
        rear = newNode;                 //Moves rear to the new last node.
    }
    cout << value << " added to the queue." << endl;
}
 
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Nothing to remove." << endl;
        return;
    }
    Node* temp = front;            // 1. remember the first node
    cout << temp->data << " removed from the queue." << endl;
    front = front->next;           // 2. move front to the next node
    if (front == NULL) {           // 3. queue became empty
        rear = NULL;
    }
    delete temp;                   // 4. free the memory
}
 
void peek() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }
    cout << "Front element: " << front->data << endl;
}
 
void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }
    cout << "FRONT -> ";
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout << "(REAR points to " << rear->data << ")" << endl;
}
 
int main() {
    int choice, value;
 
    do {
        cout << "\n*** Queue Using Linked List ***" << endl;
        cout << "1. Enqueue  2. Dequeue  3. Peek  4. Display  5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
 
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);
 
    return 0;
}

