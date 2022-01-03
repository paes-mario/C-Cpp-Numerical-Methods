/* 

From Newton divided difference (NDD) formula,
find the interpolating polynomial coefficients for
the data points (-1, 3), (0, 1), (1, 3), (3, 43)

*/

#include <iostream>

int main() {
    //x and y array of data points
    int x[4] = { -1, 0, 1, 3};
    int y[4] = { 3, 1, 3, 43};

    //empty array to be populated with NDD coefficients
    //y[0] for definition is the first NDD Coefficient
    int ndd[4] = {y[0], 0, 0, 0};
    int m = sizeof(x)/sizeof(int)-1;
    int n = 1;

    for (int i = 1; i < sizeof(x)/sizeof(int); i++) {

        for (int j = 0; j < m; j++) {

            y[j]=(y[j+1]-y[j])/(x[j+n]-x[j]);

        }
        
        ndd[i] = y[0];
        m--;
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