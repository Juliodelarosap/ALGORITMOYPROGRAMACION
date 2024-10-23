#include <stdio.h>

// Prototipo de la función que calcula el cubo de un número
int cubo(void);

// Variable global utilizada en la función cubo()
int i;

int main(void) {
    int CUB;  // Variable para almacenar el resultado del cubo

    // Bucle para calcular e imprimir el cubo de los números del 1 al 10
    for(i = 1; i <= 10; i++) {
        CUB = cubo();
        printf("El cubo de %d es %d\n", i, CUB);
    }
}

/**
 * @brief Calcula el cubo de la variable global i.
 * 
 * @return El cubo de i.
 */
int cubo(void) {
    return i * i * i;
}

