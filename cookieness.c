#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * fileName = "flag.txt";
char * signature = "Merk was here.";

// Unused function to print the first 100
// chars of a file passed as an argument
void print_file(char * name) {
    char flag[100];
    
    FILE * fp;
    fp = fopen(name, "r");
    
    // If the file can be opened and read, print its contents
    if (fgets(flag, 100, fp) != NULL)
        printf("Mostrando contenido de %s: %s", name, flag);
    else
        printf("Fichero %s no encontrado.", name);
}

void welcome() {
    // Ask user for input
    printf("%s", "Login: ");

    // Get user input
    char strUser[20];
    fgets(strUser, 20, stdin);

    // Print welcome message, followed by a printf
    // with a format string vulnerability
    printf("%s", "Bienvenido, ");
    printf(strUser);

    // Get user input via vulnerable gets function
    puts("\nPuedes leer flag.txt?");
    gets(strUser);
}

int main(int argc, char * argv[]) { 
    // Vulnerable function
    welcome();
    return 0;
}
