
#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int even = 0, odd = 0;

    cout << "Enter 5 numbers:" << endl;

    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    int *ptr = arr;

    for(int i = 0; i < 5; i++)
    {
        if(*ptr % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }

        ptr++;
    }

    cout << "\nEven numbers: " << even << endl;
    cout << "Odd numbers: " << odd << endl;

    return 0;
}
