#include <stdio.h>
#define MAX 200  // Max digits needed for 100!

void multiply(int result[], int *res_size, int x) {
    int carry = 0;

    for (int i = 0; i < *res_size; i++) {
        int prod = result[i] * x + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry) {
        result[(*res_size)++] = carry % 10;
        carry /= 10;
    }
}

void factorial(int n) {
    int result[MAX];
    result[0] = 1;
    int res_size = 1;

    for (int x = 2; x <= n; x++) {
        multiply(result, &res_size, x);
    }

    printf("%d! =\n", n);
    for (int i = res_size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    factorial(100);
    return 0;
}
