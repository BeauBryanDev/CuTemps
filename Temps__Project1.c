#include <stdio.h>
#include <stdlib.h>

int i, j, k, p, r, s;

double L, TIME, nx, nt;

double K, cp, po, t;
double To, T_left, T_Right;
double dt, dx;
//This is a Temperature simulator to Model the temperature of a X!D Bar made up of >Cupper along the X_Axis.
int main(void)
{
//These are the parameter to input.
// Cooper conductivity as : 385 W°K/m
//Cooper Density as >: 8860 Kg/m3
//Cooper Specific Heat as : 386 J/Kg°C
    printf("******************\n");
    printf("***Temperature****\n");
    printf("******************\n");
    printf("Enter Cu Conductivity as K: ");
    scanf("%lf", &K);
    printf("Enter Cu -> cp: ");
    scanf("%lf", &cp);
    printf("Enter Density as Cu po: ");
    scanf("%lf", &po);
    printf("Enter the Length of L: ");
    scanf("%lf", &L);
    printf("Enter the C Time as T: ");
    scanf("%lf", &TIME);
    printf("Enter nx as nx: ");
    scanf("%lf", &nx);
    printf("Enter nt as nt: ");
    scanf("%lf", &nt); // Enviroment T°
    printf("Enter To1 as env_T: ");
    scanf("%lf", &To);
    printf("Enter Left__T: ");
    scanf("%lf", &T_left); // Left-hand side Temperature
    printf("Enter Right_T: ");
    scanf("%lf", &T_Right); // Right-hand side Temperature....

    // CONVERT T( °C )  --->TO--> T(°K)  ...
    /*
    To = To + 273;
    T_left = T_left + 273;
    T_Right = T_Right + 273;
    */
    // Calculate dx, dt, and lambda after user input
    dx = (double)L / (nx + 1);
    dt = (double)TIME / nt;
    double alfa = 13.56*K / (po * cp);
    double lambda = (alfa * dt) / (dx * dx);

    double Tempo[100], Tempt[100];
    double A[100][100], B[100][100], I[100][100], V[100];
    double R[199][399] = {0.0 };

    for (i = 0; i < nx; i++)
    {

        for (j = 0; j < nx; j++)
        {

            if (i == j)
            {

                if (i == 0 && j == 0)
                {

                    A[i][j] = -(lambda + 1);
                    I[i][j] = 1.00;
                }
                else
                {

                    if (i == nx - 1 && j == nx - 1)
                    {

                        A[i][j] = -(lambda + 1);
                        I[i][j] = 1.00;
                    }

                    else
                    {

                        A[i][j] = -(2 * lambda + 1);
                        I[i][j] = 1.00;
                    }
                }
            }
            else
            {

                if (i - j == 1 || i - j == -1)
                {

                    A[i][j] = lambda;
                    I[i][j] = 0.00;
                }
                else
                {

                    A[i][j] = 0.00;
                    I[i][j] = 0.00;
                }
            }
        }
    }
    printf("\n");

    for (i = 0; i < nx; i++)
    {

        for (j = 0; j < nx; j++)
        {

            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < nx; i++)
    {

        if (i == 0)
        {

            Tempo[i] = T_left;
        }
        else
        {

            if (i == nx - 1)
            {

                Tempo[i] = T_Right;
            }
            else
            {

                Tempo[i] = To;
            }
        }
    }

    printf("\n");

    for (i = 0; i < nx; i++)
    {

        for (j = 0; j < nx; j++)
        {

            printf("%lf ", I[i][j]);
        }

        printf("\n");
    }

    // REDUCCION....
    double aux;
    double pivot;
    double factor;
for (i = 0; i < nx; i++)
    {

        pivot = A[i][i];

        for (s = 0; s < nx; s++)
        {

            A[i][s] = A[i][s] / pivot;
            I[i][s] = I[i][s] / pivot;
        }

        for (j = 0; j < nx; j++)
        {

            if (i != j)
            {

                aux = A[j][i] / A[i][i];

                for (r = 0; r < nx; r++)
                {

                    A[j][r] = A[j][r] - aux * A[i][r];
                    I[j][r] = I[j][r] - aux * I[i][r];
                }
            }
        }
    }

    printf("\n");

    for (i = 0; i < nx; i++)
    {

        for (j = 0; j < nx; j++)
        {

            printf("%lf ", I[i][j]);
        }

        printf("\n");
    }
    printf("\n");

    for (i = 0; i < nx; i++)
    {
        for (j = 0; j < nx; j++)
        {

            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    p = 0;
    t = 0;

    for (j = 0; j < nx; j++)
    {
        printf("%lf   ", Tempo[j]);
    }

    //double R[199][399];

    // Initialize all elements to zero...

    printf("\n");

    // STARTING OF WHILE LOOP.....

    while (t <= TIME)
    {
        for (s = 0; s < nx; s++)
        {
            Tempt[s] = 0.0;
        }

        for (i = 0; i < nx; i++)
        {
            for (k = 0; k < nx; k++)
            {
                Tempt[i] += I[i][k] * (-1.000) * Tempo[k];
            }
        }

        if (p < nt)
        {
            for (s = 0; s < nx; s++)
            {
                R[p][s]  = Tempt[s];
                
                // Tempo[s] = Tempt[s];

                if ( s == 0 ) {

                    Tempo[s] = T_left;

                }
                else if ( s == nx-1 ) {

                    Tempt[s]  =  T_Right;

                }
                else {

                    Tempo[s] = Tempt[s];

                }

            }

            // Print the state of Tempt for each iteration
            printf("Temperature T° after iteration %d:\n", p);
            for (s = 0; s < nx; s++)
            {
                printf("%lf ", Tempt[s]);
            }
            printf("\n\n");
        }
        else
        {
            printf("Error --> Exceeded Storage Limit..No more data will be stored here!\n ");
            break;
        }

        p = p + 1;
        t = t + dt;
    }
    // Ending of While Loop.......
    printf("\n");
    // FIX THE ISSUE WITH R[I,J ] ASAP....
    for (p = 0; p < nt; p++)
    {

        for (s = 0; s < nx; s++)
        {

            printf("%lf ", R[p][s]);
        }

        printf("\n");

    }
    printf("\n");

    ////PRINT  DIFF dx and dt....

    printf("dx --> %lf  \n", dx);
    printf("dt --> %lf  \n",  dt);
    printf("\n");

    return 0;

}
