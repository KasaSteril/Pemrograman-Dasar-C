#include <stdio.h>

int main() {
    int umur;
    float hargatiket, hargafinal;
    
    // input buat umur penumpang
    printf("Masukkan umur penumpang: ");
    scanf("%d", &umur);
    
    // input buat tiket normal pesawat
    printf("Masukkan harga tiket normal: ");
    scanf("%f", &hargatiket);
    
    // Validasi umur dan kalkulasi harga tiket
    if (umur >= 0 && umur <= 120) {
        if (umur < 2) {
            printf("Penumpang mendapatkan tiket gratis.\n");
            hargafinal = 0;
        } else if (umur >= 2 && umur <= 12) {
        	hargafinal = hargatiket * 0.5;
            printf("Harga tiket untuk penumpang anak-anak adalah 50%% dari harga normal.\n");
        } else if (umur > 12 && umur <= 60) {
        	hargafinal = hargatiket;
            printf("Harga tiket untuk penumpang dewasa adalah harga normal.\n");
        } else {
        	hargafinal = hargatiket * 0.75;
            printf("Harga tiket untuk penumpang lanjut usia adalah 75%% dari harga normal.\n");
        }
        printf("Harga tiket final: %.2f\n", hargafinal);
    } else {
        printf("Input tidak valid. Umur harus berada dalam rentang 0 hingga 120.\n");
    }

    return 0;
}