
#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Input rows and columns
    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    // Dynamic memory allocation
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Input matrix elements
    cout << "\nEnter matrix elements:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Display matrix
    cout << "\nMatrix is:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr;

    cout << "\nMemory successfully freed.";

    return 0;
}
