#include <stdio.h>
#include "Lab-1\Return.h"
#include "Lab-1\Descent.h"
#include "Lab-1\Combined.h"

int main()
{
    int n;
    double x, sum = 0;
    printf("Enter x(-1 < x < 1): ");
    scanf("%lf", &x);
    printf("\n");
    printf("Enter n(n > 2): ");
    scanf("%d", &n);

    // Recursive Return
    printf("\nReturn\n");
    printf("%lf", ret_sum_of_series(n, x));

    // Descent
    printf("\nRecursive Descent\n");
    //printf("%f", des_recurs_func(1, x, n, sum));
    //printf("%lf", des_recursive_sum(x, n, 0, 0));
    printf("%lf", Sum(n, x));

    // // Combined
    printf("\nCombined\n");
    //printf("%lf", comb_recurs_func(x, n, sum));
    //printf("%f", comb_sum_of_series(n, x));
    printf("%lf", Comb_Sum(n, x));
}

