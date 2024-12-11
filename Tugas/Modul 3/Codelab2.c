#include <stdio.h>

// Mendefinisikan enum untuk kelas tiket
enum TicketClass {
    Economy,
    Business,
    FirstClass
};

int main() {
    int pilihan;

    // Menampilkan pilihan kelas tiket
    printf("Pilih Kelas Tiket:\n");
    printf("1. Economy\n");
    printf("2. Business\n");
    printf("3. First Class\n");
    printf("Masukkan pilihan (1-3): ");
    scanf("%d", &pilihan);

    // Menggunakan if-else untuk menentukan harga berdasarkan pilihan user
    if (pilihan == 1) {
        printf("Harga tiket kelas ekonomi: $200\n");
    } else if (pilihan == 2) {
        printf("Harga tiket kelas bisnis: $500\n");
    } else if (pilihan == 3) {
        printf("Harga tiket kelas utama: $1000\n");
    } else {
        printf("Pilihan tidak valid. Silakan masukkan angka antara 1-3.\n");
    }

    return 0;
}
