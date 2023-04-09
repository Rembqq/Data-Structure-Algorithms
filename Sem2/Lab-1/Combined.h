
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