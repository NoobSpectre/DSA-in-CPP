#include<iostream>
using namespace std;

void print(float** mat, int rows, int columns) {
    cout << "\nThe matrix is: " << endl;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool isNullMatrix(float** mat, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(mat[i][j] != 0) return false;
        }
    }
    return true;
}

void _toEchelonForm(float** mat, int rows, int cols) {
    for(int i=0; i<rows-1; i++) {
        if((i < cols && mat[i][i] != 0) || (i >= cols && mat[i][cols-1] != 0)) {
            float _divider = mat[i][i];
            for(int j=i; j<cols; j++) {
                mat[i][j] /= _divider;
            }
            print(mat , rows, cols);

            for(int j=i+1; j<rows; j++) {
                float _multiple = mat[j][i];
                for(int k=i; k<cols; k++) {
                    if((k == i && mat[j][k] != 0) || (k >= i))
                        mat[j][k] -= mat[i][k] * _multiple;
                }
            }
            print(mat, rows, cols);
        }
        else {
            for(int j=i+1; j<rows; j++) {
                if((i >= cols && mat[j][cols-1] != 0) || (i < cols && mat[j][i] != 0)) {
                    swap(mat[i], mat[j]);
                    i--;
                    break;
                }
            }
            print(mat, rows, cols);
        }
    }
}

int rankOfMatrix(float** mat, int rows, int cols) {
    if(isNullMatrix(mat, rows, cols))
        return 0;
    
    _toEchelonForm(mat, rows, cols);

    int rank = rows;
    for(int i=0; i<rows; i++) {
        int sum = 0;
        for(int j=0; j<cols; j++) {
            sum += mat[i][j];
        }
        if(sum == 0) rank--;
    }

    return rank;
}

int main() {
    cout << "Enter the dimensions(row(s) x column(s)) of the matrix: ";
    int rows, columns; cin >> rows >> columns;

    float** matrix = new float*[rows];
    for(int i=0; i<rows; i++) {
        matrix[i] = new float[columns];
    }

    cout << "Enter the elements of the matrix: ";
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            cin >> matrix[i][j];
        }
    }

//    cout << "\nThe matrix is: " << endl;
    print(matrix, rows, columns);

    int rank = rankOfMatrix(matrix, rows, columns);
    cout << "\nThe required rank of the given matrix is: " << rank << endl;
    return 0;
}