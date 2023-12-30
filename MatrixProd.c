#include <stdio.h>

void multiplyMatrix(int firstMatrix[10][10], int secondMatrix[10][10], int result[10][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
    // Initializing elements of result matrix to 0
    for (int i = 0; i < rowFirst; ++i)
    {
        for (int j = 0; j < columnSecond; ++j)
        {
            result[i][j] = 0;
        }
    }

    // Multiplying firstMatrix and secondMatrix and storing in result
    for (int i = 0; i < rowFirst; ++i)
    {
        for (int j = 0; j < columnSecond; ++j)
        {
            for (int k = 0; k < columnFirst; ++k)
            {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main()
{
    int rowFirst, columnFirst, rowSecond, columnSecond;

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowFirst, &columnFirst);

    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowSecond, &columnSecond);

    // Check if multiplication is possible
    if (columnFirst != rowSecond)
    {
        printf("Matrices with entered order can't be multiplied with each other.\n");
        return 0;
    }

    int firstMatrix[10][10], secondMatrix[10][10], result[10][10];

    printf("\nEnter elements of matrix 1:\n");
    for (int i = 0; i < rowFirst; ++i)
    {

        for (int j = 0; j < columnFirst; ++j)
        {

            printf("A[ %d, %d ] as ", i, j);
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    printf("\nEnter elements of matrix 2:\n");
    for (int i = 0; i < rowSecond; ++i)
    {

        for (int j = 0; j < columnSecond; ++j)
        {

            printf("A[ %d, %d ] as ", i, j);
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    multiplyMatrix(firstMatrix, secondMatrix, result, rowFirst, columnFirst, rowSecond, columnSecond);

    // Displaying the multiplication of two matrix.
    printf("\nOutput Matrix:\n");
    printf("[ ");
    for (int i = 0; i < rowFirst; ++i)
        for (int j = 0; j < columnSecond; ++j)
            printf("%d%c", result[i][j], (j == columnSecond - 1) ? '\n' : ' ');

    printf("]\n");

    return 0;
}