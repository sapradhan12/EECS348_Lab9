#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int getValidatedIntInRange(string prompt, int minVal, int maxVal) {
    int num;
    bool valid = false;
    while (!valid) {
        cout << prompt;
        cin >> num;
        if (cin.fail()) {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (num < minVal || num > maxVal) {
            cout << "Input out of range. Please enter an integer between " << minVal << " and " << maxVal << "." << endl;
            cin.ignore(1000, '\n');
        } else {
            valid = true;
            cin.ignore(1000, '\n');
        }
    }
    return num;
}

int getValidatedInt(string prompt) {
    int num;
    bool valid = false;
    while (!valid) {
        cout << prompt;
        cin >> num;
        if (cin.fail()) {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            valid = true;
            cin.ignore(1000, '\n');
        }
    }
    return num;
}

double getValidatedDouble(string prompt) {
    double num;
    bool valid = false;
    while (!valid) {
        cout << prompt;
        cin >> num;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            valid = true;
            cin.ignore(1000, '\n');
        }
    }
    return num;
}

int main() {
    cout << "Enter the file name: ";
    string filename;
    cin >> filename;

    ifstream infile(filename);
    if (!infile) {
        cout << "Cannot open file: " << filename << endl;
        return 1;
    }

    int matrixSize, typeFlag;
    infile >> matrixSize >> typeFlag;
    cout << endl;

    if (typeFlag == 0) {
        Matrix<int> matrix1 = readMatrix<int>(infile, matrixSize);
        Matrix<int> matrix2 = readMatrix<int>(infile, matrixSize);

        cout << "\n1. Printing out matrices" << endl;
        cout << "Matrix 1 (int):" << endl;
        matrix1.print();
        cout << "Matrix 2 (int):" << endl;
        matrix2.print();

        cout << "\n2. Adding 2 matrices" << endl;
        Matrix<int> resultAdd = matrix1 + matrix2;
        resultAdd.print();

        cout << "\n3. Multiplying 2 matrices" << endl;
        Matrix<int> resultMul = matrix1 * matrix2;
        resultMul.print();

        cout << "\n4. Summing the diagonals" << endl;
        cout << "Sum of main diagonal (Matrix1): " << matrix1.sum_diagonal_major() << endl;
        cout << "Sum of secondary diagonal (Matrix1): " << matrix1.sum_diagonal_minor() << endl;
        cout << endl;

        if (matrixSize >= 2) {
            cout << "\n5. Swapping 2 Rows" << endl;
            int row1 = getValidatedIntInRange("Enter the first row index to swap (0 to " + to_string(matrixSize - 1) + "): ", 0, matrixSize - 1);
            int row2 = getValidatedIntInRange("Enter the second row index to swap (0 to " + to_string(matrixSize - 1) + "): ", 0, matrixSize - 1);
            Matrix<int> matrix1RowsSwapped = matrix1;
            matrix1RowsSwapped.swap_rows(row1, row2);
            cout << "Matrix1 after swapping rows " << row1 << " and " << row2 << ":" << endl;
            matrix1RowsSwapped.print();

            cout << "\n6. Swapping 2 Columns" << endl;
            int col1 = getValidatedIntInRange("Enter the first column index to swap (0 to " + to_string(matrixSize - 1) + "): ", 0, matrixSize - 1);
            int col2 = getValidatedIntInRange("Enter the second column index to swap (0 to " + to_string(matrixSize - 1) + "): ", 0, matrixSize - 1);
            Matrix<int> matrix1ColsSwapped = matrix1;
            matrix1ColsSwapped.swap_cols(col1, col2);
            cout << "Matrix1 after swapping columns " << col1 << " and " << col2 << ":" << endl;
            matrix1ColsSwapped.print();

            cout << "\n7. Updating matrix element" << endl;
            int newValue = getValidatedInt("Enter a new value (integer): ");
            int row = getValidatedIntInRange("Enter the row index to update (0 to " + to_string(matrixSize - 1) + "): ", 0, matrixSize - 1);
            int col = getValidatedIntInRange("Enter the column index to update (0 to " + to_string(matrixSize - 1) + "): ", 0, matrixSize - 1);
            Matrix<int> matrix1Updated = matrix1;
            matrix1Updated.set_value(row, col, newValue);
            cout << "Matrix1 after updating element at (" << row << ", " << col << ") to " << newValue << ":" << endl;
            matrix1Updated.print();
        } else {
            cout << "Matrix size must be at least 2 to swap rows or columns." << endl;
        }
    } else if (typeFlag == 1) {
        Matrix<double> matrix1 = readMatrix<double>(infile, matrixSize);
        Matrix<double> matrix2 = readMatrix<double>(infile, matrixSize);

        cout << "\n1. Printing out matrices" << endl;
        cout << "Matrix 1 (double):" << endl;
        matrix1.print();
        cout << "Matrix 2 (double):" << endl;
        matrix2.print();

        cout << "\n2. Adding 2 matrices" << endl;
        Matrix<double> resultAdd = matrix1 + matrix2;
        resultAdd.print();

        cout << "\n3. Multiplying 2 matrices" << endl;
        Matrix<double> resultMul = matrix1 * matrix2;
        resultMul.print();

        cout << "\n4. Summing the diagonals" << endl;
        cout << "Sum of main diagonal (Matrix1): " << matrix1.sum_diagonal_major() << endl;
        cout << "Sum of secondary diagonal (Matrix1): " << matrix1.sum_diagonal_minor() << endl;
        cout << endl;

        if (matrixSize >= 2) {
            cout << "\n5. Swapping 2 Rows" << endl;
            int row1 = getValidatedIntInRange("Enter the first row index to swap (0 to " + to_string(matrixSize - 1) + "): ", 0, matrixSize - 1);
            int row2 = getValidatedIntInRange("Enter the second row index to swap (0 to " + to_string(matrixSize - 1) + "): ", 0, matrixSize - 1);
            Matrix<double> matrix1RowsSwapped = matrix1;
            matrix1RowsSwapped.swap_rows(row1, row2);
            cout << "Matrix1 after swapping rows " << row1 << " and " << row2 << ":" << endl;
            matrix1RowsSwapped.print();

            cout << "\n6. Swapping 2 Columns" << endl;
            int col1 = getValidatedIntInRange("Enter the first column index to swap (0 to " + to_string(matrixSize - 1) + "): ", 0, matrixSize - 1);
            int col2 = getValidatedIntInRange("Enter the second column index to swap (0 to " + to_string(matrixSize - 1) + "): ", 0, matrixSize - 1);
            Matrix<double> matrix1ColsSwapped = matrix1;
            matrix1ColsSwapped.swap_cols(col1, col2);
            cout << "Matrix1 after swapping columns " << col1 << " and " << col2 << ":" << endl;
            matrix1ColsSwapped.print();

            cout << "\n7. Updating matrix element" << endl;
            double newValue = getValidatedDouble("Enter a new value (number): ");
            int row = getValidatedIntInRange("Enter the row index to update (0 to " + to_string(matrixSize - 1) + "): ", 0, matrixSize - 1);
            int col = getValidatedIntInRange("Enter the column index to update (0 to " + to_string(matrixSize - 1) + "): ", 0, matrixSize - 1);
            Matrix<double> matrix1Updated = matrix1;
            matrix1Updated.set_value(row, col, newValue);
            cout << "Matrix1 after updating element at (" << row << ", " << col << ") to " << newValue << ":" << endl;
            matrix1Updated.print();
        } else {
            cout << "Matrix size must be at least 2 to swap rows or columns." << endl;
        }
    }

    infile.close();
    return 0;
}
