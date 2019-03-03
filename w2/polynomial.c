/*
 * Adrian Martinez
 * adrian.martinez@unsw.edu.au
 *
 * An O(n) algorithm, that's easiest to implement recursively, solving
 * polynomial evaluation at a given point x (one variable).
 */

#include <stdio.h>
#include <stdlib.h>

double eval_polynomial(double *, int, double); 

/* Main code attributed to Nicholas Hiebl */
int main(int argc, char **argv) {
    if (argc <= 1) {
      fprintf(stderr, "Give coefficients as command-line arguments\n");
      return EXIT_FAILURE;
    }

    double *coefficients;
    int n = argc - 1;
    coefficients = malloc(n * sizeof(double));
    int i;
    for (i = 1; i < argc; i++) {
      coefficients[i-1] = atof(argv[i]);
    }

    printf("%.2lf", coefficients[0]);
    for (i = 1; i < n; i++) {
      printf(" + %.2lfx^%d", coefficients[i], i);
    }
    printf("\nx = ");

    double x;
    scanf("%lf", &x);

    double f_x = eval_polynomial(coefficients, n, x);

    printf("f(x) = %lf\n", f_x);
}

double eval_polynomial(double *coeff, int n, double x) {
    double sum = 0;
    double currPower = 1;
    for (int i = 0; i < n; i++) {
      sum += coeff[i] * currPower;
      currPower *= x;
    }
    return sum;
}

















double horner(double *coeff, int n, int i, double x) {
    if (i == n-1) {
      return coeff[i];
    }
    return coeff[i] + x * horner(coeff, n, i+1, x);
}

double cumulating_power(double *coeff, int n, double x) {
    double sum = 0;
    double currExp = 1;
    for (int i = 0; i < n; i++) {
        sum += coeff[i] * currExp;
        currExp *= x;
    }
    return sum;
}

/*
3x^2 + 2x + 1

(ind) 1 + x(horner(coeff, 3, 1, x))
(ind) 1 + x(2 + x * horner(coeff, 3, 2, x))
(base) 1 + x(2 + 3x)
... collect
...
return sum;
*/
