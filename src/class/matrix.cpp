#include "matrix.h"
///#include <cstdio>

void getCofactor(float a[MAX][MAX], float temp[MAX][MAX], int p, int q, int n) {
    // Copying the elements of the matrix A to the temporary matrix temp to form the fofactor matrix
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = a[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}


float determinant(float a[MAX][MAX], int n) { // NOLINT(*-no-recursion)
    // Using recursion to calculate the determinant of a square matrix

    // Base case: if the matrix reaches 1x1, return the element
    if (n == 1) {
        return a[0][0];
    }

    float temp[MAX][MAX];
    float det = 0;
    int sign = 1;

    // Iterate through the first row of the matrix
    for (int f = 0; f < n; f++) {
        // Get the cofactor of a[0][f]
        getCofactor(a, temp, 0, f, n);
        // Calculate the determinant of the sub-matrix
        det += static_cast<float>(sign) * a[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    return det;
}

void adjugate(float a[MAX][MAX], float adj[MAX][MAX], int n) {
    // Using the formula adj(A) = transpose(C), where C is the cofactor matrix
    // to calculate the adjugate of a square matrix

    // Base case: if the matrix is 1x1, the adjugate is 1
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }

    float temp[MAX][MAX];

    // Iterate through each element of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Get the cofactor of a[i][j]
            getCofactor(a, temp, i, j, n);
            int sign = (i + j) % 2 == 0 ? 1 : -1;
            // Calculate the determinant of the sub-matrix
            // and assign it to the adjugate matrix
            adj[j][i] = static_cast<float>(sign) * determinant(temp, n - 1);
        }
    }
}

bool inverse(float a[MAX][MAX], float inv[MAX][MAX], int n) {
    float det = determinant(a, n);
    if (det == 0) {
        return false;
    }

    float adj[MAX][MAX];
    adjugate(a, adj, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = adj[i][j] / det;
        }
    }

    return true;
}


// float det(float a[MAX][MAX], const int n) {
//     int count = 0, check = 1;
//     float b[n], ans = 1;
//
//     // Transforming the matrix into an upper triangular matrix
//     for (int i = 0; i < n-1; i++) {
//         // Check if the diagonal element is 0
//         if (a[i][i] == 0) {
//             check = 0;
//             // Find the first non-zero element in the row
//             // and swap it with the current column
//             for (int j = 0; j < n; j++) {
//                 if (a[i][j] != 0) {
//                     for (int k = 0; k < n; k++) {
//                         float temp = a[k][i];
//                         a[k][i] = a[k][j];
//                         a[k][j] = temp;
//                     }
//                     count++; // Count the number of times have columns been swapped
//                     check++; // Check if there is a 0 in row i and column j
//                     break;
//                 }
//             }
//         }
//
//         // If the diagonal element is still 0 (meaning the entire row is 0), the determinant is 0
//         if (check == 0) {
//             return 0;
//         }
//
//         b[i] = a[i][i];
//
//         // Normalization step (dividing the row by the diagonal element a[i][i])
//         for (int j = 0; j < n; j++) {
//             a[i][j] = a[i][j] / b[i];
//         }
//
//         // Elimination step (turning elements below the diagonal element into 0)
//         for (int j = i+1; j < n; j++) {
//             if (j != i) {
//                 float h = a[j][i];
//                 for (int k = 0; k < n; k++) {
//                     a[j][k] = a[j][k] - h * a[i][k];
//                 }
//             }
//         }
//     }
//
//     // Calculating the determinant
//     // det = a[0][0] * a[1][1] * ... * a[n-1][n-1]
//     b[n-1] = a[n-1][n-1];
//     for (int i = 0; i < n; i++) {
//         ans *= b[i];
//     }
//
//     return count % 2 == 0 ? ans : -ans;
// }