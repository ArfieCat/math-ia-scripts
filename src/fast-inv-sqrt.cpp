/* 
    fast-inv-sqrt.cpp
    quake 3 implementation of fast inverse square root
    runs the function for many input values
    prints output to an excel-readable .csv file
*/

#include <iostream>

#define LAST 64
#define INTERVAL 0.0625F                        // powers of 2 to reduce floating point precision errors

/*
    the following function is taken verbatim from the quake 3 source code
*/

float Q_rsqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//  y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}

int main()
{
    FILE *f = fopen("fast-inv-sqrt.csv", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "Input,Output\n");

    float y;
    for (float x = 0; x <= LAST; x += INTERVAL)
    {
        y = Q_rsqrt(x);
        fprintf(f, "%f,%f\n", x, y);
    }

    fclose(f);

    return 0;
}