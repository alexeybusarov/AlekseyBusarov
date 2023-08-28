#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum
{
     InfiniteNumberOfRoots,
     NoRoots,
     OneRoot,
     TwoRoots
}SolveCase;

bool isNull(double);

SolveCase solveSquare(double, double, double, double*, double*);

int main ()
{
    double a = NAN, b = NAN, c = NAN;
    char lastInput[100];
    char* wrongSymbolPointer = 0;

    printf ("������� ������������: ");
    if (scanf ("%lg %lg %s", &a, &b,lastInput) != 3)
    {
        printf ("������� ������������ ������");
        return 1;
    }

    c = strtod(lastInput, &wrongSymbolPointer);

    if(*wrongSymbolPointer != '\0')
    {
        printf ("������� ������������ ������");
        return 1;
    }

    double x1 = NAN, x2 = NAN;
    SolveCase nRoots = solveSquare (a, b, c, &x1, &x2);
    switch (nRoots)
    {
        case InfiniteNumberOfRoots:
            printf ("����������� ��������� ������");
            break;
        case NoRoots:
            printf ("��� ������");
            break;
        case OneRoot:
            printf ("������ ���� ������ %lg", x1);
            break;
        case TwoRoots:
            printf ("������� ��� �����: %lg � %lg", x1, x2);
            break;
        default:
            break;
    }
    return 0;
}


bool isNull (double q)
{
    return fabs(q) < 0.000000000001;
}


SolveCase solveSquare (double a, double b, double c, double *x1, double *x2)
{
    if(isNull(a) && isNull(b) && isNull(c))
        return InfiniteNumberOfRoots;


    if (isNull(a))
    {
        if (isNull(b))
            return NoRoots;
        else
        {
            *x1 = -c / b;
            return OneRoot;
        }
    }

    //a != 0
    double dt = b*b - 4*a*c;
    if(dt < 0)
    {
        return NoRoots;
    }
    else if (isNull(dt))
    {
        *x1 = -b/(2*a);
        return OneRoot;
    }

    //a != 0 && dt > 0
    *x1 = (-b - sqrt(dt))/(2*a);
    *x2 = (-b + sqrt(dt))/(2*a);
    return TwoRoots;
}
