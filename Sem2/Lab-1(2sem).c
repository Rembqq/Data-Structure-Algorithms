#include <stdio.h>
int powr( int x, unsigned int n)
{
    int i = -1;
    printf("i = %d n= %d \n", i , n);
    if(n == 0){ i = 1; }
    else
    {
        i = x*powr(x,n-1);
    }
    printf("i = %d n= %d \n", i, n);
    return i;
}
// }
// int fib( unsigned int n) {
//     int i = -1;
//     if (n < 2) {
//         i = n;
//     }
//     else
//     {
//         i = fib(n-2);
//         i += fib(n-1);
//     }
//     return i;
// }
int main()
{
    // int x, sum = 0;
    // scanf("%d", &x);
    // printf("%d", x);
    powr(5, 4);
    //fib(7);
}