#include <stdio.h>

int i, j, k, p, s, n;

int main(void)
{

    double matrix[6][6] = {
        {2, 6, -1, 1, 0, 0},
        {-3, -1, 3, 0, 1, 0},
        {-2, 6, 2, 0, 0, 1},
        {1, 0, 5, 7, 3, 5},
        {3, 0, 6, 1, 7, 3},
        {6, 0, 1, 7, 3, 6}};

    double V[6] = {124, 568, 897, 345, 789, 234};
    double R[6] = {0.0};
    double TAM[6] = {0.0};
    double Inv[6][6] = { 0.0};

    for (i = 0; i < 6; i++)
    {

        for (j = 0; j < 6; j++)
        {

            if (i == j )
            {

                Inv[i][j] = 1.00;
            }
            else
            {

                Inv[i][j] = 0.00;
            }
        }
    }

    printf("\n");

    for (i = 0; i < 6; i++)
    {

        for (j = 0; j < 6; j++)
        {

            printf("%lf\t", matrix[i][j]);
        }

        printf("\n");
    }

    printf("\n");

    for (i = 0; i < 6; i++)
    {

        for (j = 0; j < 6; j++)
        {

            printf("%lf ", Inv[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (j = 0; j < 6; j++)
    {

        printf("%lf\n", V[j]);
    }
    printf("\n");

    for (i = 0; i < 6; i++)
    {

        for (k = 0; k < 6; k++)
        {

            R[i] += matrix[i][k] * V[k];
        }
    }

    printf("\n");

    for (j = 0; j < 6; j++)
    {

        printf("%lf\n ", R[j]);
    }
    printf("\n");

    for (j = 0; j < 6; j++)
    {

        printf("%lf ", TAM[j]);
    }
    printf("\n\n");

    // Getting the Inverse Matrix.........
    double aux;
    double pivto, factor;

    printf("\n");

    int t, dt, Time;

    p = 0;
    t = 0;
    dt = 2;
    Time = 18;
    int nt = Time/dt;

    double Vector[6] = {0, 0};
    double Stored[6][8] = {0.0};
    
    //starting of while looop.....

    while (t <= Time)
    {

        for (i = 0; i < 6; i++)
        {

            Vector[i] = 0.0;
        }

        for (i = 0; i < 6; i++)
        {

            for (k = 0; k < 6; k++)
            {

                Vector[i] += matrix[i][k] * V[k];
            }
        }

        if (p < 8)
        {

            for (i = 0; i < 6; i++)
            {

                Stored[p][i] = Vector[i];
                V[i]         = Vector[i];
            }
        }
        else
        {
            printf("ERROR HAS OCCURED!!1!");
            break;
        }

        t = t + dt;
        p = p + 1;

        printf("%d ", t);
    } 
    //END OPF MAIN WHILE LOOP.....
    printf("\n\n");

    for (i = 0; i < 6; i++)
    {

        for (k = 0; k < nt; k++)
        {

            printf("%lf ", Stored[k][i]);
        }

        printf("\n");
    }

    printf("\n");

    for (i = 0; i < 6; i++ )
    {

        pivto = matrix[i][i];

        if (  pivto == 0.0 )  {

            printf("Matrix is singular, inverse does not exist.\n");
            break;
        }

        for (s = 0; s < 6; s++ )
        {

            matrix[i][s] = matrix[i][s] / pivto ;
            Inv[i][s]    = Inv[i][s] / pivto ; 
        }

        for (j = 0; j < 6; j++)
        {

            if (i != j )
            {

                aux = matrix[j][i] / matrix[i][i];

                for (p = 0; p < 6; p++)
                {

                    matrix[j][p] = matrix[j][p] - aux * matrix[i][p];
                    Inv[j][p]    = Inv[j][p] - aux * Inv[i][p];
                }
            }
        }
    }

    printf("\n");
    // Printing the inverse matrix
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%lf ", Inv[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    // Printing the modified matrix
    for ( i = 0; i < 6 ; i ++ )  {

        for ( j = 0 ; j < 6 ;  j ++ )  {

            printf("%lf  ", matrix[i][j] );

        }
        printf("\n");
    }

    printf("\n");

    return 0;

}