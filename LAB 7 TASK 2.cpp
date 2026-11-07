
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

int main()
{
    // Create five nodes
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    first->data = 101;
    second->data = 102;
    third->data = 103;
    fourth->data = 104;
    fifth->data = 105;

    // Connect nodes
    first->prev = nullptr;
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->next = nullptr;

    Node* head = first;
    Node* tail = fifth;

    // 1. Insert 100 at beginning
    Node* newNode = new Node();
    newNode->data = 100;
    newNode->prev = nullptr;
    newNode->next = head;

    head->prev = newNode;
    head = newNode;

    // 2. Insert 1035 after 103
    newNode = new Node();
    newNode->data = 1035;

    newNode->prev = third;
    newNode->next = fourth;

    third->next = newNode;
    fourth->prev = newNode;

    // 3. Insert 106 at end
    newNode = new Node();
    newNode->data = 106;
    newNode->next = nullptr;
    newNode->prev = tail;

    tail->next = newNode;
    tail = newNode;

    // 4. Delete first product
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;

    // 5. Delete product 104
    temp = fourth;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;

    // 6. Delete last product
    temp = tail;
    tail = tail->prev;
    tail->next = nullptr;

    delete temp;

    // 7. Display final list
    temp = head;

    cout << "Final Doubly Linked List: ";

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
