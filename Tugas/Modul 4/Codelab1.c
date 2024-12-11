#include <stdio.h>

int main() {
    int bilangan, total = 0, count = 0;
    float rata_rata;
#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  char uniqueChars[100];
  int i, j, k;

  printf("Masukkan sebuah string: ");
  scanf("%s", str);  // Menggunakan scanf untuk input string dengan batasan 99 karakter

  for (i = 0; i < strlen(str); i++) {
    // Cek apakah karakter sudah ada di uniqueChars
    for (j = 0; j < k; j++) {
      if (str[i] == uniqueChars[j]) {
        break; // karakter sudah ada, lanjut ke iterasi berikutnya
      }
    }

    // Jika karakter belum ada di uniqueChars
    if (j == k) {
      uniqueChars[k] = str[i];
      k++; // tambah jumlah karakter unik
    }
  }

  printf("Karakter unik: ");
  for (i = 0; i < k; i++) {
    printf("%c", uniqueChars[i]);
  }
  printf("\n");

  return 0;
}

    printf("Masukkan bilangan bulat (masukkan angka negatif untuk berhenti): ");
    scanf("%d", &bilangan);

    while (bilangan >= 0) {
        total += bilangan;
        count++;
        printf("Masukkan bilangan bulat (masukkan angka negatif untuk berhenti): ");
        scanf("%d", &bilangan);
    }

    if (count > 0) {
        rata_rata = (float)total / count;
        printf("\nTotal bilangan: %d\n", total);
        printf("Rata-rata bilangan: %.2f\n", rata_rata);
    } else {
        printf("\nTidak ada bilangan yang dimasukkan.\n");
    }

    return 0;
}
