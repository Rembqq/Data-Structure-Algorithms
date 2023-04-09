#include <stdio.h>

double ret_recursive_sum(int n, double x) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return -x/2;
    } else {
        return ret_recursive_sum(n-1, x) * x * (2*n - 3) / (2*n);
    }
}

double ret_sum_of_series(int n, double x) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ret_recursive_sum(i, x);
    }
    return sum;
}
