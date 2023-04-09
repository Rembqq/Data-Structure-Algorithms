double loop_sum(int n, double x)
{
    double Fi = -x/2;
    double sum = Fi + 1;
    for (int i = 2; i <= n; i++) {
        Fi = Fi * x * (2 * i - 3) / (2 * i);
        sum += Fi;
    }
    return sum;
}