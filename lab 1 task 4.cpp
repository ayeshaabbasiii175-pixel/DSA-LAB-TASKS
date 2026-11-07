
#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    int *ptr1 = &a;
    int *ptr2 = &b;

    cout << "\nBefore swapping:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    int temp;

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    cout << "\nAfter swapping:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
