#ifndef SQRMATRIX_H
#define SQRMATRIX_H

#include <vector>

class SqrMatrix {
public:
    explicit SqrMatrix(int size);
    void input() const;
    void display() const;

    std::vector<std::vector<float>> data;

    void adjugate(SqrMatrix &adj) const;
    bool inverse(SqrMatrix &inv) const;

    int size;
};

void getCofactor(const SqrMatrix &mat, SqrMatrix &temp, int p, int q, int size);
float determinant(const SqrMatrix &mat, int size);

#endif //SQRMATRIX_H