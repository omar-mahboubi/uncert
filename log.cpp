#include <iostream>
#include <cmath>
#include "uncert.h"
using namespace std;

void log_product() {
    int n1, n2, power1, power2;
    float sys1, sys2, a, b, c;
    float array1[200], array2[200];
    float x, dx;
    cout << "Please input a, b, c, n, k in order\n" ;
    cin >> a; cin >> b; cin >> c; cin >> power1; cin >> power2;
    cout << "Input the number of measurements for x1.\n"; cin >> n1;
    cout << "Please input the systematic uncertainty for x1 (in the same unit as the measurements)\n"; cin >> sys1;
    cout << "Please input the measurements of x1, one-by-one:\n";
    for (int i=0 ; i<n1 ; i++) {
        cin >> array1[i];
    }
    print_line();
    cout << "Input the number of measurements for x2.\n"; cin >> n2;
    cout << "Please input the systematic uncertainty for x2 (in the same unit as the measurements)\n"; cin >> sys2;
    cout << "Please input the measurements of x2, one-by-one:\n";
    for (int i=0;i<n2;i++) {
        cin >> array2[i];
    }
    print_line();
    Result x1 = calculate (n1, sys1, array1);
    Result x2 = calculate (n2, sys2, array2);
    x = (a * pow(x1.avg , power1)) * (b *pow(x2.avg , power2)) + c ;
    dx = x * ((x1.delta * power1 / x1.avg) + (x2.delta * power2 / x2.avg)) ;
    cout << "The value of z, adjusted for uncertainty, is: " << x << " + " << dx << endl;
}
