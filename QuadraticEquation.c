#include <math.h>
#include <stdio.h>
#include <TXLib.h>

const double Precision = 1E-6;

int SolveQE (double a, double b, double c, double *x1, double *x2)
    {

    double dscr = b*b - 4*a*c;

    if (dscr > 0)
        {
        if (a == 0)
            {
            *x1 = (-(c / b));
            return 1;
            }
        else
            {
            *x1 = ((-b + sqrt(dscr)) / (2*a));
            *x2 = ((-b - sqrt(dscr)) / (2*a));
            return 2;
            }
        }

    if (dscr == 0)
        {
        if (a == 0)
            {
             if (c == 0)
                {
                return -1;
                }
            if (c != 0)
                {
                return 0;
                }
            }
        *x1 = (-b/ (2*a));
        return 1;
        }

    if (dscr < 0)
        {
        return 0;
        }
    }

int main()
    {

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    printf ("- ��� ��������� ��� ������� ���������� ���������\n\n");
    printf ("- ������� ������������ a, b, c ����� ������: ");

    scanf ("%lg %lg %lg", &a, &b, &c);              /*��������� ������ &a, &b, &c*/
    int nRoots = SolveQE (a, b, c, &x1, &x2);

    switch (nRoots)
        {
        case 0: printf ("\n����� �����������");
                break;
        case 1: printf ("\nx = %lg\n", x1);
                break;
        case 2: printf ("\nx1 = %lg, x2 = %lg", x1, x2);
                break;
        case -1: printf ("\n����� �����");
                break;
        default: printf ("\n������: ���������� ������ = %d\n", nRoots);
                 return 1;
        }
    return 0;
    }
