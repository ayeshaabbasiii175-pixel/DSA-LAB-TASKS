
#include <iostream>
using namespace std;

int main() {

    // Dynamic memory allocation
    char* ptr = new char;

    // Store a character
    cout << "Enter a character: ";
    cin >> *ptr;

    // Display the character
    cout << "Stored character: " << *ptr << endl;

    // Deallocate memory
    delete ptr;

    // Set pointer to nullptr
    ptr = nullptr;

    cout << "Memory successfully freed.";

    return 0;
}
