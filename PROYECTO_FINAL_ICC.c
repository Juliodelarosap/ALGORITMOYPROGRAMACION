
/**
 * @file PROYECTO_FINAL_ICC.c
 * @brief Programa para la gestión de inventario y transacciones de productos.
 * 
 * Este programa permite gestionar un inventario de productos y registrar transacciones
 * de entrada, salida y ajuste de inventario. Proporciona un menú principal para acceder
 * a las funcionalidades de gestión de inventario y transacciones.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTES
#define MAX_PRODUCTOS 100 ///< Número máximo de productos en el inventario.
#define MAX_TRANSACCIONES 100 ///< Número máximo de transacciones registradas.

// ESTRUCTURAS

/**
 * @struct Producto
 * @brief Estructura que representa un producto en el inventario.
 * 
 * @var Producto::id
 * ID del producto.
 * @var Producto::nombre
 * Nombre del producto.
 * @var Producto::existencia
 * Cantidad en existencia del producto.
 * @var Producto::unidad_medida
 * Unidad de medida del producto (l=libra, k=kilo, i=litro, o=onza, t=otro).
 * @var Producto::empaque
 * Tipo de empaque del producto (c=caja, b=botella, g=granel, f=funda, o=otro).
 * @var Producto::peso
 * Peso del producto.
 * @var Producto::precio_compra
 * Precio de compra del producto.
 * @var Producto::precio_venta
 * Precio de venta del producto.
 * @var Producto::estado
 * Estado del producto (a=activo, c=cancelado, d=descontinuado).
 * @var Producto::proveedor
 * Proveedor del producto.
 * @var Producto::fecha_ultima_compra
 * Fecha de la última compra del producto.
 * @var Producto::fecha_ultima_venta
 * Fecha de la última venta del producto.
 */
typedef struct {
    int id;
    char nombre[50];
    int existencia;
    char unidad_medida;
    char empaque;
    float peso;
    float precio_compra;
    float precio_venta;
    char estado;
    char proveedor[50];
    char fecha_ultima_compra[20];
    char fecha_ultima_venta[20];
} Producto;

/**
 * @struct Transaccion
 * @brief Estructura que representa una transacción de inventario.
 * 
 * @var Transaccion::id_producto
 * ID del producto asociado a la transacción.
 * @var Transaccion::nombre_producto
 * Nombre del producto asociado a la transacción.
 * @var Transaccion::fecha_transaccion
 * Fecha de la transacción.
 * @var Transaccion::tipo_transaccion
 * Tipo de transacción (e=entrada, s=salida, a=ajuste).
 * @var Transaccion::cantidad
 * Cantidad de producto involucrada en la transacción.
 * @var Transaccion::proveedor
 * Proveedor asociado a la transacción.
 */
typedef struct {
    int id_producto;
    char nombre_producto[50];
    char fecha_transaccion[20];
    char tipo_transaccion;
    int cantidad;
    char proveedor[50];
} Transaccion;

// VARIABLES GLOBALES
Producto inventario[MAX_PRODUCTOS]; ///< Arreglo de productos en el inventario.
Transaccion transacciones[MAX_TRANSACCIONES]; ///< Arreglo de transacciones registradas.
int cantidad_productos = 0; ///< Cantidad actual de productos en el inventario.
int cantidad_transacciones = 0; ///< Cantidad actual de transacciones registradas.

// PROTOTIPOS DE FUNCIONES

/**
 * @brief Muestra el menú principal del programa.
 */
void mostrar_menu_principal();

/**
 * @brief Gestiona las opciones del inventario.
 */
void gestion_inventario();

/**
 * @brief Gestiona las opciones de transacciones.
 */
void gestion_transacciones();

/**
 * @brief Muestra el listado de productos en el inventario.
 */
void mostrar_inventario();

/**
 * @brief Crea o actualiza un producto en el inventario.
 */
void crear_actualizar_producto();

/**
 * @brief Elimina un producto del inventario.
 */
void eliminar_producto();

/**
 * @brief Muestra el listado de transacciones registradas.
 */
void mostrar_transacciones();

/**
 * @brief Registra una nueva transacción de inventario.
 */
void registrar_transaccion();

/**
 * @brief Sale del programa.
 */
void salir_programa();
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

void mostrar_transacciones() {
    printf("\n--- LISTADO DE TRANSACCIONES ---\n");
    for (int i = 0; i < cantidad_transacciones; i++) {
        printf("ID Producto: %d | Nombre: %s | Fecha: %s | Tipo: %c | Cantidad: %d | Proveedor: %s\n",
               transacciones[i].id_producto, transacciones[i].nombre_producto,
               transacciones[i].fecha_transaccion, transacciones[i].tipo_transaccion,
               transacciones[i].cantidad, transacciones[i].proveedor);
    }
}

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
    printf("Ingrese el proveedor: ");
    scanf(" %[^\n]", nueva_transaccion.proveedor);

    for (int i = 0; i < cantidad_productos; i++) {
        if (inventario[i].id == nueva_transaccion.id_producto) {
            if (nueva_transaccion.tipo_transaccion == 'e') {
                inventario[i].existencia += nueva_transaccion.cantidad;
                strcpy(inventario[i].fecha_ultima_compra, nueva_transaccion.fecha_transaccion);
            } else if (nueva_transaccion.tipo_transaccion == 's') {
                if (inventario[i].existencia >= nueva_transaccion.cantidad) {
                    inventario[i].existencia -= nueva_transaccion.cantidad;
                    strcpy(inventario[i].fecha_ultima_venta, nueva_transaccion.fecha_transaccion);
                } else {
                    printf("Error: Inventario insuficiente.\n");
                    return;
                }
            } else if (nueva_transaccion.tipo_transaccion == 'a') {
                inventario[i].existencia += nueva_transaccion.cantidad;
            }
            transacciones[cantidad_transacciones++] = nueva_transaccion;
            printf("Transaccion registrada con exito.\n");
            return;
        }
    }
    printf("Error: Producto no encontrado.\n");
}

void salir_programa() {
    printf("Gracias por utilizar el programa. Adios.\n");
    exit(0);
}
