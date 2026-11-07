#include <iostream>
using namespace std;
 
#define SIZE 5
 
int items[SIZE];
int front = 0;          // index of the first element
int rear = -1;          // index of the last element
int itemCount = 0;      // how many elements are in the queue
 
bool isEmpty() {
    return itemCount == 0;
}
 
bool isFull() {
    return itemCount == SIZE;
}
 
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is FULL! Cannot add " << value << endl;
        return;
    }
    int old = rear;
    rear = (rear + 1) % SIZE;      // wraps to 0 after last index
    items[rear] = value;   //Store the new value at the position pointed to by rear.
    itemCount++;
    cout << value << " added at index " << rear;
    cout << "   [rear = (" << old << " + 1) % " << SIZE;
    cout << " = " << rear << "]" << endl;
}
 
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Nothing to remove." << endl;
        return;
    }
    int old = front;   //Save the current front position.
    cout << items[front] << " removed from index " << front;
    front = (front + 1) % SIZE;    // wraps to 0 after last index
    itemCount--;
    cout << "   [front = (" << old << " + 1) % " << SIZE;
    cout << " = " << front << "]" << endl;
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
    for (int i = 0; i < itemCount; i++) {
        int index = (front + i) % SIZE;    // wraps around
        cout << items[index] << " ";
    }
    cout << "<- REAR" << endl;
    cout << "(front = " << front << ", rear = " << rear
         << ", count = " << itemCount << ")" << endl;
}
 
int main() {
    int choice, value;
 
    do {
        cout << "\n*** Circular Queue ***" << endl;
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

