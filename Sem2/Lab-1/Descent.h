//we have to have index to pass the position between function calls
// float des_recurs_func(int i, float x, int n, float sum)
// {
//     if (i == 1) {
//         sum++;
//         if (n == 1) {
//             return sum;
//         } else {
//             return des_recurs_func(i+1, x, n-1, sum);
//         }
//     } else if (i == 2) {
//         sum += -x/2;
//         if (n == 1) {
//             return sum;
//         } else {
//             return des_recurs_func(i+1, x, n-1, sum);
//         }
//     } else {
//         float f = des_recurs_func(i-1, x, n, 0) * x * (2*i-3)/(2*i);
//         sum += f;
//         if (n == 1) {
//             return sum;
//         } else {
//             return des_recurs_func(i+1, x, n-1, sum);
//         }
//     }
// }

// double des_recursive_sum(double x, int n, int i, double sum) {
//     if (i == 0) {
//         sum++;
//         if(n == 1)
//         {
//             return sum;
//         }
//         else {
//             return des_recursive_sum(x, n-1, i+1, sum);
//         }
//     }
//     else if(i == 1)
//     {
//         sum += -x/2;
//         if(n == 1)
//         {
//             return sum;
//         }
//         else {
//             return des_recursive_sum(x, n-1, i+1, sum);             
//         }
//     } 
//     else {
//         double last_el = des_recursive_sum(x, n, i-1, 0) * x * (2 * i - 3) / (2 * i);
//         sum += last_el;
//         if(n == 1)
//         {
//             return sum;
//         }
//         else {
//             return des_recursive_sum(x, n-1, i+1, sum);
//         }
//     }
// }
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