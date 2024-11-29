#include<stdio.h>

int promedio;

int main(){

    int calificacion1, calificacion2, calificacion3;
    int promedio;
    printf("ingrese la calificacion de 0 - 10\n");

    printf("Ingrese la calificacion 1: ");
    scanf("%d", &calificacion1);

    printf("Ingrese la calificacion 2: ");
    scanf("%d", &calificacion2);

    printf("Ingrese la calificacion 3: ");
    scanf("%d", &calificacion3);

    promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

    if (promedio >= 6){
        printf("Aprobado\n");
    } 
        else {
            printf("Reprobado\n");
    }

    printf("el promedio es: %d\n", promedio);

    return 0;
}