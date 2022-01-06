/* finding a root for p(x)=x^3-x-1 polynomial
using Newton-Raphson Method */

#include <iostream>
#include <math.h>

double p(double x); //polynomial
double df(double x);//derivative

int main() {
    int iterations = 0;
    double x0 = 0.0;
    double xn;
    double tol = 1e-3; //0.001
    
    while (fabs(p(x0))>tol) {
        xn = x0 - p(x0)/df(x0);
        x0 = xn;
        iterations++;
    }
    
    std::cout<<"The root is: "<<xn<<std::endl;
    std::cout<<"Number of interations: "<<iterations;
    
    return 0;
}

double p(double x) {
    double poly = pow(x,3)-x-1;
    return poly;
}

double df(double x) {
    double deriv = 3*pow(x,2)-1;
    return deriv;
}

/* Output:
The root is: 1.32472
Number of interations: 20
*/
