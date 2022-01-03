/* 

From Newton divided difference (NDD) formula,
find the interpolating polynomial coefficients for
the data points (-1, 3), (0, 1), (1, 3), (3, 43)

*/

#include <iostream>

int main() {
    //x and y array of interpolating points
    int x[4] = { -1, 0, 1, 3};
    int y[4] = { 3, 1, 3, 43};

    //empty array to be populated with NDD coefficients
    //y[0] for definition is the first coefficient
    int ndd[4] = {y[0], 0, 0, 0};
    int aux = 3;
    int n = 1;

    for (int count = 1; count < 4; count++) {

        for (int num = 0; num < aux; num++) {

            y[num]=(y[num+1]-y[num])/(x[num+n]-x[num]);

        }
        
        ndd[count] = y[0];
        aux--;
        n++;

    }

    std::cout << "NDD Coefficients for data points are: " << std::endl;
    
    for (int count = 0; count < sizeof(x)/sizeof(int); count++) {

        std::cout << 'a' << count+1 << ": "
        << ndd[count] << " " << std::endl;
    }
    return 0;

}

/* 

(Output:)

NDD Coefficients for data points are: 
a1: 3
a2: -2
a3: 2
a4: 1

 */