#include <stdio.h>
#include <math.h>

//we have to have index to pass the position between function calls
float des_recurs_func(int i, float x, int n, float sum)
{
    if (i == 1) {
        sum++;
        if (n == 1) {
            return sum;
        } else {
            return des_recurs_func(i+1, x, n-1, sum);
        }
    } else if (i == 2) {
        sum += -x/2;
        if (n == 1) {
            return sum;
        } else {
            return des_recurs_func(i+1, x, n-1, sum);
        }
    } else {
        float f = des_recurs_func(i-1, x, n, 0) * x * (2*i-3)/(2*i);
        sum += f;
        if (n == 1) {
            return sum;
        } else {
            return des_recurs_func(i+1, x, n-1, sum);
        }
    }
}

float comb_recurs_func(int n, float x)
{
    float sum = sqrt(1-x);
    float fi = -1;
    printf("fi = %f i = %d sum = %f\n", fi, n, sum);
    if(n == 2)
    {
        fi = -x/2;
    }
    else    
    {
        fi = comb_recurs_func(n-1, x) * x * (2*n - 3) / (2 * n);
        sum += fi;
    }
    printf("fi = %f i = %d sum = %f\n", fi, n, sum);  
    return fi;
}

float ret_recurs_func(int n, float x)
{
    float sum = 0;
    float fi = -1;
    printf("fi = %f i = %d sum = %f\n", fi, n, sum);
    
    if(n == 2)
    {
        fi = -x/2;
    }
    else    
    {
        fi = ret_recurs_func(n-1, x) * x * (2*n - 3) / (2 * n);
    }
    sum = sqrt(1-x);
    printf("fi = %f i = %d sum = %f\n", fi, n, sum);  
    return fi;
}

int main()
{
    int n, index = 1;
    float x, sum = 0;
    printf("Enter x(-1 < x < 1): ");
    scanf("%f", &x);
    printf("\n");
    printf("Enter n(n > 2): ");
    scanf("%d", &n);
    
    // Recursive Return
    //printf("\nReturn\n");
    //printf("%f",ret_recurs_func(n, x, 0));

    // Descent
    printf("\nRecursive Descent\n");
    printf("%f",des_recurs_func(index, x, n, sum));

    // // Combined
    // printf("\nCombined\n");
    // printf("%f",comb_recurs_func(index, x, n, sum));

}