struct Matrix : std::array<std::array<Z, 2>, 2> {
    Matrix(Z x = 0) {
        (*this)[0][0] = x;
        (*this)[0][1] = 0;
        (*this)[1][0] = 0;
        (*this)[1][1] = x;
    }
};
 
Matrix operator*(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    return c;
}
 
Matrix &operator*=(Matrix &a, const Matrix &b) {
    return a = a * b;
}

// power(mat, x) -> matrix exponentiation