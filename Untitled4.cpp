#include <TXLib.h>
#include <stdio.h>
#include <math.h>
int SolveSquare (double a, double b, double c, double *x1, double *x2)
    {
    if (a == 0)
        {
        if (b == 0)
            {
            if (c == 0)
                {
                return 0;
                }
            else /*Если c не равно 0*/
                {
                return 1;
                }
            }
        else /*Если b не равно 0*/
            {
            *x1 = -c / b;
            return 2;
            }
        }
    else /*Если a не равно 0*/
        {
        double dt = b*b - 4*a*c;
        if (dt < 0)
            {
            return 1;
            }
        if (dt == 0)
            {
            *x1 = -b/(2*a);
            return 2;
            }
        if (dt > 0)
            {
            *x1 = (-b - sqrt(dt)) / (2*a);
            *x2 = (-b + sqrt(dt)) / (2*a);
            return 3;
            }
        }
    }


int main ()
    {
        double a = NULL, b = NULL, c = NULL;
        if (scanf ("%lg %lg %lg", &a, &b, &c) == 3)
            {
            double x1 = NULL, x2 = NULL;
            int nRoots = SolveSquare (a, b, c, &x1, &x2);
            switch (nRoots)
                {
                case 0: printf ("Бесконечное количество корней");
                        break;
                case 1: printf ("Корней нет");
                        break;
                case 2: printf ("Корень равен %lg", x1);
                        break;
                case 3: printf ("Корни равны %lg и %lg", x1, x2);
                        break;
                default: printf ("main(): ERROR: nRoots = %d\n", nRoots);
                }
            }
        else
            {
            printf ("Ошибка");
            }
    }

