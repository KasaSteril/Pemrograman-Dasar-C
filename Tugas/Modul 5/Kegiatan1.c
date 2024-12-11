#include <stdio.h>
#include <string.h>

int main() {
    int jumlahBuah;
    const int maksimalBuah = 10; // Jumlah maksimal buah
    const int panjangNama = 50; // Panjang maksimal nama buah
    char buah[maksimalBuah][panjangNama]; // Array untuk menyimpan nama buah
    char temp[panjangNama];              // Variabel sementara untuk pengurutan

    // Meminta jumlah buah dari pengguna
    printf("Masukkan jumlah buah (maksimal %d): ", maksimalBuah);
    if (scanf("%d", &jumlahBuah) != 1) {
        printf("Input tidak valid. Harus berupa angka.\n");
        return 1;
    }
    if (jumlahBuah > maksimalBuah || jumlahBuah <= 0) {
        printf("Jumlah buah harus antara 1 hingga %d.\n", maksimalBuah);
        return 1;
    }

    // Membersihkan buffer input
    getchar(); 

    // Meminta pengguna memasukkan nama-nama buah
    for (int i = 0; i < jumlahBuah; i++) {
        printf("Masukkan nama buah ke-%d: ", i + 1);
        if (fgets(buah[i], panjangNama, stdin) == NULL) {
            printf("Terjadi kesalahan saat membaca input.\n");
            return 1;
        }
        // Menghapus newline di akhir input jika ada
        buah[i][strcspn(buah[i], "\n")] = '\0';
    }

    // Menampilkan nama buah dalam urutan yang diinputkan
    printf("\n--- Nama Buah dalam Urutan yang Dimasukkan ---\n");
    for (int i = 0; i < jumlahBuah; i++) {
        printf("%d. %s\n", i + 1, buah[i]);
    }

    // Mengurutkan nama buah secara alfabetis (abjad)
    for (int i = 0; i < jumlahBuah - 1; i++) {
        for (int j = i + 1; j < jumlahBuah; j++) {
            if (strcmp(buah[i], buah[j]) > 0) {
                // Menukar posisi array buah[i] dan buah[j]
                strcpy(temp, buah[i]);
                strcpy(buah[i], buah[j]);
                strcpy(buah[j], temp);
            }
        }
    }

    // Menampilkan nama buah dalam urutan abjad
    printf("\n--- Nama Buah dalam Urutan Abjad ---\n");
    for (int i = 0; i < jumlahBuah; i++) {
        printf("%d. %s\n", i + 1, buah[i]);
    }

    printf("\n=== Code Execution Successful ===\n");
    return 0;
}
