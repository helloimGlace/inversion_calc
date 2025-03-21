#include <iostream>
#include "sqrMatrix.h"

int main() {
    int n;

    std::cin >> n;

    SqrMatrix a(n), inv(n);

    a.input();

    if (n == 1) {
        std::cout << a.data[0][0] << std::endl;
        return 0;
    }
    if (a.inverse(inv)) {
        inv.display();
    } else {
        std::cout << "No solution" << std::endl;
    }
}
