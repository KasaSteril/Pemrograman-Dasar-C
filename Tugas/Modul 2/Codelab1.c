#include <stdio.h>

int main() {
  // 1. Pengenalan Program
  printf("===== Program Penghitung Kalori Harian =====\n");
  printf("Program ini akan menghitung total kalori harian yang dikonsumsi.\n");

  // 2. Mengambil input kalori per makanan
  int kalori1, kalori2, kalori3;
  printf("Masukkan kalori makanan pertama: ");
  scanf("%d", &kalori1);
  printf("Masukkan kalori makanan kedua: ");
  scanf("%d", &kalori2);
  printf("Masukkan kalori makanan ketiga: ");
  scanf("%d", &kalori3);

  // 3. Menghitung total kalori
  int total_kalori = kalori1 + kalori2 + kalori3;

  // 4. Memeriksa batas kalori harian
  const int BATAS_KALORI = 2000; // Contoh batas kalori harian
  int melebihi_batas = total_kalori > BATAS_KALORI; 

  // 5. Menampilkan hasil
  printf("\nTotal kalori: %d\n", total_kalori);

  if (melebihi_batas) {
    printf("Total kalori melebihi batas harian.\n");
  } else {
    printf("Total kalori tidak melebihi batas harian.\n");
  }

  printf("=== Code Execution Successful ===\n");
  return 0;
}