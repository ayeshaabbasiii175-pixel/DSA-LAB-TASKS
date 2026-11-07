
#include <iostream>
using namespace std;

int main()
{
    int numbers[5];
    int sum = 0;
    float average;

    cout << "Enter 5 numbers:" << endl;

    for(int i = 0; i < 5; i++)
    {
        cin >> numbers[i];
        sum = sum + numbers[i];
    }

    average = sum / 5.0;

    cout << "\nSum = " << sum << endl;
    cout << "Average = " << average << endl;

    return 0;
}
