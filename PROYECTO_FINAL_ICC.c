/*1. Inicializar datos  
   1.1 Crear arreglos para almacenar:  
       1.1.1 Inventario.  
       1.1.2 Transacciones.  
   1.2 Inicializar variables necesarias para el manejo del programa.  

2. Menú principal  
   2.1 Mostrar opciones al usuario:  
       2.1.1 Listado de inventario.  
       2.1.2 Listado de transacciones.  
       2.1.3 Salir del programa.  
   2.2 Leer la opción seleccionada.  
   2.3 Realizar acción según la opción:  
       2.3.1 Ir al manejo del inventario si se selecciona opción 1.  
       2.3.2 Ir al manejo de transacciones si se selecciona opción 2.  
       2.3.3 Salir si se selecciona opción 3.

3. Listado de inventario (Opción 1) 
   3.1 Mostrar la información del inventario:  
       3.1.1 ID del producto.  
       3.1.2 Nombre del producto.  
       3.1.3 Existencia.  
       3.1.4 Precio de venta.  
       3.1.5 Proveedor.  
   3.2 Mostrar opciones para manipular el inventario:  
       3.2.1 Crear producto.  
       3.2.2 Actualizar producto.  
       3.2.3 Eliminar producto.  
   3.3 Realizar acción según la opción:  
       3.3.1 Crear producto:  
           3.3.1.1 Solicitar datos del producto:  
               3.3.1.1.1 ID del producto.  
               3.3.1.1.2 Nombre del producto.  
               3.3.1.1.3 Existencia inicial.  
               3.3.1.1.4 Unidad de medida.  
               3.3.1.1.5 Empaque.  
               3.3.1.1.6 Peso.  
               3.3.1.1.7 Precio de compra.  
               3.3.1.1.8 Estado del producto.  
               3.3.1.1.9 Proveedor.  
           3.3.1.2 Calcular precio de venta (20% sobre el precio de compra).  
           3.3.1.3 Agregar producto al inventario.  
       3.3.2 Actualizar producto:  
           3.3.2.1 Solicitar ID del producto a actualizar.  
           3.3.2.2 Buscar producto en el arreglo de inventario.  
           3.3.2.3 Solicitar datos a modificar.  
           3.3.2.4 Actualizar datos en el inventario.  
       3.3.3 Eliminar producto:  
           3.3.3.1 Solicitar ID del producto a eliminar.  
           3.3.3.2 Buscar producto en el inventario.  
           3.3.3.3 Eliminar el producto del arreglo de inventario.  

4. Listado de transacciones (Opción 2)  
   4.1 Mostrar todas las transacciones registradas:  
       4.1.1 ID del producto.  
       4.1.2 Fecha de la transacción.  
       4.1.3 Tipo de transacción.  
   4.2 Mostrar opción para registrar nueva transacción:  
       4.2.1 Solicitar datos de la transacción:  
           4.2.1.1 ID del producto.  
           4.2.1.2 Cantidad.  
           4.2.1.3 Fecha de la transacción.  
           4.2.1.4 Tipo de transacción (entrada, salida, ajuste).  
       4.2.2 Validar operación:  
           4.2.2.1 Si la transacción es salida, verificar existencia suficiente.  
           4.2.2.2 Mostrar error si la operación no es válida.  
       4.2.3 Actualizar inventario según operación:  
           4.2.3.1 Si es entrada, sumar cantidad.  
           4.2.3.2 Si es salida, restar cantidad.  
           4.2.3.3 Si es ajuste, modificar cantidad a la nueva establecida.  
       4.2.4 Registrar transacción en el arreglo de transacciones.  

5. Salir del programa (Opción 3)  
   5.1 Mostrar mensaje de despedida.  
   5.2 Finalizar ejecución del programa.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTES
#define MAX_PRODUCTOS 100 // Cantidad máxima de productos en el inventario
#define MAX_TRANSACCIONES 100 // Cantidad máxima de transacciones

// DATOS DE ALMACEN DE PRODUCTOS
typedef struct {
    int id;          // id del producto
    char nombre[50]; // nombre del producto
    int existencia; // cantidad de productos en existencia
    float unidad_medida; // unidad de medida (l = litros, kg = kilogramos, u = unidades)
    float empaque; // empaque (c = caja, p = paquete, u = unidad)
    float peso; // peso del producto
    float precio_compra; // precio de compra al proveedor
    float precio_venta; // precio de venta al público(20% sobre el precio de compra)
    char estado[20]; // estado del producto (a = activo, c = cancelado , d = descontinuado)
    char proveedor[50]; // nombre del proveedor
    char fechaultimacompra[20]; // fecha de la última compra
    char fehcaultimaventa[20]; // fecha de la última venta
} Producto;

// DATOS DE TRANSACCIONES
typedef struct {
    int id_producto; // id del producto
    int cantidad; // cantidad de productos
    char fechadetransaccion[20]; // fecha de la transacción
    char operacion[20]; // tipo de operación (e = entrada, s = salida, a = ajuste)
} Transaccion;

// VARIABLES GLOBALES

Producto inventario[MAX_PRODUCTOS]; // arreglo de productos
Transaccion transacciones[MAX_TRANSACCIONES]; // arreglo de transacciones
int cantidad_productos = 0; // cantidad de productos en el invent
int cantidad_transacciones = 0; // cantidad de transacciones

// FUNCIONES
void mostrar_menu_inventario();
void gestion_de_inventario();
void mostrar_menu_transacciones();
void gestion_de_transacciones();
void salir_del_programa();

int main() {

int opcion;

do {
    printf("\n-------------------MENU PRINCIPAL-------------------\n");
    printf("1. Gestion de inventario\n");
    printf("2. Gestion de transacciones\n");
    printf("3. Salir del programa\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
        case 1:
            gestion_de_inventario();
            break;
        case 2:
            gestion_de_transacciones();
            break;
        case 3:
            salir_del_programa();
            break;
        default:
            printf("Opcion no valida\n");
        }

    } while(opcion != 3);

    return 0;
}




    
