#include <stdio.h>

void displayMatrix(double matrix[3][6]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void rowOperation(double matrix[3][6], int row, double factor) {
    for (int j = 0; j < 6; j++) {
        matrix[row][j] /= factor;
    }
}

void eliminateOtherRows(double matrix[3][6], int row, int col) {
    for (int i = 0; i < 3; i++) {
        if (i != row) {
            double factor = matrix[i][col];
            for (int j = 0; j < 6; j++) {
                matrix[i][j] -= factor * matrix[row][j];
            }
        }
    }
}

int main() {
    double matrix[3][6] = {
        {2, 6, -1, 1, 0, 0},
        {-3, -1, 3, 0, 1, 0},
        {-2, 6, 2, 0, 0, 1}
    };

    printf("Original Matrix:\n");
    displayMatrix(matrix);

    for (int i = 0; i < 3; i++) {
        double pivot = matrix[i][i];
        if (pivot == 0) {
            printf("The matrix is singular, and the inverse doesn't exist.\n");
            return 1;
        }

        rowOperation(matrix, i, pivot);
        eliminateOtherRows(matrix, i, i);

        printf("\nMatrix after step %d:\n", i + 1);
        displayMatrix(matrix);
    }

    printf("\nInverse Matrix:\n");
    displayMatrix(matrix);

    return 0;
}