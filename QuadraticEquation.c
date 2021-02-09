#include <math.h>
#include <stdio.h>
#include <TXLib.h>

#define INF_N_ROOTS -1

const double Precision = 1E-10;

int SolveQE (double a, double b, double c, double *x1, double *x2);

int IsZero (double value);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
    {

    printf ("- Quadratic equation solver\n\n");
    printf ("- Enter coefficients a, b, c: ");

    double a = 0, b = 0, c = 0;

    if(scanf("%lg %lg %lg", &a, &b, &c) != 3)
        {
        printf("\nError: wrong data");
        return 1;
        }

    double x1 = 0, x2 = 0;
    int nRoots = SolveQE (a, b, c, &x1, &x2);

    switch (nRoots)
        {
        case 0: printf ("\nNo roots");
                break;
        case 1: printf ("\nx = %lg\n", x1);
                break;
        case 2: printf ("\nx1 = %lg, x2 = %lg", x1, x2);
                break;
        case INF_N_ROOTS: printf ("\nAny number");
                break;
        default: printf ("\nError: number of roots = %d\n", nRoots);
                 return 1;
        }
    return 0;
    }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int SolveQE (double a, double b, double c, double *x1, double *x2)
    {

    if (IsZero(a))
        {
        if (!IsZero(b))
            {
            if (!IsZero(c))     // <-- a=0 b!=0 c!=0
                {
                *x1 = (-(c / b));
                return 1;
                }
            else    // <-- a=0 b!=0 c=0
                {
                *x1 = 0;
                return 1;
                }
            }
        else
            {
            if (!IsZero(c))    // <-- a=0 b=0 c!=0
                {
                return 0;
                }
            else    // <-- a=0 b=0 c=0
                {
                return INF_N_ROOTS;
                }
            }
        }

    else if (IsZero(c))
        {
         if (!IsZero(a))
            {
            if (!IsZero(b))    // <-- a!=0 b!=0 c=0
                {
                *x1 = 0;
                *x2 = (-(b / a));
                return 2;
                }
            else    // <-- a!=0 b=0 c=0
                {
                *x1 = 0;
                return 1;
                }
            }
        }

    else if (IsZero(b))
        {
        if (!IsZero(a))
            {
            if (c < 0)    // <-- a!=0 b=0 c>0
                {
                double sqrt_mns_c_div_a = sqrt(-(c / a));
                *x1 = sqrt_mns_c_div_a;
                *x2 = -sqrt_mns_c_div_a;
                return 2;
                }
            else    // <-- a!=0 b=0 c<0
                {
                return 0;
                }
            }
        }

    else    // <-- a!=0 b!=0 c!=0
        {
        double dscr = b * b - 4 * a * c;

        double reverse2a = 1 / (2 * a);

        if (dscr > 0)
            {
            double sqrt_dscr = sqrt(dscr);

            *x1 = (-b + sqrt_dscr) * reverse2a;
            *x2 = (-b - sqrt_dscr) * reverse2a;
            return 2;
            }
        else if (IsZero(dscr))
            {
            *x1 = -b * reverse2a;
            return 1;
            }
        else
            {
            return 0;
            }
        }

    return 1;

    }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int IsZero (double value)
    {
    if (fabs(value) > Precision)
        {
        return 0;
        }
    else
        {
        return 1;
        }
    }
