/* 
    const-finder.cpp
    type puns floats to longs
    runs the function for many input values
    prints output to an excel-readable .csv file
*/

#include <iostream>

#define LAST 64
#define INTERVAL 0.0625F                        // match fast-inv-sqrt.cpp

long solve(float x)
{
    long i;

    i = *(long*) &x;

    return i;
}

int main()
{
    FILE *f = fopen("type-pun.csv", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "Input,Output\n");

    long i;
    for (float x = 0; x <= LAST; x += INTERVAL)
    {
        i = solve(x);

        fprintf(f, "%f,%x\n", x, i);
    }

    fclose(f);

    return 0;
}