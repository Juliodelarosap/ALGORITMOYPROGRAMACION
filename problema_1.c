/*programa que permita desplegar en pantalla un mensaje de bienvenida de acuerdo con su género, señor o señora 
respectivamente.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char genero[10];  // Variable para almacenar el género ingresado

    // Solicita al usuario que ingrese su género
    printf("Ingrese su genero: Femenino O Masculino\n");
    scanf("%s", genero);

    // Convierte todos los caracteres del género a minúsculas
    for (int i = 0; genero[i]; i++) {
        genero[i] = tolower(genero[i]);
    }

    // Compara el género ingresado y despliega el mensaje correspondiente
    if (strcmp(genero, "masculino") == 0) {
        printf("Bienvenido caballero.\n");
    } else if (strcmp(genero, "femenino") == 0) {
        printf("Bienvenida dama.\n");
    } else {
        // Mensaje en caso de que el género no sea reconocido
        printf("Genero no reconocido.\n");
    }

    return 0;  // Finaliza el programa
}
