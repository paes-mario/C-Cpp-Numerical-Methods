/* finding a root for f(x)=exp(-x^2)-cos(x) function
using Newton-Raphson Method */

#include <iostream>
#include <math.h>

double f(double x); //function
double df(double x);//derivative

int main() {
    int iterations = 0;
    double x0 = 1.5;
    double xn;
    double tol = 1e-12;
    
    while (fabs(f(x0))>tol) {
        xn = x0 - f(x0)/df(x0);
        x0 = xn;
        iterations++;
    }
    
    std::cout<<"The root is: "<<xn<<std::endl;
    std::cout<<"Number of interations: "<<iterations;
    
    return 0;
}

double f(double x) {
    double foo = exp(-x*x)-cos(x);
    return foo;
}

double df(double x) {
    double deriv = exp(-x*x)*-2*x+sin(x);
    return deriv;
}

/* Output:
The root is: 1.44741
Number of interations: 4 
*/