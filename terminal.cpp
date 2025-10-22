#ifdef _WIN32
#define NOBYTE
#include <windows.h>
#include <iostream>
int get_terminal_width() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return 80;
}
#else
#include <iostream>
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

void print_line(char c = '-') {
    int width = get_terminal_width();
    for (int i = 0; i < width; ++i)
        cout << c;
    cout << '\n';
}
