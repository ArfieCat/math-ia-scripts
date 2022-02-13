/* 
    const-tester.cpp
    for testing a constant given a number
    runs in the console
*/

#include <iostream>

using namespace std;

float Q_rsqrt(float x, long constant)
{
    long i;
    float x2, y;

    x2 = x * 0.5F;
    y = x;
    i = * (long *) &y;
    i = constant - (i >> 1);
    y = * (float *) &i;
    y = y * (1.5F - (x2 * y * y));

    return y;
}

int main()
{
    double x;
    unsigned long constant;

    while (!cin.fail())
    {
        cout << "Input a number:\n";
        cin >> x;
        
        cout << "Input a constant:\n";
        cin >> constant;

        cout << "Result:\n";
        cout << Q_rsqrt((float) x, constant) << "\n";
        cout << 1 / sqrt(x) << "\n";
    }
    
    return 0;
}