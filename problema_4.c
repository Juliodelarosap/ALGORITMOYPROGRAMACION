/*Programa que permita determinar cuantas aulas se necesitan para determinado 
numero de estudiantes, en una escuela rural, si el maximo de estudiantes por aula es 25*/

#include <stdio.h>

int main(){

    int estudiantes, aulas;

    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &estudiantes);

    aulas = estudiantes / 25;

    if(estudiantes % 25 != 0){
        aulas++;
    }
    
    printf("Se necesitan %d aulas\n", aulas);
    
    

    return 0;
}