#include <iostream>
#include <cmath>
using namespace std;

struct Result {
    float avg;
    float delta;
};

float avg (int n, float array[200]) {
    float sum = 0;
    for (int i=0;i<n;i++){
        sum += array[i];
    }
    return (sum/float(n));
}

float delta (int n, float sys, float avg, float array[200]) {
    float random = 0;
    for (int i=0; i<n; i++) {
        random += pow((avg-array[i]),2);
    }
    random = random / 4.0;
    return sqrt(pow(sys,2)+pow(random,2));
}

Result calculate (int n, float sys, float array[200]) {
    Result r;
    float sum = 0;
    float random = 0;
    for (int i=0;i<n;i++){
        sum += array[i];
    }
    r.avg = (sum/float(n));
    for (int i=0; i<n; i++) {
        random += pow((r.avg-array[i]),2);
    }
    random = random / 4.0;
    r.delta = sqrt(pow(sys,2)+pow(random,2));
    return r;
}

void single () {
    int n;
    float array[200];
    float sys;
    cout << "Please input the number of measurements.\n"; cin >> n;
    cout << "Please input the systematic uncertainty (in the same unit as the measurements)\n"; cin >> sys;
    cout << "Please input the measurements, one-by-one:\n";
    for (int i=0;i<n;i++) {
        cin >> array[i];
    }
    cout << "----------------------------------------------------------------------------------------------------\n";
    Result x = calculate (n, sys, array);
    cout << "The value, adjusted for uncertainty, is: " << x.avg << " ± " << x.delta << endl;
}

void sum (char sign) {
    int n1, n2, sys1, sys2;
    float array1[200], array2[200];
    float x, dx;
    cout << "Input the number of measurements for x1.\n"; cin >> n1;
    cout << "Please input the systematic uncertainty for x1 (in the same unit as the measurements)\n"; cin >> sys1;
    cout << "Please input the measurements of x1, one-by-one:\n";
    for (int i=0;i<n1;i++) {
        cin >> array1[i];
    }
    cout << "----------------------------------------------------------------------------------------------------\n";
    cout << "Input the number of measurements for x2.\n"; cin >> n2;
    cout << "Please input the systematic uncertainty for x2 (in the same unit as the measurements)\n"; cin >> sys2;
    cout << "Please input the measurements of x2, one-by-one:\n";
    for (int i=0;i<n2;i++) {
        cin >> array2[i];
    }
    cout << "----------------------------------------------------------------------------------------------------\n";
    Result x1 = calculate (n1, sys1, array1);
    Result x2 = calculate (n2, sys2, array2);
    switch (sign) {
        case ('+'): x = (x1.avg + x2.avg) / 2.0; break;
        case ('-'): x = (x1.avg - x2.avg) / 2.0; break;
    }
    dx = x1.delta + x2.delta ;
    cout << "The value of x1 + x2, adjusted for uncertainty, is: " << x << " + " << dx << endl;
}

int main() {
    int choice;
    cout << "Welcome to Uncertainty Calculator!\n" ;
    cout << "Please note that this is a work in progress.\n" ;
    cout << "Please choose the calculation type (type the number of the type in question)\n" ;
    cout << "(1) Single variable x\n" ;
    cout << "(2) Sum of two variables x1 and x2\n" ;
    cin >> choice;
    cout << "----------------------------------------------------------------------------------------------------\n";
    switch (choice) {
        case (1): single(); break;
        case (2): sum('+'); break;
        default:
            cout << "Please choose a valid value!" << endl; return 1;
    }
    cout << "----------------------------------------------------------------------------------------------------\n";
    cout << "Thank you for using this software!\n";
    cout << "made by MAHBOUBI Omar Amine, GPG public key 59DF7048E99A634ADBF01ABC9C048C00C65E74EC" << endl;
    return 0;
}
