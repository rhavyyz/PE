#pragma once
#include<iostream>

// using namespace std;

typedef struct
{
    double a, b;
} reta;

reta regressao(double *x_v, double * y_v, int n)
{
    double xx= 0, xy = 0, x = 0, y=0; 
    for(int i = 0; i < n; i++)
    {
        xx += x_v[i] * x_v[i];
        xy += x_v[i] * y_v[i];
        y += y_v[i];
        x += x_v[i];
    }
    double Sxy = n*(xy) - x*y,
           Sxx = n*(xx) - x*x;

    double a = Sxy/Sxx;
    double b = y/n - a*x/n;
    
    return {a, b};
}

void aplicar_regressao()
{
    int n; std::cin >> n;

    double * x = (double*) malloc(sizeof(double) * n),
           * y = (double*) malloc(sizeof(double) * n);

    for(int i = 0; i < n; i++)
        std::cin >> x[i];

    for(int i = 0; i < n; i++)
        std::cin >> y[i];


    auto a = regressao(x, y, n);

    std::cout << a.a << std::endl <<  a.b << std::endl;

    free(x);
    free(y);

}