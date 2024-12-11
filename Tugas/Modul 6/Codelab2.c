#include <stdio.h>
#include <string.h>

int main() {
    FILE *fptr;
    int pilihan;
    char nama[100];
    long long int nim;
    char ps[100];
    char addData[1000];

    // Loop utama untuk menampilkan menu berulang kali
    while (1) {
        // Menampilkan menu pilihan
        printf("\nPilih Aksi: \n");
        printf("1. Tulis data mahasiswa\n");
        printf("2. Baca data mahasiswa\n");
        printf("3. Keluar\n");

        // Meminta masukan dari pengguna
        printf("Masukkan Pilihan: ");
        scanf("%d", &pilihan);
        getchar();
        printf("\n");

        // Proses berdasarkan pilihan pengguna
        switch (pilihan) {
            case 1:
                // Membuka file untuk menulis data mahasiswa
                fptr = fopen("database1.txt", "a");
                if (fptr == NULL) {
                    printf("File gagal dibuka, data tidak dapat ditambahkan.\n");
                    break;
                }

                // Meminta data dari pengguna
                printf("Masukkan Nama: ");
                fgets(nama, sizeof(nama), stdin);

                printf("Masukkan NIM: ");
                scanf("%lld", &nim);
                getchar();

                printf("Masukkan Program Studi: ");
                fgets(ps, sizeof(ps), stdin);

                // Memeriksa apakah data valid sebelum menulis ke file
                if (strlen(nama) > 1 && strlen(ps) > 1) {
                    fprintf(fptr, "Nama: %s", nama);
                    fprintf(fptr, "NIM: %lld\n", nim);
                    fprintf(fptr, "Program Studi: %s\n", ps);
                    printf("Data Mahasiswa Berhasil Ditulis ke File.\n");
                } else {
                    printf("Kesalahan: Data tidak valid.\n");
                }

                fclose(fptr);  // Menutup file setelah selesai
                break;

            case 2:
                // Membuka file untuk membaca data mahasiswa
                fptr = fopen("database1.txt", "r");
                if (fptr == NULL) {
                    printf("Error: File tidak ditemukan.\n");
                    break;
                }
                // Membaca dan menampilkan data dari file
                printf("Data Mahasiswa:\n");
                while (fgets(addData, sizeof(addData), fptr)) {
                    printf("%s", addData);
                }
                fclose(fptr);  // Menutup file setelah selesai
                break;

            case 3:
                // Keluar dari program
                printf("Terima Kasih Telah Menggunakan Sistem Kami!!\n");
                return 0;

            default:
                // Menampilkan pesan jika pilihan tidak valid
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    }
    return 0; 
}
