
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

int main()
{
    // Create three nodes
    Node* node1 = new Node;
    Node* node2 = new Node;
    Node* node3 = new Node;

    // Assign values
    node1->data = 90;
    node2->data = 30;
    node3->data = 10;

    // Link the nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Traverse the linked list
    Node* temp = node1;

    cout << "Linked List: ";

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;

    // Free allocated memory
    delete node1;
    delete node2;
    delete node3;

    return 0;
}
