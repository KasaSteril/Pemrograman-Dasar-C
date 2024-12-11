#include <stdio.h>
#include <string.h>

int main() {
    char nama[5][10] = {"Alice", "Bob", "Charlie", "David", "Eva"};
    int nilai[5] = {85, 90, 78, 92, 88};
    int i;

    printf("Daftar siswa dan nilai sebelum diubah:\n");
    for (i = 0; i < 5; i++) {
        printf("%s: %d\n", nama[i], nilai[i]);
    }

    // Mengubah nilai David
    for (i = 0; i < 5; i++) {
        if (strcmp(nama[i], "David") == 0) {
            nilai[i] = 95;
            break; // Keluar dari loop setelah perubahan
        }
    }

    printf("\nDaftar siswa dan nilai setelah diubah:\n");
    for (i = 0; i < 5; i++) {
        printf("%s: %d\n", nama[i], nilai[i]);
    }

    return 0;
}
