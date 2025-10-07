#ifdef _WIN32
#define NOBYTE
#include <windows.h>
#include <iostream>
#include <cmath>
int get_terminal_width() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return 80;
}
#else
#include <iostream>
#include <cmath>
#include <sys/ioctl.h>
#include <unistd.h>
int get_terminal_width() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1)
        return 80;
    return w.ws_col;
}
#endif
using namespace std;

struct Result {
    float avg;
    float delta;
};

void print_line(char c = '-') {
    int width = get_terminal_width();
    for (int i = 0; i < width; ++i)
        cout << c;
    cout << '\n';
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
    for (int i=0 ; i<n ; i++) {
        cin >> array[i];
    }
    print_line();
    Result x = calculate (n, sys, array);
    cout << "The value, adjusted for uncertainty, is: " << x.avg << " ± " << x.delta << endl;
}

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

int main() {
    int choice;
    cout << "Welcome to Uncertainty Calculator!\n" ;
    cout << "Please note that this is a work in progress.\n" ;
    cout << "Please choose the calculation type (type the number of the type in question)\n" ;
    cout << "(1) Single variable x\n" ;
    cout << "(2) Sum of two variables x1 and x2\n" ;
    cin >> choice;
    print_line();
    switch (choice) {
        case (1): single(); break;
        case (2): sum('+'); break;
        default:
            cout << "Please choose a valid value!" << endl; return 1;
    }
    print_line();
    cout << "Thank you for using this software!\n";
    cout << "made by MAHBOUBI Omar Amine, GPG public key 59DF7048E99A634ADBF01ABC9C048C00C65E74EC" << endl;
    return 0;
}
