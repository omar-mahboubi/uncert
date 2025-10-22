#ifndef UNCERT
#define UNCERT

struct Result {
    float avg;
    float delta;
};

void print_line();

Result calculate (int n, float sys, float array[200]);

void single ();
void sum (char sign);
void log_product();

#endif // UNCERT
