#include <iostream>
#include "uncert.h"
using namespace std;

int main() {
    int choice;
    cout << "Welcome to Uncertainty Calculator!\n" ;
    cout << "Please note that this is a work in progress.\n" ;
    cout << "Please choose the calculation type (type the number of the type in question)\n" ;
    cout << "(1) Single variable x\n" ;
    cout << "(2) Sum of two variables x1 and x2\n" ;
    cout << "(3) Product: z = ax^n * bx^k + c (Logarithmic method)\n" ;
    cin >> choice;
    print_line();
    switch (choice) {
        case (1): single(); break;
        case (2): sum('+'); break;
        case (3): log_product(); break;
        default:
            cout << "Please choose a valid value!" << endl; return 1;
    }
    print_line();
    cout << "Thank you for using this software!\n";
    cout << "made by MAHBOUBI Omar Amine, GPG public key 59DF7048E99A634ADBF01ABC9C048C00C65E74EC" << endl;
    return 0;
}
