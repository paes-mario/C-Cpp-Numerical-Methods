/*find a root for p(x)=x^3-x-1 polynomial
use Bisection Method with x in [1,2] interval */

#include <stdio.h>
#include <math.h>

//declaring p(x) function
double p(double x);

int main() {
    //defining variables
    double a = 1.0; //lower limit
    double b = 2.0; //upper limit
    double tol = 1e-5; //tolerance
    int iterations = 0; //iterations counter

    //bisection method
    double m = (a + b)/2.0;
    
    //iterative loop
    do {
        if (p(a)*p(m)<0.0) {
            b = m;
        }
        else {
            a = m;
        }
        m = (a + b)/2.0;
        iterations++;
    } while(fabs(p(m))>tol);

    //printing result
    printf("The root of the polynomial is: %lf\n", m);
    printf("The number of interations is: %d", iterations);

    return 0;    
}

//defining polynomial
double p(double x) {
    double res = pow(x,3)-x-1;
    return res;
}

/*Output:
The root of the polynomial is: 1.324718
The number of interations is: 17
*/

