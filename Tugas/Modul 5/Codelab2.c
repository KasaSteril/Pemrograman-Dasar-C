#include <stdio.h>

int main() {
    char toko_produk[3][10] = {"ProdukA", "ProdukB", "ProdukC"};
    int toko_nilai1[3] = {5, 8, 6};
    int toko_nilai2[3] = {3, 7, 9};
    int total, i;

    printf("Total penjualan untuk setiap produk:\n");
    for (i = 0; i < 3; i++) {
        total = toko_nilai1[i] + toko_nilai2[i];
        printf("%s: %d\n", toko_produk[i], total);
    }

    return 0;
}
