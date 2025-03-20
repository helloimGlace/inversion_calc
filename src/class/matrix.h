#ifndef MATRIX_H
#define MATRIX_H

#endif //MATRIX_H

constexpr int MAX = 100;

void getCofactor(float a[MAX][MAX], float temp[MAX][MAX], int p, int q, int n);
float determinant(float a[MAX][MAX], int n);
void adjugate(float a[MAX][MAX], float adj[MAX][MAX], int n);
bool inverse(float a[MAX][MAX], float inv[MAX][MAX], int n);
//float det(float a[MAX][MAX], int n);