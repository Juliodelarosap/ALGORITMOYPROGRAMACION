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
    printf("4. Mostrar inventario\n");
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
        
        case 4:
            mostrar_menu_inventario();
            break;
        default:
            printf("Opcion no valida\n");
        }

    } while(opcion != 3);

    return 0;
}

void mostrar_menu_inventario() {
    printf("\n--- Listado de Inventario ---\n");
    for (int i = 0; i < cantidad_productos; i++) {
        printf("ID: %d, Nombre: %s, Cantidad: %d, Precio: %.2f, Proveedor: %s\n",
               inventario[i].id, inventario[i].nombre, inventario[i].existencia, inventario[i].precio_venta, inventario[i].proveedor, inventario[i].estado, 
               inventario[i].fechaultimacompra,inventario[i].fehcaultimaventa,inventario[i].unidad_medida, inventario[i].empaque, inventario[i].peso);
    }
    gestion_de_inventario();
}

void gestion_de_inventario() {
    int opcion;
    printf("\nOpciones:\n");
    printf("1. Crear producto\n");
    printf("2. Actualizar producto\n");
    printf("3. Eliminar producto\n");
    printf("4. Regresar al menu principal\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1: {
            Producto p;
            printf("Ingrese ID del producto: ");
            scanf("%d", &p.id);
            printf("Ingrese nombre del producto: ");
            scanf("%s", p.nombre);
            printf("Ingrese cantidad inicial: ");
            scanf("%d", &p.existencia);
            printf("Ingrese precio de compra: ");
            scanf("%f", &p.precio_compra);
            printf("Ingrese proveedor: ");
            scanf("%s", p.proveedor);
           /* printf("Producto activo (a), cancelado (c) o descontinuado (d): ");
            scanf("%s", p.estado);
            printf("Ingrese fecha de la ultima compra: ");
            scanf("%s", p.fechaultimacompra);
            printf("Ingrese fecha de la ultima venta: ");
            scanf("%s", p.fehcaultimaventa);
            printf("Ingrese unidad de medida (l = litros, kg = kilogramos, u = unidades): ");
            scanf("%f", &p.unidad_medida);
            printf("Ingrese empaque (c = caja, p = paquete, u = unidad): ");
            scanf("%f", &p.empaque);
            printf("Ingrese peso: ");
            scanf("%f", &p.peso);*/

            
            p.precio_venta = p.precio_compra * 1.2; // Precio de venta con 20% de margen
            inventario[cantidad_productos++] = p;

            printf("Producto agregado con exito.\n");
            break;
        }
        case 2: {
            int id, encontrado = 0;
            printf("Ingrese ID del producto a actualizar: ");
            scanf("%d", &id);
            for (int i = 0; i < cantidad_productos; i++) {
                if (inventario[i].id == id) {
                    printf("Ingrese nuevo nombre: ");
                    scanf("%s", inventario[i].nombre);
                    printf("Ingrese nueva cantidad: ");
                    scanf("%d", &inventario[i].existencia);
                    printf("Ingrese nuevo precio: ");
                    scanf("%f", &inventario[i].precio_venta);
                    printf("Ingrese nuevo proveedor: ");
                    scanf("%s", inventario[i].proveedor);
                    encontrado = 1;
                    printf("Producto actualizado.\n");
                    break;
                }
            }
            if (!encontrado) {
                printf("Producto no encontrado.\n");
            }
            break;
        }
        case 3: {
            int id, encontrado = 0;
            printf("Ingrese ID del producto a eliminar: ");
            scanf("%d", &id);
            for (int i = 0; i < cantidad_productos; i++) {
                if (inventario[i].id == id) {
                    for (int j = i; j < cantidad_productos - 1; j++) {
                        inventario[j] = inventario[j + 1];
                    }
                    cantidad_productos--;
                    encontrado = 1;
                    printf("Producto eliminado.\n");
                    break;
                }
            }
            if (!encontrado) {
                printf("Producto no encontrado.\n");
            }
            break;
        }
        case 4:
            return;
        default:
            printf("Opcion invalida.\n");
    }
}

void mostrar_transacciones() {
    printf("\n--- Listado de Transacciones ---\n");
    for (int i = 0; i < cantidad_transacciones; i++) {
        printf("ID Producto: %d, Fecha: %s, Tipo: %s, Cantidad: %d\n",
               transacciones[i].id_producto, transacciones[i].fechadetransaccion, transacciones[i].operacion, transacciones[i].cantidad);
    }
    gestion_de_transacciones();
}

void gestion_de_transacciones() {
    int opcion;
    printf("\nOpciones:\n");
    printf("1. Registrar nueva transaccion\n");
    printf("2. Regresar al menu principal\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        Transaccion t;
        printf("Ingrese ID del producto: ");
        scanf("%d", &t.id_producto);
        printf("Ingrese fecha (YYYY-MM-DD): ");
        scanf("%s", t.fechadetransaccion);
        printf("Ingrese tipo de transaccion (entrada/salida/ajuste): ");
        scanf("%s", t.operacion);
        printf("Ingrese cantidad: ");
        scanf("%d", &t.cantidad);

        int encontrado = 0;
        for (int i = 0; i < cantidad_productos; i++) {
            if (inventario[i].id == t.id_producto) {
                if (strcmp(t.operacion, "salida") == 0 && inventario[i].existencia < t.cantidad) {
                    printf("Error: Cantidad insuficiente.\n");
                } else {
                    if (strcmp(t.operacion, "entrada") == 0) {
                        inventario[i].existencia += t.cantidad;
                    } else if (strcmp(t.operacion, "salida") == 0) {
                        inventario[i].existencia -= t.cantidad;
                    } else if (strcmp(t.operacion, "ajuste") == 0) {
                        inventario[i].existencia = t.cantidad;
                    }
                    transacciones[cantidad_transacciones++] = t;
                    printf("Transaccion registrada con exito.\n");
                }
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("Producto no encontrado.\n");
        }
    }
}

void salir_del_programa() {
    printf("Gracias por usar el programa. Adios!\n");
    exit(0);
}










    
