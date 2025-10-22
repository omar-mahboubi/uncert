#include <iostream>
#include "uncert.h"
using namespace std;

void sum (char sign) {
    int n1, n2;
    float sys1, sys2;
    float array1[200], array2[200];
    float x, dx;
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
    switch (sign) {
        case ('+'): x = (x1.avg + x2.avg) / 2.0; break;
        case ('-'): x = (x1.avg - x2.avg) / 2.0; break;
    }
    dx = x1.delta + x2.delta ;
    cout << "The value of x1 + x2, adjusted for uncertainty, is: " << x << " + " << dx << endl;
}
