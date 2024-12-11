#include <stdio.h>
#include <string.h>

int main(){
    FILE *file;
    char data[100];

    file = fopen("contoh.txt", "w");
    printf("Data yang ingin ditulis: ");
    fgets(data, sizeof(data), stdin);
    fprintf(file, "%s", data);

    fclose(file);

    file = fopen("contoh.txt", "r");

    printf("isi file:\n");
    while(fgets(data, sizeof(data), file) != NULL){
        printf("%s", data);
    }

    fclose(file);

    return 0;
}