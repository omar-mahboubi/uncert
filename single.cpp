#include <iostream>
#include "uncert.h"
using namespace std;

void single () {
    int n;
    float array[200];
    float sys;
    cout << "Please input the number of measurements.\n"; cin >> n;
    cout << "Please input the systematic uncertainty (in the same unit as the measurements)\n"; cin >> sys;
    cout << "Please input the measurements, one-by-one:\n";
    for (int i=0 ; i<n ; i++) {
        cin >> array[i];
    }
    print_line();
    Result x = calculate(n, sys, array);
    cout << "The value, adjusted for uncertainty, is: " << x.avg << " ± " << x.delta << endl;
}
