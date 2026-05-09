/*Pide una contraseña y sigue preguntando hasta que el usuario escriba "1234".*/

#include <stdio.h>
#include <string.h>

int main() {
    char password[20]; // variable para almacenar la contraseña ingresada

    while (1) { // bucle infinito
        printf("ingrese la password: ");
        scanf("%s", password); // lee la contraseña ingresada por el usuario

        if (strcmp(password, "1234") == 0) { // Compara la contraseña con "1234"
            printf("password correcta. Bienvenido\n");
            break; // sale del bucle si la contraseña es correcta
        } else {
            printf("password incorrecta, intente de nuevo.\n");
        }
    }

    return 0;
}