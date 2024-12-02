
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTES
#define MAX_PRODUCTOS 100
#define MAX_TRANSACCIONES 100

// ESTRUCTURAS
typedef struct {
    int id;                         // ID del producto
    char nombre[50];                // Nombre del producto
    int existencia;                 // Cantidad en existencia
    char unidad_medida;             // Unidad de medida (l=libra, k=kilo, i=litro, o=onza, t=otro)
    char empaque;                   // Tipo de empaque (c=caja, b=botella, g=granel, f=funda, o=otro)
    float peso;                     // Peso del producto
    float precio_compra;            // Precio de compra del producto
    float precio_venta;             // Precio de venta del producto (20% sobre precio_compra)
    char estado;                    // Estado del producto (a=activo, c=cancelado, d=descontinuado)
    char proveedor[50];             // Proveedor del producto
    char fecha_ultima_compra[20];   // Fecha de la última compra
    char fecha_ultima_venta[20];    // Fecha de la última venta
} Producto;

typedef struct {
    int id_producto;                // ID del producto
    char nombre_producto[50];       // Nombre del producto
    char fecha_transaccion[20];     // Fecha de la transacción
    char tipo_transaccion;          // Tipo de transacción (e=entrada, s=salida, a=ajuste)
    int cantidad;                   // Cantidad de la transacción
    float precio;                   // Precio de la transacción
    char proveedor[50];             // Proveedor de la transacción
} Transaccion;

// VARIABLES GLOBALES
Producto inventario[MAX_PRODUCTOS]; // Arreglo de productos en el inventario
Transaccion transacciones[MAX_TRANSACCIONES]; // Arreglo de transacciones
int cantidad_productos = 0;         // Cantidad de productos en el inventario
int cantidad_transacciones = 0;     // Cantidad de transacciones registradas

// PROTOTIPOS DE FUNCIONES
void mostrar_menu_principal();      // Muestra el menú principal
void gestion_inventario();          // Gestiona el inventario
void gestion_transacciones();       // Gestiona las transacciones
void mostrar_inventario();          // Muestra el inventario
void crear_actualizar_producto();   // Crea o actualiza un producto
void eliminar_producto();           // Elimina un producto
void mostrar_transacciones();       // Muestra las transacciones
void registrar_transaccion();       // Registra una transacción
void salir_programa();              // Sale del programa

// FUNCIÓN PRINCIPAL
int main() {
    mostrar_menu_principal();       // Llama a la función para mostrar el menú principal
    return 0;
}

// IMPLEMENTACIÓN DE FUNCIONES

// Muestra el menú principal y gestiona la selección del usuario
void mostrar_menu_principal() {
    int opcion;
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Listado de inventario (crear/actualizar/eliminar items)\n");
        printf("2. Listado de transacciones (compra/salida/ajuste)\n");
        printf("3. Salir del programa\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                gestion_inventario(); // Llama a la función para gestionar el inventario
                break;
            case 2:
                gestion_transacciones(); // Llama a la función para gestionar las transacciones
                break;
            case 3:
                salir_programa(); // Llama a la función para salir del programa
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 3);
}

