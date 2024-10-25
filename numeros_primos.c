#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int prime_count = 0;
    for (int num = 1; num <= 500; num++) {
        if (is_prime(num)) {
            printf("%d\n", num);
            prime_count++;
        }
    }
    printf("Total de numeros primos: %d\n", prime_count);

    return 0;
}
