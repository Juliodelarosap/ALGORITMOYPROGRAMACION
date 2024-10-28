/*5. El salón de belleza Las Marías, ha lanzado un concurso, que consiste en otorgar boletos a los clientes por consumo, por el uso de líneas de belleza, y por tipo de servicio. 
para ello necesita un programa en C que determine la cantidad de boletos que entregará a cada cliente en cada servicio prestado. Puede sumar boletos por cada aspecto.

Por monto de servicios:

Hasta 1000 pesos, 5 boletos
1001 a 2000 pesos, 10 boletos
2001 a 3000 pesos, 15 boletos
mas de 3000 pesos, 20 boletos

Por tipo de procedimiento o servicio:

Corte de cabello, 2 boletos
Lavado de cabeza, 3 boletos
Secado de cabello, 1 boleto
Tinte, 5 boletos

Por línea de producto:

Sebastian, 5 boletos
Palmolive, 3 boletos
Treceme, 4 boletos

El programa debe pedir tipo de procedimiento, costo del procedimiento, y línea usada. Al final debe desplegar, tipo de procedimiento, costo, y línea usada, 
así como el total de boletos obtenido.*/

#include <stdio.h>
#include <string.h>

int main() {
    char tipo_procedimiento[20];
    float costo;
    char linea_producto[20];
    int boletos = 0;

    // Solicitar datos al usuario
    printf("Ingrese el tipo de procedimiento (Corte, Lavado, Secado, Tinte): ");
    scanf("%s", tipo_procedimiento);
    printf("Ingrese el costo del procedimiento: ");
    scanf("%f", &costo);
    printf("Ingrese la linea de producto (Sebastian, Palmolive, Treceme): ");
    scanf("%s", linea_producto);

    // Calcular boletos por monto de servicios
    if (costo <= 1000) {
        boletos += 5;
    } else if (costo <= 2000) {
        boletos += 10;
    } else if (costo <= 3000) {
        boletos += 15;
    } else {
        boletos += 20;
    }

    // Calcular boletos por tipo de procedimiento
    if (strcmp(tipo_procedimiento, "Corte") == 0) {
        boletos += 2;
    } else if (strcmp(tipo_procedimiento, "Lavado") == 0) {
        boletos += 3;
    } else if (strcmp(tipo_procedimiento, "Secado") == 0) {
        boletos += 1;
    } else if (strcmp(tipo_procedimiento, "Tinte") == 0) {
        boletos += 5;
    }

    // Calcular boletos por línea de producto
    if (strcmp(linea_producto, "Sebastian") == 0) {
        boletos += 5;
    } else if (strcmp(linea_producto, "Palmolive") == 0) {
        boletos += 3;
    } else if (strcmp(linea_producto, "Treceme") == 0) {
        boletos += 4;
    }

    // Mostrar resultados
    printf("Tipo de procedimiento: %s\n", tipo_procedimiento);
    printf("Costo del procedimiento: %.2f\n", costo);
    printf("Linea de producto: %s\n", linea_producto);
    printf("Total de boletos obtenidos: %d\n", boletos);

    return 0;
}
