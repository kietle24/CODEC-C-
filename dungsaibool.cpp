#include <stdio.h>

int main() {
    long long n, x, y, k;
    scanf("%lld %lld %lld %lld", &n, &x, &y, &k);

    // S? lu?ng xe hoi t?i da c� th? d?
    long long max_cars = (n - y) / (x + k);

    // T?ng chi?u d�i c�n du l?i c?a b�i xe khi b�i xe d� d?y
    long long remaining_space = n - max_cars * (x + k);

    printf("%lld %lld\n", max_cars, remaining_space);

    return 0;
}
