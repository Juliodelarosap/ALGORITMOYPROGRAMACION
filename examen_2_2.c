/*Elabore un programa en C, que solicite un valor en pantalla, y usando una función, calcule la potencia de ese número,
 retorne el resultado al programa principal y lo despliegue en pantalla.*/

#include <stdio.h>
#include <math.h>

int potencia(int base, int exponente){
    return pow(base, exponente);
}

int main(){
    int base, exponente;
    printf("Ingrese un numero: ");
    scanf("%d", &base);

    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);

    printf("El resultado de la potencia es: %d\n", potencia(base, exponente));

return 0;
}




