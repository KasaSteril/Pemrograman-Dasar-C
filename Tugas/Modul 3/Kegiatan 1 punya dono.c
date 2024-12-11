#include <stdio.h>

// enum film
enum Film {
    SPIDERMAN = 50000,
    BATMAN = 55000,
    SUPERMAN = 60000,
    AVENGERS = 70000,
    JOKER = 45000
};

// enum tiket
enum JenisTiket {
    REGULER = 30000,
    VIP = 100000,
    VVIP = 150000
};

// function untuk menampilkan pilihan film
void tampilkanPilihanFilm() {
    printf("===== Bioskop =====\n");
    printf("Film:\n");
    printf("1. Spiderman - Rp.50000\n");
    printf("2. Batman - Rp.55000\n");
    printf("3. Superman - Rp.60000\n");
    printf("4. Avengers - Rp.70000\n");
    printf("5. Joker - Rp.45000\n");
}

// function untuk menampilkan pilihan tiket
void tampilkanPilihanTiket() {
    printf("\nJenis Tiket:\n");
    printf("1. Reguler - Rp.30000\n");
    printf("2. VIP - Rp.100000\n");
    printf("3. VVIP - Rp.150000\n");
}

int main() {
    int pilihanFilm, pilihanTiket, isMember;
    int hargaFilm = 0, hargaTiket = 0;
    double totalHarga;
    int uangDibayarkan;
    
    tampilkanPilihanFilm();
    printf("Pilih film (1-5): ");
    scanf("%d", &pilihanFilm);
    
    // harga tiket film
    switch (pilihanFilm) {
        case 1: hargaFilm = SPIDERMAN; break;
        case 2: hargaFilm = BATMAN; break;
        case 3: hargaFilm = SUPERMAN; break;
        case 4: hargaFilm = AVENGERS; break;
        case 5: hargaFilm = JOKER; break;
        default: printf("Pilihan film tidak valid.\n"); return 1;
    }
    
    printf("\n");
    printf("===================\n");
    
    tampilkanPilihanTiket();
    printf("Pilih jenis tiket (1-3): ");
    scanf("%d", &pilihanTiket);
    
    // list harga tiket berdasarkan member
    switch (pilihanTiket) {
        case 1: hargaTiket = REGULER; break;
        case 2: hargaTiket = VIP; break;
        case 3: hargaTiket = VVIP; break;
        default: printf("Pilihan tiket tidak valid.\n"); return 1;
    }
    
    // input tanya apakah pelanggan member atau tidaknya
    printf("Apakah Anda adalah member? (Y/N): ");
    char memberInput;
    scanf(" %c", &memberInput);
    isMember = (memberInput == 'y' || memberInput == 'Y') ? 1 : 0;
    
    printf("\n");
    printf("===================\n");
    
    // kalkulasi total harga
    totalHarga = hargaFilm + hargaTiket;
    if (isMember == 1) {
        totalHarga *= 0.9; // diskon 10% untuk member
    }
    
    printf("\n");
    
    printf("\Total harga: Rp. %.2f\n", totalHarga);
    printf("Alamat memori variabel total: %p\n", (void*)&totalHarga);
    
    // input uang payment 
    printf("Masukkan uang pembayaran: ");
    scanf("%d", &uangDibayarkan);
    
    // cek payment
    if (uangDibayarkan > totalHarga) {
        printf("Kembalian Anda: Rp. %.2f\n", uangDibayarkan - totalHarga);
    } else if (uangDibayarkan < totalHarga) {
        printf("Uang Anda kurang.\n");
    } else {
        printf("Terima kasih!\n");
    }

    printf("\n=== Code Execution Successful ===\n");
    printf("\n");
    printf("BANGGGG UDAHHH BANGGGG GUAAA UDAHHH MUAAAKKKKKK\n");
    
    return 0;
}