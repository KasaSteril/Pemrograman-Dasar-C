#include <stdio.h>

// Mendefinisikan enum untuk Film dan Jenis Tiket
enum Film {
    Spiderman = 50000,
    Batman = 55000,
    Superman = 60000,
    Avengers = 70000,
    Joker = 45000
};

enum JenisTiket {
    Reguler = 30000,
    VIP = 100000,
    VVIP = 150000
};

int main() {
    int pilihanFilm, pilihanTiket;
    char member;
    double totalHarga, uangDibayar, kembalian;
    double *alamatMemori;

    // Menampilkan dashboard bioskop
    printf("===== Bioskop =====\n");
    printf("Film:\n");
    printf("1. Spiderman - Rp.50000\n");
    printf("2. Batman - Rp.55000\n");
    printf("3. Superman - Rp.60000\n");
    printf("4. Avengers - Rp.70000\n");
    printf("5. Joker - Rp.45000\n");
    printf("Pilih film (1-5): ");
    scanf("%d", &pilihanFilm);

    // Menghitung harga berdasarkan pilihan film
    if (pilihanFilm == 1) {
        totalHarga = Spiderman;
    } else if (pilihanFilm == 2) {
        totalHarga = Batman;
    } else if (pilihanFilm == 3) {
        totalHarga = Superman;
    } else if (pilihanFilm == 4) {
        totalHarga = Avengers;
    } else if (pilihanFilm == 5) {
        totalHarga = Joker;
    } else {
        printf("Pilihan film tidak valid.\n");
        return 1;
    }

    // Menampilkan jenis tiket
    printf("\nJenis Tiket:\n");
    printf("1. Reguler - Rp.30000\n");
    printf("2. VIP - Rp.100000\n");
    printf("3. VVIP - Rp.150000\n");
    printf("Pilih jenis tiket (1-3): ");
    scanf("%d", &pilihanTiket);

    // Menghitung harga berdasarkan pilihan tiket
    if (pilihanTiket == 1) {
        totalHarga += Reguler;
    } else if (pilihanTiket == 2) {
        totalHarga += VIP;
    } else if (pilihanTiket == 3) {
        totalHarga += VVIP;
    } else {
        printf("Pilihan tiket tidak valid.\n");
        return 1;
    }

    // Menanyakan apakah pelanggan adalah member
    printf("\nApakah Anda adalah member? (Y/N): ");
    scanf(" %c", &member);

    // Jika member, berikan diskon 10%
    if (member == 'Y' || member == 'y') {
        totalHarga *= 0.9;
    }

    // Menampilkan total harga dan alamat memori
    alamatMemori = &totalHarga;
    printf("\nTotal harga: Rp. %.2f\n", totalHarga);
    printf("Alamat memori variabel total: %p\n", (void*)alamatMemori);

    // Meminta input pembayaran
    printf("Masukkan uang pembayaran: ");
    scanf("%lf", &uangDibayar);

    // Menghitung kembalian atau memeriksa apakah uang kurang
    if (uangDibayar > totalHarga) {
        kembalian = uangDibayar - totalHarga;
        printf("Kembalian Anda: Rp. %.2f\n", kembalian);
    } else if (uangDibayar < totalHarga) {
        printf("Uang yang Anda masukkan kurang.\n");
    } else {
        printf("Terima kasih telah membayar dengan tepat.\n");
    }

    return 0;
}
