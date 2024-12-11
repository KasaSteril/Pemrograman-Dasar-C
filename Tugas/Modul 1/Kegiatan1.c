#include <stdio.h>

int main() {
    
    char nama[50];
    long long int nim;
    int nilai_tugas, nilai_uts, nilai_uas;
    float nilai_akhir;

    printf("--- Program penghitung nilai akhir mahasiswa --- \n");
    printf(" Masukkan nama mahasiswa \t: ");
    gets(nama);
    
    printf(" Masukkan nim mahasiswa \t: ");
    scanf("%lld", &nim);
    
    printf(" Masukkan nilai tugas (0-100) \t: ");
    scanf("%s", &nilai_tugas);
    
    printf(" Masukkan nilai uts (0-100) \t: ");
    scanf("%d", &nilai_uts);
    
    printf(" Masukkan nilai uas (0-100) \t: ");
    scanf("%d", &nilai_uas);
    
    printf(" ------------------------------------------- \n");
    
    printf(" Nama mahasiswa\t: %s\n", nama);
    printf(" Nim mahasiswa \t: %lld\n", nim);
    printf(" Nilai tugas \t: %d\n", nilai_tugas);
    printf(" Nilai uts \t: %d\n", nilai_uts);
    printf(" Nilai uas \t: %d\n", nilai_uas);
    
    nilai_akhir = (nilai_tugas * 0.20)+(nilai_uts * 0.35)+(nilai_uas * 0.45);
    printf(" Nilai akhir \t: %.2f\n", nilai_akhir);
    
    printf(" ------------------------------------------- \n");

    return 0;
}
