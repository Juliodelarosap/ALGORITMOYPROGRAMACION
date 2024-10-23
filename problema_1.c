/*programa que permita desplegar en pantalla un mensaje de bienvenida de acuerdo con su género, señor o señora 
respectivamente.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char genero[10];

    printf("Ingrese su genero: Femenino O Masculino\n");
    scanf("%s", genero);

    for (int i = 0; genero[i]; i++) {
        genero[i] = tolower(genero[i]);
    }

    if (strcmp(genero, "masculino") == 0) {
        printf("Bienvenido caballero.\n");
    } else if (strcmp(genero, "femenino") == 0) {
        printf("Bienvenida dama.\n");
    } else {
        printf("Genero no reconocido.\n");
    }

    return 0;
}
