#include <stdio.h>

// Fungsi untuk menghitung faktorial
int sum(int angka);

// Fungsi untuk menghitung nilai Fibonacci
int fibonacci(int deret_fibonacci);

int main() {
    int angka, deret_fibonacci;

    // Input dan output faktorial
    printf("Masukkan angka untuk menghitung faktorial: ");
    scanf("%d", &angka);
    int result = sum(angka);
    printf("Faktorial dari %d adalah: %d\n", angka, result);

    // Input dan output deret Fibonacci
    printf("Masukkan angka untuk menghasilkan deret Fibonacci: ");
    scanf("%d", &deret_fibonacci);
    printf("Deret Fibonacci hingga suku ke-%d adalah: ", deret_fibonacci);
    for (int i = 0; i < deret_fibonacci; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}

// Definisi fungsi faktorial
int sum(int angka) {
    if (angka > 1) {
        return angka * sum(angka - 1);
    } else {
        return 1;
    }
}

// Definisi fungsi Fibonacci
int fibonacci(int deret_fibonacci) {
    if (deret_fibonacci == 0 || deret_fibonacci == 1) {
        return deret_fibonacci;
    } else {
        return fibonacci(deret_fibonacci - 1) + fibonacci(deret_fibonacci - 2);
    }
}
