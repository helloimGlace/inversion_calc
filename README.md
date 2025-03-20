# Inversion Calculator
### A simple program to calculate the inversion of a given square (nxn) matrix.

Methods used: 
- **Gauss-Jordan Elimination**
- **Determinant Calculation**: Recursive & Cofactor expansion.
- **Adjugate Matrix Calculation**

### How to use:
- **Input**: 
    - The program reads the matrix from user inputs on the terminal window.
    - The first line of the file should contain the size of the matrix (n).
    - The next n lines should contain the elements of the matrix.
- **Output**:
    - The program will output the inverse of the matrix if it exists.
    - If the matrix is singular, the program will output "Singular Matrix".
    - If the matrix is not invertible, the program will output "No Solution".