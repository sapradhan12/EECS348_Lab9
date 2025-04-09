#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    cout << "Enter the file name: ";
    string filename;
    cin >> filename;

    ifstream infile(filename);

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

        cout << "\n5. Swapping 2 Rows" << endl;
        if (matrixSize >= 2) {
            int row1, row2;
            cout << "Enter two row indices (space-separated) to swap for Matrix1: ";
            cin >> row1 >> row2;
            Matrix<int> matrix1RowsSwapped = matrix1;
            matrix1RowsSwapped.swap_rows(row1, row2);
            cout << "Matrix1 after swapping rows " << row1 << " and " << row2 << ":" << endl;
            matrix1RowsSwapped.print();
        } else {
            cout << "You can't swap rows because the matrix needs to be a 2x2 matrix or larger" << endl;
        }
        
        cout << "\n6. Swapping 2 columns" << endl;
        if (matrixSize >= 2) {
            int col1, col2;
            cout << "Enter two column indices (space-separated) to swap for Matrix1: ";
            cin >> col1 >> col2;
            Matrix<int> matrix1ColsSwapped = matrix1;
            matrix1ColsSwapped.swap_cols(col1, col2);
            cout << "Matrix1 after swapping columns " << col1 << " and " << col2 << ":" << endl;
            matrix1ColsSwapped.print();
        } else {
            cout << "You can't swap columns because the matrix needs to be a 2x2 matrix or larger" << endl;
        }

        cout << "\n7. Updating matrix element" << endl;
        int newValue, row, col;
        cout << "Enter a new value, row index, and column index (space-separated) for updating Matrix1: ";
        cin >> newValue >> row >> col;
        Matrix<int> matrix1Updated = matrix1;
        matrix1Updated.set_value(row, col, newValue);
        cout << "Matrix1 after updating element at (" << row << ", " << col << ") to " << newValue << ":" << endl;
        matrix1Updated.print();

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

        cout << "\n5. Swapping 2 Rows" << endl;
        if (matrixSize >= 2) {
            int row1, row2;
            cout << "Enter two row indices (space-separated) to swap for Matrix1: ";
            cin >> row1 >> row2;
            Matrix<double> matrix1RowsSwapped = matrix1;
            matrix1RowsSwapped.swap_rows(row1, row2);
            cout << "Matrix1 after swapping rows " << row1 << " and " << row2 << ":" << endl;
            matrix1RowsSwapped.print();
        } else {
            cout << "You can't swap rows because the matrix needs to be a 2x2 matrix or larger" << endl;
        }
        
        cout << "\n6. Swapping 2 Columns" << endl;
        if (matrixSize >= 2) {
            int col1, col2;
            cout << "Enter two column indices (space-separated) to swap for Matrix1: ";
            cin >> col1 >> col2;
            Matrix<double> matrix1ColsSwapped = matrix1;
            matrix1ColsSwapped.swap_cols(col1, col2);
            cout << "Matrix1 after swapping columns " << col1 << " and " << col2 << ":" << endl;
            matrix1ColsSwapped.print();
        } else {
            cout << "You can't swap columns because the matrix needs to be a 2x2 matrix or larger" << endl;
        }

        cout << "\n7. Updating matrix element" << endl;
        double newValue;
        int row, col;
        cout << "Enter a new value, row index, and column index (space-separated) for updating Matrix1: ";
        cin >> newValue >> row >> col;
        Matrix<double> matrix1Updated = matrix1;
        matrix1Updated.set_value(row, col, newValue);
        cout << "Matrix1 after updating element at (" << row << ", " << col << ") to " << newValue << ":" << endl;
        matrix1Updated.print();
    }
    
    infile.close();
    return 0;
}
