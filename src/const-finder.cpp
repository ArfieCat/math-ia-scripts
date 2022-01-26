/* 
const-finder.cpp
reverse engineers constants given some parameters
runs the function for many input values
prints output to an excel-readable .csv file
*/

#include <iostream>

#define LAST 64
#define INTERVAL 0.0625F                        // match fast-inv-sqrt.cpp

/*
the following function is taken verbatim from quake 3
*/

long solve(float x, float y)
{
    long i, j, constant;

    i = * (long *) &x;
    i *= 0.5F;

    j = * (long *) &y;

    constant = j + i;

    return constant;
}

int main()
{
    FILE *f = fopen("const-finder.csv", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "Input,Output\n");

    double d, r1, r2;
    long c1, c2;
    for (double x = 0; x <= LAST; x += INTERVAL)
    {
        d = -1 / sqrt(x);                       // last coefficient of the cubic polynomial
        r1 = 2 * d;                             // approximation for the roots based on observed correlation
        r2 = -d;

        c1 = solve((float) x, r1);
        c2 = solve((float) x, r2);

        fprintf(f, "%f,%x,%x\n", (float) x, c1, c2);
    }

    fclose(f);

    return 0;
}