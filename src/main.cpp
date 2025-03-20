#include <iostream>
#include <cstdio>
#include "matrix.h"

int main() {
    int n;
    float a[MAX][MAX], inv[MAX][MAX];

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    if (n == 1) {
        std::cout << a[0][0] << std::endl;
        return 0;
    }
    if (inverse(a, inv, n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%6.2f", inv[i][j]);
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No solution" << std::endl;
    }
}
