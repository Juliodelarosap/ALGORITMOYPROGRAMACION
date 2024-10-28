/*1. Una empresa de taxis quiere regularizar el costo de los servicios de transporte, por tanto necesita un programa en C, 
que solicite la distancia en kilómetros del recorrido del servicio, y genere un calculo del precio considerando cuatro (4) regiones:

Regiones:

Norte $9 pesos por kilometro
Sur $8 pesos por kilometro
Este $11 pesos por kilometro
Oeste $7 pesos por kilometro

Al final debe desplegar el costo del servicio basado en el precio por kilometro dependiendo de la región y la cantidad de kilómetros. */

#include <stdio.h>

float costo_servicio(float distancia, int region) {
    float costoporKm;

    switch (region) {
        case 1:
            costoporKm = 9;//norte
            break;
        case 2:
            costoporKm = 8;//sur
            break;
        case 3:
            costoporKm = 11;//este
            break;
        case 4:
            costoporKm = 7;//oeste
            break;
        default:
            printf("Region no valida\n");
            return -1;
    }

    return distancia * costoporKm;
}

int main() {
    float distancia;
    int region;

    //Solicitud de distancia 
    printf("Introduce la distancia en kilometros: ");
    scanf("%f", &distancia);

    //Soliciutd de region
    printf("Introduce la region:\n");
    printf("1. Norte\n");
    printf("2. Sur\n");
    printf("3. Este\n");
    printf("4. Oeste\n");
    scanf("%d", &region);

    
    if (costo_servicio(distancia, region) != -1) {
        printf("Costo del servicio: $%.2f pesos\n", costo_servicio(distancia, region));
    }
    else {
        printf("Introduce una region valida\n");
    }


    return 0;
}