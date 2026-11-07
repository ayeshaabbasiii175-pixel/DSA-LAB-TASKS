
#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    int code;
    float price;
};

int main() {
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    // Dynamic memory allocation
    Product* p = new Product[n];

    // Input products
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of product " << i + 1 << endl;

        cout << "Enter name: ";
        cin >> p[i].name;

        cout << "Enter code: ";
        cin >> p[i].code;

        cout << "Enter price: ";
        cin >> p[i].price;
    }

    // Display products
    cout << "\n--- Product Details ---\n";

    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << endl;
        cout << "Name: " << p[i].name << endl;
        cout << "Code: " << p[i].code << endl;
        cout << "Price: " << p[i].price << endl;
    }

    // Free allocated memory
    delete[] p;
    p = nullptr;

    cout << "\nMemory successfully freed.";

    return 0;
}
