#include<iostream>
using namespace std;

void print(int** mat, int _rows, int _cols) {
    for(int i=0; i<_rows; i++) {
        for(int j=0; j<_cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }   
}

int** multiplyMatrices(int** mat1, int** mat2, int _rows1,int _cols1, int _rows2, int _cols2) {
    if(_cols1 != _rows2) return NULL;

    int** newMat = new int*[_rows1];
    for(int i=0; i<_rows1; i++) {
        newMat[i] = new int[_cols2];
    }

    for(int i=0; i<_rows1; i++) {
        for(int j=0; j<_cols2; j++) {
            newMat[i][j] = 0;
            for(int k=0; k<_cols1; k++) {
                newMat[i][j] += (mat1[i][k] * mat2[k][j]);
            }
        }
    }

    // for(int i=0; i<_rows1; i++) {
    //     for(int j=0; j<_cols1; j++) {
    //         cout << mat1[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for(int i=0; i<_rows2; i++) {
    //     for(int j=0; j<_cols2; j++) {
    //         cout << mat1[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return newMat;
}

int main() {
    cout << "Enter the dimensions(row(s) x column(s)) of the matrix1: ";
    int _rows1, _cols1; cin >> _rows1 >> _cols1;

    int** matrix1 = new int*[_rows1];
    for(int i=0; i<_rows1; i++) {
        matrix1[i] = new int[_cols1];
    }

    cout << "Enter the elements of matrix1: ";
    for(int i=0; i<_rows1; i++) {
        for(int j=0; j<_cols1; j++) {
            cin >> matrix1[i][j];
        }
    }

    cout << "The matrix 1 is:" << endl;
    print(matrix1, _rows1, _cols1);

    cout << "\nEnter the dimensions(row(s) x column(s)) of the matrix2: ";
    int _rows2, _cols2; cin >> _rows2 >> _cols2;

    int** matrix2 = new int*[_rows2];
    for(int i=0; i<_rows2; i++) {
        matrix2[i] = new int[_cols2];
    }

    cout << "Enter the elements of matrix2: ";
    for(int i=0; i<_rows2; i++) {
        for(int j=0; j<_cols2; j++) {
            cin >> matrix2[i][j];
        }
    }

    cout << "The matrix 2 is:" << endl;
    print(matrix2, _rows2, _cols2);

    int** resultantMatrix = multiplyMatrices(matrix1, matrix2, _rows1, _cols1, _rows2, _cols2);

    if(resultantMatrix == NULL)
        cout << "\nMultiplication Not Possible..." << endl;
    else {
        cout << "\nThe resultant matrix is: " << endl;
        print(resultantMatrix, _rows1, _cols2);
    }

    for(int i=0, j=0; i<_rows1 || j<_rows2; i++, j++) {
        if(i<_rows1) delete []matrix1[i];
        if(j<_rows2) delete []matrix2[j];
    }

    delete []matrix1;
    delete []matrix2;

    return 0;
}