#include <stdio.h>

int main() {
    int jumlah_mahasiswa;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlah_mahasiswa);

    float nilai[jumlah_mahasiswa][3]; // 3 kolom untuk Matematika, Fisika, Kimia
    float rata_rata_mat = 0, rata_rata_fis = 0, rata_rata_kim = 0;

    // Input nilai
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        printf("Masukkan nilai untuk mahasiswa ke-%d (Matematika, Fisika, Kimia): ", i + 1);
        scanf("%f %f %f", &nilai[i][0], &nilai[i][1], &nilai[i][2]);

        // Hitung total sementara
        rata_rata_mat += nilai[i][0];
        rata_rata_fis += nilai[i][1];
        rata_rata_kim += nilai[i][2];
    }

    // Hitung rata-rata
    rata_rata_mat /= jumlah_mahasiswa;
    rata_rata_fis /= jumlah_mahasiswa;
    rata_rata_kim /= jumlah_mahasiswa;

    float rata_rata_keseluruhan = (rata_rata_mat + rata_rata_fis + rata_rata_kim) / 3;

    // Tampilkan data
    printf("\nData Nilai Ujian:\n");
    printf("Mahasiswa\tMatematika\tFisika\t\tKimia\n");
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        printf("Mhs %d\t\t%.2f\t\t%.2f\t\t%.2f\n", i + 1, nilai[i][0], nilai[i][1], nilai[i][2]);
    }

    // Tampilkan rata-rata
    printf("\nRata-rata Nilai:\n");
    printf("Matematika: %.2f\n", rata_rata_mat);
    printf("Fisika: %.2f\n", rata_rata_fis);
    printf("Kimia: %.2f\n", rata_rata_kim);
    printf("Rata-rata Keseluruhan: %.2f\n", rata_rata_keseluruhan);

    return 0;
}