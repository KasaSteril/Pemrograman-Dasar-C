#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int pilihan;
    int harga_produk;
    int stok_produk;
    char nama_produk[50];
    char kategori_produk[50];
    char addData[1000];
    char buff[255];
    long long int id;
    long long int  deleteId;
    char idStr[20];
    char line[255];
    int found = 0;
    char data[1000][255]; // Buffer untuk menyimpan semua baris file
    int lineCount = 0;
    FILE *fptr, *tempFile;

    printf("\n=== Selamat Datang Di Program Manajemen Toko Elektronik ===\n");
    printf("\nMenu:\n");
    printf("1. Tambah Produk Baru \n"); 
    printf("2. Tampilkan Daftar Produk \n"); 
    printf("3. Update Informasi Produk \n"); 
    printf("4. Hapus Produk  \n"); 
    printf("5. Keluar \n");
    printf("Masukan pilihan: ");scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        fptr = fopen("produk_toko.txt", "a");
        printf("Masukan ID produk: ");scanf("%lld", &id);
        // if (fptr == id) {
        //     printf("Id sudah tersedia!\n");
        //     main();
        //     break;
        // }
        printf("Masukan nama produk:");scanf("%s", &nama_produk);
        printf("Masukan kategori produk:");scanf("%s", &kategori_produk);
        printf("Masukan harga produk:");scanf("%d", &harga_produk);
        printf("Masukan stok produk: ");scanf("%d", &stok_produk);
        if(fptr != NULL){
            fprintf(fptr, "ID produk: %lld\n", id);
            fprintf(fptr, "Nama produk: %s\n", nama_produk);
            fprintf(fptr, "Kategori produk: %s\n", kategori_produk);
            fprintf(fptr, "Harga produk: %d\n", harga_produk);
            fprintf(fptr, "Stok produk: %d\n", stok_produk);
            printf("Produk berhasil ditambahkan!");
        fclose(fptr);
        printf("\n\n");
        main();

        }else{
            printf("File gagal di bukan dan data tidak dapat ditambahkan");
        }
        break;
    case 2:
        fptr = fopen("produk_toko.txt", "r");
        printf("\nDaftar Produk: \n");
        if(fptr != NULL){
            while (fgets(addData, sizeof(addData), fptr)){
                printf("%s", addData);
            }
            fclose(fptr);
            main();
        }else{
            printf("Eror");
        }
        break;
    case 3:
        fptr = fopen("produk_toko.txt", "r");
        if (fptr == NULL) {
            printf("Error: File tidak ada!\n");
            break;
        }

        char buffer[1000][255];
        int lineCount = 0;
        long long updateId;
        int found = 0;

        // Masukkan isi file ke buffer
        while (fgets(buffer[lineCount], sizeof(buffer[lineCount]), fptr)) {
            lineCount++;
        }
        fclose(fptr);

        printf("Masukkan ID produk yang ingin diupdate: ");
        scanf("%lld", &updateId);

        // Konversi ID produk ke string untuk pencocokan
        char idStr[20];
        sprintf(idStr, "%lld", updateId);

        for (int i = 0; i < lineCount; i++) {
            if (strstr(buffer[i], "ID produk:") && strstr(buffer[i], idStr)) {
                found = 1;

                // Input data baru
                printf("Masukan nama produk baru: "); scanf("%s", nama_produk);
                printf("Masukan kategori produk baru: "); scanf("%s", kategori_produk);
                printf("Masukan harga produk baru: "); scanf("%d", &harga_produk);
                printf("Masukan stok produk baru: "); scanf("%d", &stok_produk);

                // Perbarui data di buffer
                snprintf(buffer[i + 1], sizeof(buffer[i + 1]), "Nama produk: %s\n", nama_produk);
                snprintf(buffer[i + 2], sizeof(buffer[i + 2]), "Kategori produk: %s\n", kategori_produk);
                snprintf(buffer[i + 3], sizeof(buffer[i + 3]), "Harga produk: %d\n", harga_produk);
                snprintf(buffer[i + 4], sizeof(buffer[i + 4]), "Stok produk: %d\n", stok_produk);
                break;
            }
        }

        if (!found) {
            printf("Produk dengan ID %lld tidak ditemukan!\n", updateId);
            main();
        } else {
            // Tulis ulang file dengan data yang diperbarui
            fptr = fopen("produk_toko.txt", "w");
            for (int i = 0; i < lineCount; i++) {
                fprintf(fptr, "%s", buffer[i]);
            }
            fclose(fptr);
            printf("Produk berhasil diperbarui!\n");
            main();
        }
    break;

    case 4:
    printf("Masukkan ID yang ingin dihapus: ");
    scanf("%lld", &deleteId);

    // Konversi ID ke string
    sprintf(idStr, "ID produk: %lld\n", deleteId);

    // Buka file untuk membaca
    fptr = fopen("produk_toko.txt", "r");
    if (fptr == NULL) {
        printf("Error: File tidak dapat dibuka!\n");
        return 1;
    }

    // Buat file sementara untuk menulis data yang tidak dihapus
    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error: File sementara tidak dapat dibuka!\n");
        fclose(fptr);
        return 1;
    }

    found = 0;
    while (fgets(line, sizeof(line), fptr)) {
        if (strstr(line, idStr)) {
            // Tandai ID ditemukan dan lewati data produk (5 baris)
            found = 1;
            for (int i = 0; i < 4; i++) {
                fgets(line, sizeof(line), fptr);
            }
        } else {
            // Salin baris ke file sementara
            fputs(line, tempFile);
        }
    }
    fclose(fptr);
    fclose(tempFile);

    if (!found) {
        printf("ID %lld tidak ditemukan dalam file!\n", deleteId);
        remove("temp.txt"); // Hapus file sementara jika tidak ada perubahan
        break;
    }

    // Hapus file lama dan ganti dengan file sementara
    remove("produk_toko.txt");
    rename("temp.txt", "produk_toko.txt");

    printf("Produk dengan ID %lld berhasil dihapus!\n", deleteId);
    main();
    break;

 
    case 5:
        return 0;
        break;

    default:
        printf("Input Invalid!");
        break;
    }

    return 0;
}