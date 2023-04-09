
double F(int i, double x) {
    if(i == 2)
    {
        return -x/2;
    }
    else {
        double Fi_1 = F(i - 1, x);
        return Fi_1 * x * (2 * (i-1) - 3) / (2 * (i-1));
    }
}

double Sum(int n, double x) {
    if(n == 2)
    {
        return -x/2 + 1;
    }
    else {
        return F(n, x) + Sum(n - 1, x);
    }
}