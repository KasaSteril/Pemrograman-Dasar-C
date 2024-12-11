#include <stdio.h>

int main() {
    int transaksi, lanjut, total = 0;

    do {
        printf("=== Pencatatan Transaksi ===\n");
        printf("Masukkan transaksi selanjutnya (gunakan 0 untuk menyelesaikan): \n");
        
        for (;;) {
            scanf("%d", &transaksi);

            if (transaksi == 0) {
                break;
            }
            total += transaksi;
        }
        
        printf("\nTotal dari transaksi tersebut adalah: %d\n", total);
        printf("\nApakah Anda ingin mencatat transaksi lagi? (1=Ya, 0=Tidak): ");
        scanf("%d", &lanjut);
        printf("\n");
    } while (lanjut == 1);

    printf("Terima kasih!\n");

    return 0;
}
