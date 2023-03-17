#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int four_to_i_power, standart_functions_amount = 0;
    int n;
    double result = 0, prod_sum;
    scanf_s("%i", &n);
    for (size_t i = 1; i <= n; ++i)
    {
        prod_sum = 1;
        four_to_i_power = 1;
        //production(denumerator)
        for (size_t j = 1; j <= i; ++j)
        {
            prod_sum *= (j + cos(j));
        }
        //power of 4 loop(numerator)
        for (size_t k = 0; k < i; ++k)
        {
            four_to_i_power *= 4;
        }
        result += (four_to_i_power - i) / prod_sum;
    }
    printf("%f", result);
    return 0;
}
