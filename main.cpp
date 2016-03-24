/*
 * File:   main.cpp
 * Author: robert
 *
 * Created on March 23, 2016, 12:37 PM
 */

#include <iostream>

template <class T>
class Matrix {
    
public:
    Matrix (int rows, int columns) {
        matrixRows = rows;
        matrixColumns = columns;
        matrixReference = new T*[rows];
        for (int r = 0; r < rows; r++) {
            matrixReference[r] = new T[columns];
            for (int c = 0; c < columns; c++) {
                matrixReference[r][c] = 0;
            }
        }
    };
    
    int rows() const {
        return matrixRows;
    };
    
    int columns() const {
        return matrixColumns;
    };
    
    T valueAt(int row, int column) const {
        return matrixReference[row][column];
    };
    
    void setValue(int row, int column, T value) {
      matrixReference[row][column] = value;  
    };
    
    void showMatrix() const {
        for (int r = 0; r < matrixRows; r++) {
            for (int c = 0; c < matrixColumns; c++) {
                std::cout << " | " << matrixReference[r][c];
            }
            std::cout << std::endl;
        }
    };
    
    Matrix operator + (const Matrix<T>& otherMatrix) {
        int rCount = rows() > otherMatrix.rows() ? rows() : otherMatrix.rows();
        int cCount = columns() > otherMatrix.columns() ? columns() : otherMatrix.columns();
        Matrix<T> sumMatrix(rCount, cCount);
        for (int r = 0; r < rCount; r++) {
            for (int c = 0; c < cCount; c++) {
                T value = 0;
                if (r < rows() && c < columns()) {
                    value += valueAt(r, c);
                }
                if (r < otherMatrix.rows() && c < otherMatrix.columns()) {
                    value += otherMatrix.valueAt(r, c);
                }
                sumMatrix.setValue(r, c, value);
            }
        }
        return sumMatrix;
    };
    
private:
    T ** matrixReference;
    int matrixRows;
    int matrixColumns;
};

int main() {
    Matrix<int> myMatrix(3, 5);
    myMatrix.setValue(0, 0, 1);
    myMatrix.setValue(0, 1, 2);
    myMatrix.setValue(0, 2, 3);
    myMatrix.setValue(0, 3, 4);
    myMatrix.setValue(0, 4, 5);
    myMatrix.setValue(1, 0, 6);
    myMatrix.setValue(1, 1, 7);
    myMatrix.setValue(1, 2, 8);
    myMatrix.setValue(1, 3, 9);
    myMatrix.setValue(1, 4, 0);
    myMatrix.setValue(2, 0, 1);
    myMatrix.setValue(2, 1, 2);
    myMatrix.setValue(2, 2, 3);
    myMatrix.setValue(2, 3, 4);
    myMatrix.setValue(2, 4, 5);
    //myMatrix.showMatrix();
    Matrix<int> sumMatrix = myMatrix + myMatrix;
    sumMatrix.showMatrix();
}
