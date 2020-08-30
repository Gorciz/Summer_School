#include <math.h>
#include <stdio.h>
#include <TXLib.h>

#define INF_N_ROOTS -1
#define EQL_TO_ZERO 0
#define LSS_THAN_ZERO 1
#define GRT_THAN_ZERO 2

const double Precision = 1E-10;

int SolveQE (double a, double b, double c, double *x1, double *x2);

int ZeroComp (double param);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
    {

    printf ("- Quadratic equation solver\n\n");
    printf ("- Enter coefficients a, b, c: ");

    double a = 0, b = 0, c = 0;
    scanf ("%lg %lg %lg", &a, &b, &c);              //ispravit'(chto-to ya ne ponyal kak ispravlyat')

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

    if (ZeroComp(a) == EQL_TO_ZERO)
        {
        if (ZeroComp(b) == GRT_THAN_ZERO or ZeroComp(b) == LSS_THAN_ZERO)
            {
            *x1 = (-(c / b));
            return 1;
            }
        else
            {
            if (ZeroComp(c) == EQL_TO_ZERO)
                {
                return INF_N_ROOTS;
                }
            else
                {
                return 0;
                }
            }
        }

    else
        {

        double dscr = b * b - 4 * a * c;

        double var1 = -b / (2 * a);                  // var1?

        if (ZeroComp(dscr) == GRT_THAN_ZERO)
            {

            double var2 = sqrt(dscr) / (2 * a);      // var2?

            *x1 = var1 + var2;
            *x2 = var1 - var2;
            return 2;
            }
        else if (ZeroComp(dscr) == EQL_TO_ZERO )
            {
            *x1 = var1;
            return 1;
            }
        else
            {
            return 0;
            }
        }
    }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int ZeroComp (double param)
    {

    if (param > Precision)
        {
        return GRT_THAN_ZERO;
        }
    else if (param < - Precision)
        {
        return LSS_THAN_ZERO;
        }
    else
        {
        return EQL_TO_ZERO ;
        }
    }
