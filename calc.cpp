#include <cmath>
#include "uncert.hpp"
using namespace std;

Result calculate (int n, float sys, float array[ARRAY_LIMIT]) {
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
