#include <stdio.h>
#include <unistd.h> // Para usar la función sleep

int main() {
    int pisoActual = 1; // El ascensor comienza en el piso 1
    int pisoDestino;

    printf("Ascensor con 3 pisos\n");
    printf("Piso actual: %d\n", pisoActual);

    while (1) {
        printf("\nIngrese el piso al que desea ir (1-3, 0 para salir): ");
        scanf("%d", &pisoDestino);

        if (pisoDestino == 0) {
            printf("Saliendo del programa....\n");
            break;
        }

        if (pisoDestino < 1 || pisoDestino > 3) {
            printf("Piso invalido. Por favor, ingrese un piso entre 1 y 3.\n");
            continue;
        }

        printf("Cerrando puertas...\n");
        sleep(1); // Espera 1 segundo

        if (pisoDestino == pisoActual) {
            printf("Ya esta en el piso %d. No es necesario moverse.\n", pisoActual);
        } else if (pisoDestino > pisoActual) {
            for (int i = pisoActual + 1; i <= pisoDestino; i++) {
                printf("Subiendo... Piso %d\n", i);
                sleep(1); // Espera 1 segundo entre pisos
            }
            pisoActual = pisoDestino;
        } else {
            for (int i = pisoActual - 1; i >= pisoDestino; i--) {
                printf("Bajando... Piso %d\n", i);
                sleep(1); // Espera 1 segundo entre pisos
            }
            pisoActual = pisoDestino;
        }

        printf("Abriendo puertas...\n");
        sleep(1); // Espera 1 segundo
        printf("Ahora esta en el piso %d.\n", pisoActual);
    }

    return 0;
}