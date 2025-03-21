#include "sqrMatrix.h"
#include <iostream>
#include <cstdio>
#include <vector>

SqrMatrix::SqrMatrix(int size): data(size, std::vector<float>(size)), n(size) {}

void SqrMatrix::input() const {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &data[i][j]);
        }
    }
}

void SqrMatrix::display() const {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.2f", data[i][j]);
        }
        printf("\n");
    }
}

void SqrMatrix::adjugate(SqrMatrix &adj) const {
    // Using the formula adj(A) = transpose(C), where C is the cofactor matrix
    // to calculate the adjugate of a square matrix

    // Base case: if the matrix is 1x1, the adjugate is 1
    if (n == 1) {
        adj.data[0][0] = 1;
        return;
    }

    SqrMatrix temp(n);
    int sign = 1;

    // Iterate through each element of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Get the cofactor of mat[i][j]
            getCofactor(*this, temp, i, j, n);
            sign = (i + j) % 2 == 0 ? 1 : -1;
            // Calculate the determinant of the sub-matrix
            // and assign it to the adjugate matrix
            adj.data[j][i] = static_cast<float>(sign) * determinant(temp, n - 1);
        }
    }
}

bool SqrMatrix::inverse(SqrMatrix &inv) const {
    float det = determinant(*this, n);
    if (det == 0) {
        return false;
    }

    SqrMatrix adj(n);
    adjugate(adj);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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
        getCofactor(mat, temp, 0, k, size);
        // Calculate the determinant of the sub-matrix
        det += static_cast<float>(sign) * mat.data[0][k] * determinant(temp, size - 1);
        sign = -sign;
    }

    return det;
}

void getCofactor(const SqrMatrix &mat, SqrMatrix &temp, int p, int q, int size) {
    // Copying the elements of the matrix A to the temporary matrix temp to form the cofactor matrix
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
