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
float comb_recurs_func(float x, int n, float sum)
{
    if (n == 1) {
        // it could be just return ++sum, but in my opinion 
        // this way is more readable
        sum++;
        return sum;
    } 
    else if (n == 2) {
        sum += -x/2;
        return comb_recurs_func(x, n-1, sum);
    } 
    else {
        // as we recall n == 2 statement, it refers to n == 1 where we add
        // +1 to sum, therefore I have to pass -1 instead of 0 in sum
        float last_el = comb_recurs_func(x, n-1, -1) * x * (2*n-3)/(2*n);
        sum += last_el;
        return comb_recurs_func(x, n-1, sum);
    }
}

float ret_recurs_func(float x, int n, float sum)
{
    if (n == 1) {
        // it could be just return ++sum, but in my opinion 
        // this way is more readable
        sum++;
        return sum;
    } 
    else if (n == 2) {
        sum += -x/2;
        return comb_recurs_func(x, n-1, sum);
    } 
    else {
        // as we recall n == 2 statement, it refers to n == 1 where we add
        // +1 to sum, therefore I have to pass -1 instead of 0 in sum
        float last_el = comb_recurs_func(x, n-1, -1) * x * (2*n-3)/(2*n);
        sum += last_el;
        return comb_recurs_func(x, n-1, sum);
    }
}

int main()
{
    int n, last_elem = 1;
    float x, sum = 0;
    printf("Enter x(-1 < x < 1): ");
    scanf("%f", &x);
    printf("\n");
    printf("Enter n(n > 2): ");
    scanf("%d", &n);

    // Recursive Return
    printf("\nReturn\n");
    // for (int i = 0; i < n; i++) {
    //     ret_recurs_func(x, i, &sum);
    // }

    // Descent
    printf("\nRecursive Descent\n");
    printf("%f", des_recurs_func(0, x, n, sum));

    // // Combined
    // printf("\nCombined\n");
    // printf("%f", comb_recurs_func(x, n, sum));

}