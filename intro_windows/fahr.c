#include <stdio.h>
/* K&R example 1.2 float */

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3d %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

