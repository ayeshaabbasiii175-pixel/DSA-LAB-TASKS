#include <iostream>
using namespace std;
 
#define SIZE 5
 
int items[SIZE];      // array that stores the data
int front = 0;        // index of the first element
int rear = -1;        // index of the last element
 
bool isEmpty() {
    return front > rear;
}
 
bool isFull() {
    return rear == SIZE - 1;
}
 
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is FULL! Cannot add " << value << endl;
        return;
    }
    rear++;                    // move rear one step forward
    items[rear] = value;       // store the value at rear
    cout << value << " added to the queue." << endl;
}
 
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Nothing to remove." << endl;
        return;
    }
    cout << items[front] << " removed from the queue." << endl;
    front++;                   // move front one step forward
    if (front > rear) {        // queue empty again: start over
        front = 0;
        rear = -1;
    }
}
 
void peek() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }
    cout << "Front element: " << items[front] << endl;
}
 
void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }
    cout << "FRONT -> ";
    for (int i = front; i <= rear; i++) {
        cout << items[i] << " ";
    }
    cout << "<- REAR" << endl;
    cout << "(front = " << front << ", rear = " << rear << ")" << endl;
}
 
int main() {
    int choice, value;
 
    do {
        cout << "\n*** Queue Using Array ***" << endl;
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
 