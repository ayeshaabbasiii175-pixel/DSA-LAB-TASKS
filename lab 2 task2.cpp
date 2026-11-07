
#include <iostream>
using namespace std;

int main()
{
    int number = 10;

    int *ptr = &number;

    int **pp = &ptr;

    cout << "Original value: " << number << endl;

    **pp = 50;

    cout << "Modified value: " << number << endl;

    return 0;
}
