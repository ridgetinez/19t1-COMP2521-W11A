#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main(void)
{
    printf("%d\n", fib(5));
}

int fibR(int, int*);

int fib(int n)
{
    int *arr = malloc(sizeof(int) * (n+1));
    for (int i = 0; i <= n; i++) {
        arr[i] = -1;
    }
    free(arr);
    return fibR(n, arr);
}

int fibR(int n, int *memo)
{
    if (memo[n] != -1) return memo[n];
    if (n == 1) return 1;
	if (n == 2) return 1;
	memo[n] = (fibR (n - 1, memo) + fibR (n - 2, memo));
    return memo[n];
}
