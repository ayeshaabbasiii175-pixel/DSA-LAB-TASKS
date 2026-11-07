
#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int choice, key;

    cout << "Enter 10 integers: ";

    for(int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    do
    {
        cout << "\n\n----- MENU -----";
        cout << "\n1. Selection Sort";
        cout << "\n2. Bubble Sort";
        cout << "\n3. Insertion Sort";
        cout << "\n4. Binary Search";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if(choice == 1)
        {
            for(int i = 0; i < 9; i++)
            {
                int minIndex = i;

                for(int j = i + 1; j < 10; j++)
                {
                    if(arr[j] < arr[minIndex])
                        minIndex = j;
                }

                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }

            cout << "Selection Sort: ";

            for(int i = 0; i < 10; i++)
                cout << arr[i] << " ";
        }

        else if(choice == 2)
        {
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9 - i; j++)
                {
                    if(arr[j] > arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            cout << "Bubble Sort: ";

            for(int i = 0; i < 10; i++)
                cout << arr[i] << " ";
        }

        else if(choice == 3)
        {
            for(int i = 1; i < 10; i++)
            {
                int key = arr[i];
                int j = i - 1;

                while(j >= 0 && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }

                arr[j + 1] = key;
            }

            cout << "Insertion Sort: ";

            for(int i = 0; i < 10; i++)
                cout << arr[i] << " ";
        }

        else if(choice == 4)
        {
            // Sort array before Binary Search

            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9 - i; j++)
                {
                    if(arr[j] > arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            cout << "Enter value to search: ";
            cin >> key;

            int low = 0;
            int high = 9;
            int found = -1;

            while(low <= high)
            {
                int mid = (low + high) / 2;

                if(arr[mid] == key)
                {
                    found = mid;
                    break;
                }
                else if(key > arr[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            if(found != -1)
                cout << "Element found at index " << found;
            else
                cout << "Element not found";
        }

        else if(choice == 5)
        {
            cout << "Program Exited!";
        }

        else
        {
            cout << "Invalid Choice!";
        }

    } while(choice != 5);

    return 0;
}
