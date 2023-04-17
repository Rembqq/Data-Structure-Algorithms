#include <stdio.h>
#include "Lab-1\Return.h"
#include "Lab-1\Descent.h"
#include "Lab-1\Combined.h"
#include "Lab-1\Loop.h"

int main()
{
    int n = 0;
    double x = 0, sum = 0;
    for(;x >= 1 || x <= -1 || n <= 2;)
    {
        printf("Enter x(-1 < x < 1): ");
        scanf("%lf", &x);
        printf("\n");
        printf("Enter n(n > 2): ");
        scanf("%d", &n);
    }
    // Recursive Return
    printf("\nReturn\n");
    printf("%lf", ret_sum_of_series(n, x));

    // Descent
    printf("\nDescent\n");
    printf("%lf", Sum(n, x));

    // Combined
    printf("\nCombined\n");
    printf("%lf", Comb_Sum(n, x));

    //Looped
    printf("\nLooped\n");
    printf("%lf", loop_sum(n, x));
}

