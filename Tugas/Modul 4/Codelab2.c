#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, char_unik;

    printf("Masukkan sebuah string: ");
    scanf("%s", str);

    for (i = 0; str[i]; i++) {
        char_unik = 1;

        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                char_unik = 0;
                break;
            }
        }

        if (!char_unik) continue;

        printf("%c", str[i]);
    }


    return 0;
}
