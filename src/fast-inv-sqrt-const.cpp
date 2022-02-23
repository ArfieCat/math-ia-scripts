/* 
    fast-inv-sqrt-const.cpp
    fast inverse square root with new constant formula
    runs the function for many input values
    prints output to an excel-readable .csv file
*/

#include <iostream>

#define LAST 64
#define INTERVAL 0.0625F                        // match fast-inv-sqrt.cpp

/*
    calculates (approximately) optimal constant to replace 0x5f3579df
*/

long solve(double x)
{
    double a, b, c, d, sum;
    const double pi = 3.141592653589793238;

    a = 240935 - abs(240935 * sin(pi * log2(x)));
    b = 719629 - abs(719629 * sin(pi * (log2(x) / log2(4))));    // change of base to log4(x)
    c = -1 * abs(148346 * sin(pi * log2(x)));
    d = -36824 * sin(pi * log2(x));
    
    sum = a + b + c + d;

    return (long) sum + 1597069260;
}

float Q_rsqrt(float x, long constant)
{
    long i;
    float x2, y;

    x2 = x * 0.5F;
    y = x;
    i = *(long*) &y;
    i = constant - (i >> 1);
    y = *(float*) &i;
    y = y * (1.5F - (x2 * y * y));

    return y;
}

int main()
{
    FILE *f = fopen("fast-inv-sqrt-const.csv", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "Input,Constant,Output\n");

    float y;
    long constant;
    for (float x = 0; x <= LAST; x += INTERVAL)
    {
        constant = solve((double) x);
        y = Q_rsqrt(x, constant);

        fprintf(f, "%f,%x,%f\n", x, constant, y);
    }

    fclose(f);

    return 0;
}