/*3. La universidad del Sur de Italia necesita un programa en C, que les permita establecer la admisión de un estudiante dependiendo 
del promedio de calificaciones de sus estudios de pre-grado, que debe ser mayor de 85 puntos. 
Dependiendo de este promedio se genera la decisión correspondiente: 85% admitido, 84-80% curso propedeútico, 79% o menos no es admitido.
De igual forma debe considerar que las  calificaciones de las materias utilizadas para generar el promedio sean mayores a 70 puntos, 
si alguna de las materias tiene menos de 70 puntos automáticamente no es admitido.

Materias a considerar:

Matemáticas
Ingles
Quimica
Biología
Historia
Física
Lengua española

El programa al final debe desplegar las notas ingresadas por materia, el promedio de calificaciones,
y la decisión sobre la condición del estudiante: admitido, curso propedéutico, no admitido.*/

#include <stdio.h>
#include <windows.h>

int main (){

    float matematicas, ingles, quimica, biologia, historia, fisica, lengua, promedio;
    int decision = 1;

    printf("Inroduce calificacion de matematicas:");
    scanf("%f", &matematicas);

    printf("Inroduce calificacion de ingles:");
    scanf("%f", &ingles);

    printf("Inroduce calificacion de quimica:");
    scanf("%f", &quimica);

    printf("Inroduce calificacion de biologia:");
    scanf("%f", &biologia);

    printf("Inroduce calificacion de historia:");
    scanf("%f", &historia);

    printf("Inroduce calificacion de fisica:");
    scanf("%f", &fisica);

    printf("Inroduce calificacion de lengua:");
    scanf("%f", &lengua);

system("cls");

    if (matematicas < 70 || ingles < 70 || quimica < 70 || biologia < 70 || historia < 70 || fisica < 70 || lengua < 70){
        decision = 0;
    
        printf("Ha reprobado una materia\n");
    }

    printf("Matematicas: %.2f\n", matematicas);
    printf("Ingles: %.2f\n", ingles);
    printf("Quimica: %.2f\n", quimica);
    printf("Biologia: %.2f\n", biologia);
    printf("Historia: %.2f\n", historia);
    printf("Fisica: %.2f\n", fisica);
    printf("Lengua: %.2f\n", lengua);


    promedio = (matematicas + ingles + quimica + biologia + historia + fisica + lengua) / 7;
    printf("Promedio: %.2f\n", promedio);


    if (!decision ){
        printf("no admitido\n");    
    } 
    else if (promedio >= 85){
        printf("admitido\n");
    }
    else if (promedio >= 80){
        printf("curso propedeutico\n");
    }
    else {
        printf("no admitido\n");
    }


    return 0;
}