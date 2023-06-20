#pragma once

#include <iostream>
#include <math.h>

double S(double * x, double * y, int n)
{
    double sxy = 0, sx=0, sy=0;
    for(int i = 0; i < n; i++)
    {
        sxy += x[i] * y[i];
        sx += x[i];
        sy += y[i];
    }

    return (n*sxy) - (sx *sy);

}

double correlacao(double * x, double * y, int n)
{

    double sxy = S(x, y, n);
    double sxx = S(x, x, n);
    double syy = S(y, y, n);

    double r = sxy/sqrt(syy*sxx);

    return r;
}

void aplicar_correlacao()
{
    int n; std::cin >> n;

    double * x = (double*) malloc(sizeof(double) * n),
           * y = (double*) malloc(sizeof(double) * n);

    for(int i = 0; i < n; i++)
        std::cin >> x[i];

    for(int i = 0; i < n; i++)
        std::cin >> y[i];


    auto a = correlacao(x, y, n);

    std::cout << a << std::endl;

    free(x); free(y);    

}