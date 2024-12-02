#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTES
#define MAX_PRODUCTOS 100
#define MAX_TRANSACCIONES 100

// ESTRUCTURAS
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

typedef struct {
    int id_producto;
    char nombre_producto[50];
    char fecha_transaccion[20];
    char tipo_transaccion;
    int cantidad;
    char proveedor[50];
} Transaccion;

// VARIABLES GLOBALES
Producto inventario[MAX_PRODUCTOS];
Transaccion transacciones[MAX_TRANSACCIONES];
int cantidad_productos = 0;
int cantidad_transacciones = 0;

// PROTOTIPOS DE FUNCIONES
void mostrar_menu_principal();
void gestion_inventario();
void gestion_transacciones();
void mostrar_inventario();
void crear_actualizar_producto();
void eliminar_producto();
void mostrar_transacciones();
void registrar_transaccion();
void salir_programa();

// FUNCIÓN PRINCIPAL
int main() {
    mostrar_menu_principal();
    return 0;
}

// IMPLEMENTACIÓN DE FUNCIONES

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
                gestion_inventario();
                break;
            case 2:
                gestion_transacciones();
                break;
            case 3:
                salir_programa();
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 3);
}

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
                mostrar_inventario();
                break;
            case 2:
                crear_actualizar_producto();
                break;
            case 3:
                eliminar_producto();
                break;
            case 4:
                return;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 4);
}

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
                mostrar_transacciones();
                break;
            case 2:
                registrar_transaccion();
                break;
            case 3:
                return;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 3);
}

void mostrar_inventario() {
    printf("\n--- LISTADO DE INVENTARIO ---\n");
    for (int i = 0; i < cantidad_productos; i++) {
        printf("ID: %d | Nombre: %s | Existencia: %d | Precio de Venta: %.2f | Proveedor: %s\n",
               inventario[i].id, inventario[i].nombre, inventario[i].existencia,
               inventario[i].precio_venta, inventario[i].proveedor);
    }
}

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

    // Actualización o creación
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
