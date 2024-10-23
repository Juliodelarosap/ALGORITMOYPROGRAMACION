/* programa que permita realizar la operación matemática deseada (calculadora básica), considerando las 
divisiones entre cero (0), y no negativos en las restas. */
#include <stdio.h>

int main(){
    int num1, num2, resultado; /**< Variables para almacenar los números y el resultado de la operación. */
    char operador; /**< Variable para almacenar el operador aritmético. */

    printf("Calculadora basica\n");
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1); /**< Solicita el primer número al usuario. */

    printf("Ingrese el segundo numero: \n");
    scanf("%d", &num2); /**< Solicita el segundo número al usuario. */

    printf("Ingrese el operador: \n");
    scanf(" %c", &operador); /**< Solicita el operador aritmético al usuario. */

    switch (operador)
    {
        case '+' :
            resultado = num1 + num2; /**< Realiza la suma de los dos números. */
            printf("El resultado de la suma es: %d\n", resultado);
            break;

        case '-' :
            if (num1 >= num2)
            {
                resultado = num1 - num2; /**< Realiza la resta de los dos números si el primero es mayor o igual al segundo. */
                printf("El resultado de la resta es: %d\n", resultado);
            }
            else
            {
                printf("El resultado de la resta no es valido.\n"); /**< Muestra un mensaje de error si la resta no es válida. */
            }
            break;
        
        case '*' :
            resultado = num1 * num2; /**< Realiza la multiplicación de los dos números. */
            printf("El resultado de la multiplicacion es: %d\n", resultado);
            break;
        
        case '/' :
            if (num2 != 0)
            {
                resultado = num1 / num2; /**< Realiza la división de los dos números si el segundo no es cero. */
                printf("El resultado de la division es: %d\n", resultado);
            }
            else
            {
                printf("El resultado de la division no es valido.\n"); /**< Muestra un mensaje de error si la división no es válida. */
            }
            break; 

        default:
            printf("Operador no valido.\n"); /**< Muestra un mensaje de error si el operador no es válido. */
            break;
    }

    return 0;
}
