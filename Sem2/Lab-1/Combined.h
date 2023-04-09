#include <stdio.h>


// float comb_recurs_func(float x, int n, float sum)
// {
//     if (n == 1) {
//         // it could be just return ++sum, but in my opinion 
//         // this way is more readable
//         sum++;
//         return sum;
//     } 
//     else if (n == 2) {
//         sum += -x/2;
//         return comb_recurs_func(x, n-1, sum);
//     } 
//     else {
//         // as we recall n == 2 statement, it refers to n == 1 where we add
//         // +1 to sum, therefore I have to pass -1 instead of 0 in sum
//         float last_el = comb_recurs_func(x, n-1, -1) * x * (2*n-3)/(2*n);
//         sum += last_el;
//         return comb_recurs_func(x, n-1, sum);
//     }
//}

// float recursive_sum(int n, float x) {
//     if (n == 0) {
//         return 1;
//     } else if (n == 1) {
//         return -x/2;
//     } else {
//         return recursive_sum(n-1, x) * x * (2*n - 3) / (2*n);
//     }
// }

// float comb_sum_of_series(int n, float x) {
//     float sum = 0;
//     for (int i = 0; i < n; i++) {
//         sum += recursive_sum(i, x);
//     }
//     return sum;
// }
double Fi(int i, double x) {
    if (i == 1) {
        return 1;
    }
    if (i == 2) {
        return -x/2;
    }
    else {
        double Fi_1 = Fi(i - 1, x);
        return Fi_1 * x * (2 * (i-1) - 3) / (2 * (i-1));
    }
}

double Comb_Sum(int n, double x) {
    if (n == 2) {
        return Fi(2, x) + Fi(1, x);
    }
    else {
        double sum_1 = Comb_Sum(n - 1, x);
        double Fn = Fi(n, x);
        return sum_1 + Fn;
    }
}