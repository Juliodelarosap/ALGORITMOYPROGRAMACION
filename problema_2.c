/*programa que permita sumar 3 números enteros, y desplegar en pantalla los 3 números, el valor de su suma e indicar si el 
resultado es par o impar. */
#include <stdio.h>

int main() {
    int num1, num2, num3, sum;

    // Solicitar los tres números al usuario
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);

    // Calcular la suma de los tres números
    sum = num1 + num2 + num3;

    // Desplegar los números y el valor de su suma
    printf("Los numeros ingresados son: %d, %d, %d\n", num1, num2, num3);
    printf("La suma de los numeros es: %d\n", sum);

    // Indicar si el resultado es par o impar
    if (sum % 2 == 0) {
        printf("El resultado es par.\n");
    } else {
        printf("El resultado es impar.\n");
    }

    return 0;
}