// Gestiona el inventario y las opciones del usuario
void gestion_inventario() {
    int opcion;
    do {
        printf("\n--- GESTION DE INVENTARIO ---\n");
        printf("1. Mostrar listado de inventario\n");
        printf("2. Crear/Actualizar items\n");
        printf("3. Eliminar items\n");
        printf("4. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrar_inventario(); // Llama a la función para mostrar el inventario
                break;
            case 2:
                crear_actualizar_producto(); // Llama a la función para crear o actualizar un producto
                break;
            case 3:
                eliminar_producto(); // Llama a la función para eliminar un producto
                break;
            case 4:
                return; // Vuelve al menú principal
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 4);
}

// Gestiona las transacciones y las opciones del usuario
void gestion_transacciones() {
    int opcion;
    do {
        printf("\n--- GESTION DE TRANSACCIONES ---\n");
        printf("1. Mostrar listado de transacciones\n");
        printf("2. Registrar transaccion (compra/salida/ajuste)\n");
        printf("3. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrar_transacciones(); // Llama a la función para mostrar las transacciones
                break;
            case 2:
                registrar_transaccion(); // Llama a la función para registrar una transacción
                break;
            case 3:
                return; // Vuelve al menú principal
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 3);
}

// Muestra el inventario de productos
void mostrar_inventario() {
    printf("\n--- LISTADO DE INVENTARIO ---\n");
    for (int i = 0; i < cantidad_productos; i++) {
        printf("ID: %d | Nombre: %s | Existencia: %d | Precio de Venta: %.2f | Proveedor: %s\n",
               inventario[i].id, inventario[i].nombre, inventario[i].existencia,
               inventario[i].precio_venta, inventario[i].proveedor);
    }
}

// Crea o actualiza un producto en el inventario
void crear_actualizar_producto() {
    Producto nuevo_producto;
    printf("\n--- CREAR/ACTUALIZAR PRODUCTO ---\n");
    printf("Ingrese el ID del producto: ");
    scanf("%d", &nuevo_producto.id);
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nuevo_producto.nombre);
    printf("Ingrese la existencia inicial: ");
    scanf("%d", &nuevo_producto.existencia);
    printf("Ingrese la unidad de medida (l=libra, k=kilo, i=litro, o=onza, t=otro): ");
    scanf(" %c", &nuevo_producto.unidad_medida);
    printf("Ingrese el empaque (c=caja, b=botella, g=granel, f=funda, o=otro): ");
    scanf(" %c", &nuevo_producto.empaque);
    printf("Ingrese el peso del producto: ");
    scanf("%f", &nuevo_producto.peso);
    printf("Ingrese el precio de compra: ");
    scanf("%f", &nuevo_producto.precio_compra);
    nuevo_producto.precio_venta = nuevo_producto.precio_compra * 1.2;
    printf("Ingrese el estado del producto (a=activo, c=cancelado, d=descontinuado): ");
    scanf(" %c", &nuevo_producto.estado);
    printf("Ingrese el proveedor: ");
    scanf(" %[^\n]", nuevo_producto.proveedor);
    printf("Ingrese la fecha de la ultima compra: ");
    scanf(" %[^\n]", nuevo_producto.fecha_ultima_compra);
    printf("Ingrese la fecha de la ultima venta: ");
    scanf(" %[^\n]", nuevo_producto.fecha_ultima_venta);

    // Agregar o actualizar producto en el inventario
    for (int i = 0; i < cantidad_productos; i++) {
        if (inventario[i].id == nuevo_producto.id) {
            inventario[i] = nuevo_producto;
            printf("Producto actualizado con exito.\n");
            return;
        }
    }
    if (cantidad_productos < MAX_PRODUCTOS) {
        inventario[cantidad_productos++] = nuevo_producto;
        printf("Producto agregado con exito.\n");
    } else {
        printf("Error: Inventario lleno.\n");
    }
}

// Elimina un producto del inventario
void eliminar_producto() {
    int id;
    printf("\n--- ELIMINAR PRODUCTO ---\n");
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%d", &id);
    for (int i = 0; i < cantidad_productos; i++) {
        if (inventario[i].id == id) {
            for (int j = i; j < cantidad_productos - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            cantidad_productos--;
            printf("Producto eliminado con exito.\n");
            return;
        }
    }
    printf("Error: Producto no encontrado.\n");
}

// Muestra el listado de transacciones
void mostrar_transacciones() {
    printf("\n--- LISTADO DE TRANSACCIONES ---\n");
    for (int i = 0; i < cantidad_transacciones; i++) {
        printf("ID Producto: %d | Nombre: %s | Fecha: %s | Tipo: %c | Cantidad: %d | Precio: %.2f | Proveedor: %s\n",
               transacciones[i].id_producto, transacciones[i].nombre_producto,
               transacciones[i].fecha_transaccion, transacciones[i].tipo_transaccion,
               transacciones[i].cantidad, transacciones[i].precio, transacciones[i].proveedor);
    }
}

// Registra una nueva transacción
void registrar_transaccion() {
    Transaccion nueva_transaccion;
    printf("\n--- REGISTRAR TRANSACCION ---\n");
    printf("Ingrese el ID del producto: ");
    scanf("%d", &nueva_transaccion.id_producto);
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nueva_transaccion.nombre_producto);
    printf("Ingrese la fecha de la transaccion: ");
    scanf(" %[^\n]", nueva_transaccion.fecha_transaccion);
    printf("Ingrese el tipo de transaccion (e=entrada, s=salida, a=ajuste): ");
    scanf(" %c", &nueva_transaccion.tipo_transaccion);
    printf("Ingrese la cantidad: ");
    scanf("%d", &nueva_transaccion.cantidad);
    printf("Ingrese el precio: ");
    scanf("%f", &nueva_transaccion.precio);
    printf("Ingrese el proveedor: ");
    scanf(" %[^\n]", nueva_transaccion.proveedor);

    // Registrar la transacción
    if (cantidad_transacciones < MAX_TRANSACCIONES) {
        transacciones[cantidad_transacciones++] = nueva_transaccion;
        printf("Transaccion registrada con exito.\n");
    } else {
        printf("Error: No se pueden registrar mas transacciones.\n");
    }
}

// Sale del programa
void salir_programa() {
    printf("\nGracias por usar el programa. Adios!\n");
    exit(0);
}









    
