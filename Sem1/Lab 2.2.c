#include <stdio.h>
#include <stdlib.h>

int main()
{
	time_t t;
	srand((unsigned)time(&t));
	int M[10][10], T;
	for (int k = 0; k < 10; ++k)
	{
		for (int s = 0; s < 10; ++s)
		{
			M[k][s] = rand() % 100 + 1;
			printf("%i ", M[k][s]);
		}
		printf("\n");
	}
	for(int i = 0; i < 10; ++i)
	{
		if(i%2==1 && M[0][i-1] > M[0][i])
		{
			T = M[0][i];
			for(int j = 0; j < i)
		}
	}
}