#include "sqrMatrix.h"
#include <iostream>
#include <cstdio>
#include <vector>

SqrMatrix::SqrMatrix(int size): data(size, std::vector<float>(size)), size(size) {}

void SqrMatrix::input() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%f", &data[i][j]);
        }
    }
}

void SqrMatrix::display() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%6.2f", data[i][j]);
        }
        printf("\n");
    }
}

void SqrMatrix::adjugate(SqrMatrix &adj) const {
    // Using the formula adj(A) = transpose(C), where C is the cofactor matrix
    // to calculate the adjugate of a square matrix

    // Base case: if the matrix is 1x1, the adjugate is 1
    if (size == 1) {
        adj.data[0][0] = 1;
        return;
    }

    SqrMatrix temp(size);
    int sign = 1;

    // Iterate through each element of the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Get the cofactor of mat[i][j]
            getMinor(*this, temp, i, j, size);
            sign = (i + j) % 2 == 0 ? 1 : -1;
            // Calculate the determinant of the sub-matrix
            // and assign it to the adjugate matrix
            adj.data[j][i] = static_cast<float>(sign) * determinant(temp, size - 1);
        }
    }
}

bool SqrMatrix::inverse(SqrMatrix &inv) const {
    // Using the formula A^-1 = adj(A) / det(A) to calculate the inverse of a square matrix
    float det = determinant(*this, size);
    if (det == 0) {
        // If the determinant is 0, the matrix is not invertible
        return false;
    }

    SqrMatrix adj(size);
    adjugate(adj);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inv.data[i][j] = adj.data[i][j] / det;
        }
    }

    return true;
}

float determinant(const SqrMatrix &mat, int size) { // NOLINT(*-no-recursion)
    // Using recursion to calculate the determinant of a square matrix

    // Base case: if the matrix reaches 1x1, return the element
    if (size == 1) {
        return mat.data[0][0];
    }

    SqrMatrix temp(size);
    float det = 0;
    int sign = 1;

    // Iterate through the first row of the matrix
    for (int k = 0; k < size; k++) {
        // Get the cofactor of a[0][f]
        getMinor(mat, temp, 0, k, size);
        // Calculate the determinant of the sub-matrix
        det += static_cast<float>(sign) * mat.data[0][k] * determinant(temp, size - 1);
        sign = -sign;
    }

    return det;
}

void getMinor(const SqrMatrix &mat, SqrMatrix &temp, int p, int q, int size) {
    // Copying the elements of the matrix A to the temporary matrix temp to form the minor matrix
    int i = 0, j = 0;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (row != p && col != q) {
                temp.data[i][j++] = mat.data[row][col];
                // If the row is filled, move to the next row
                if (j == size - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
