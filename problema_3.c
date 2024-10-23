/* programa que permita realizar la operación matemática deseada (calculadora básica), considerando las 
divisiones entre cero (0), y no negativos en las restas.*/
#include <stdio.h>

int main(){

    int num1, num2, resultado;
    char operador;

    printf("Calculadora basica\n");
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: \n");
    scanf("%d", &num2);

    printf("Ingrese el operador: \n");
    scanf(" %c", &operador); 

    switch (operador)
    {
        case '+' :
            resultado = num1 + num2;
            printf("El resultado de la suma es: %d\n", resultado);
            break;

        case '-' :
            if (num1 >= num2)
            {
                resultado = num1 - num2;
                printf("El resultado de la resta es: %d\n", resultado);
            }
            else
            {
                printf("El resultado de la resta no es valido.\n");
            }
            break;
        
        case '*' :
            resultado = num1 * num2;
            printf("El resultado de la multiplicacion es: %d\n", resultado);
            break;
        
        case '/' :
            if (num2 != 0)
            {
                resultado = num1 / num2;
                printf("El resultado de la division es: %d\n", resultado);
            }
            else
            {
                printf("El resultado de la division no es valido.\n");
            }
            break; 

        default:
            printf("Operador no valido.\n");
            break;
    }

    return 0;
}
