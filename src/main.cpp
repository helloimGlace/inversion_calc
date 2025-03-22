#include <iostream>
#include "sqrMatrix.h"

int main() {
    int size;

    std::cin >> size;

    SqrMatrix a(size), inv(size);

    a.input();

    if (size == 1) {
        std::cout << a.data[0][0] << std::endl;
        return 0;
    }
    if (a.inverse(inv)) {
        inv.display();
    } else {
        std::cout << "The matrix is not invertible" << std::endl;
    }
}
