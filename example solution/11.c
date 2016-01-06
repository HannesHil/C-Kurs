#include <stdio.h>

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int n(int s) {
    if (s == 1) {
        return 1;
    }
    return s * n(s - 1);
}

int main() {
    printf("fib(10) = %d\n", fib(10));
    printf("10! = %d\n", n(10));
}
