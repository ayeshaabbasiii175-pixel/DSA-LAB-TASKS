
#include <iostream>
using namespace std;

int main()
{
    int number;
    
    cout << "Enter a number: ";
    cin >> number;

    int *ptr = &number;

    cout << "\nBefore modification: " << number << endl;

    *ptr = 100;

    cout << "After modification: " << number << endl;

    return 0;
}
