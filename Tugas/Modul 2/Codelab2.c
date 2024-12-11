#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    // Boolean values
    bool flagTrue = true;    // boolean salah, diganti bool
    bool flagFalse = false;

    printf("Boolean values demonstration:\n");
    printf("flagTrue: %d\n", flagTrue);    // kurang flagtrue
    printf("flagFalse: %d\n", flagFalse);  // kurang flagfalse

    // String operations
    char greeting[] = "Hello, World!";
    char copyGreeting[20];
    strcpy(copyGreeting, greeting);  // stringcopy salah, ganti strcpy

    printf("\nString operations:\n");
    printf("Original greeting: %s\n", greeting);      // string1 salah ganti greeting
    printf("Copied greeting: %s\n", copyGreeting);    // string2 salah ganti copyGreeting

    // Pointer demonstrations
    int number = 100;
    int *pointer = &number;

    printf("\nPointer demonstrations:\n");
    printf("Value of number: %d\n", number);
    printf("Address of number: %p\n", &number);
    printf("Value of pointer: %p\n", pointer); 
    printf("Value pointed by pointer: %d\n", *pointer);

    return 0;
}
