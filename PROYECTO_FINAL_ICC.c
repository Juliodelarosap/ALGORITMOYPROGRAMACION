#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// CONSTANTES
#define MAX_PRODUCTOS 100
#define MAX_TRANSACCIONES 100

// ingreso al sistema usuario x contraseña
#define USUARIO "abc"
#define CLAVE "1016"
#define LONGITUD 80 

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
char usuario [LONGITUD + 1];
char clave [LONGITUD + 1];
int intento = 0;
int ingresa = 0;

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
void factura();

// FUNCIÓN PRINCIPAL
int main() {

    // login
     do{  
        system("cls"); 
        printf("\n\t\t\tINICIO DE SESION\n");
        printf("\t\t\t----------------\n");
        printf ("\n\tUSUARIO: ");
        gets(usuario);
        printf("\tCLAVE: ");
        gets(clave);

    if (strcmp(usuario, USUARIO) == 0 && strcmp (clave,CLAVE) == 0) {
        ingresa = 1;
    } else {
        printf("\n\tUsuario y/o clave son incorrectos\n");
        intento++;
        getchar();
    } 

    } while (intento < 3 && ingresa == 0);

    if (ingresa == 1) {
        printf("\n\tBienvenido al Sistema\n");
        getch();

    } else {
        printf("\n\tHa sobrepasado el numero de intentos permitidos\n");
        exit(-1);
    }
    // fin login

    mostrar_menu_principal();
    return 0;
}

// IMPLEMENTACIÓN DE FUNCIONES

void mostrar_menu_principal() {
    int opcion;
    do {
        system("cls");  // Limpiar pantalla
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Listado de inventario (crear/actualizar/eliminar items)\n");
        printf("2. Listado de transacciones (compra/salida/ajuste)\n");
        printf("3. Salir del programa\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        system("cls");  // Limpiar pantalla

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
        system("cls");  // Limpiar pantalla
        printf("\n--- GESTION DE INVENTARIO ---\n");
        printf("1. Mostrar listado de inventario\n");
        printf("2. Crear/Actualizar items\n");
        printf("3. Eliminar items\n");
        printf("4. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        system("cls");  // Limpiar pantalla

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
        system("cls");  // Limpiar pantalla
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
    system("cls");  // Limpiar pantalla
     //printf("prueba de variable: cantidad_productos = %d\n", cantidad_productos);
    if (cantidad_productos == 0) {
        printf("No hay productos en el inventario.\n");
        getch();
    }
    else {
    printf("\n--- LISTADO DE INVENTARIO ---\n");
    for (int i = 0; i < cantidad_productos; i++) {
        printf("ID: %d | Nombre: %s | Existencia: %d | Precio de Venta: %.2f | Proveedor: %s | Estado: %c\n",
               inventario[i].id, inventario[i].nombre, inventario[i].existencia,
               inventario[i].precio_venta, inventario[i].proveedor, inventario[i].estado);// se modifico para que muestre el estado del producto, favor revisar...
    }                                                                                     // R: se reviso 
    getch();
}
 
}

/*void crear_actualizar_producto() {
    system("cls");  // Limpiar pantalla
    Producto nuevo_producto;
    printf("\n--- CREAR/ACTUALIZAR PRODUCTO ---\n");
    printf("Ingrese el ID del producto: ");
    scanf("%d", &nuevo_producto.id);
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nuevo_producto.nombre);
    printf("Ingrese la existencia inicial: ");
    scanf("%d", &nuevo_producto.existencia);
    printf("Ingrese la unidad de medida (l=libra, k=kilo, i=litro, o=onza, u=unidad): ");
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
}*/
void crear_actualizar_producto() { //funcion modificada para no tener que repetir el proceso, favor revisar...
    system("cls");  // Limpiar pantalla
    int opcion;
    printf("\n--- CREAR/ACTUALIZAR PRODUCTO ---\n");
    printf("Seleccione una opcion:\n");
    printf("1. Agregar producto\n");
    printf("2. Actualizar producto\n");
    printf("3. Volver al menu anterior\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        system("cls");  // Limpiar pantalla
        Producto nuevo_producto;
        printf("Ingrese el ID del producto: ");
        scanf("%d", &nuevo_producto.id);
        printf("Ingrese el nombre del producto: ");
        scanf(" %[^\n]", nuevo_producto.nombre);
        printf("Ingrese la existencia inicial: ");
        scanf("%d", &nuevo_producto.existencia);
        printf("Ingrese la unidad de medida (l=libra, k=kilo, i=litro, o=onza, u=unidad): ");
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

        if (cantidad_productos < MAX_PRODUCTOS) {
            inventario[cantidad_productos++] = nuevo_producto;
            printf("Producto agregado con exito.\n");
        } else {
            printf("Error: Inventario lleno.\n");
        }
        getch();
    } else if (opcion == 2) {
        system("cls");  // Limpiar pantalla
        int id;
        printf("Ingrese el ID del producto a actualizar: ");
        scanf("%d", &id);
        for (int i = 0; i < cantidad_productos; i++) {
            if (inventario[i].id == id) {
                printf("Seleccione el campo a actualizar:\n");
                printf("1. Nombre\n");
                printf("2. Existencia\n");
                printf("3. Unidad de medida\n");
                printf("4. Empaque\n");
                printf("5. Peso\n");
                printf("6. Precio de compra\n");
                printf("7. Estado\n");
                printf("8. Proveedor\n");
                printf("9. Fecha de la ultima compra\n");
                int campo;
                printf("Seleccione una opcion: ");
                scanf("%d", &campo);
                switch (campo) {
                    case 1:
                        printf("Ingrese el nuevo nombre: ");
                        scanf(" %[^\n]", inventario[i].nombre);//revisar esa forma de google 
                        break;
                    case 2:
                        printf("Ingrese la nueva existencia: ");
                        scanf("%d", &inventario[i].existencia);
                        break;
                    case 3:
                        printf("Ingrese la nueva unidad de medida (l=libra, k=kilo, i=litro, o=onza, u=unidad): ");
                        scanf(" %c", &inventario[i].unidad_medida);
                        break;
                    case 4:
                        printf("Ingrese el nuevo empaque (c=caja, b=botella, g=granel, f=funda, o=otro): ");
                        scanf(" %c", &inventario[i].empaque);
                        break;
                    case 5:
                        printf("Ingrese el nuevo peso: ");
                        scanf("%f", &inventario[i].peso);
                        break;
                    case 6:
                        printf("Ingrese el nuevo precio de compra: ");
                        scanf("%f", &inventario[i].precio_compra);
                        inventario[i].precio_venta = inventario[i].precio_compra * 1.2;
                        break;
                    case 7:
                        printf("Ingrese el nuevo estado (a=activo, c=cancelado, d=descontinuado): ");
                        scanf(" %c", &inventario[i].estado);
                        break;
                    case 8:
                        printf("Ingrese el nuevo proveedor: ");
                        scanf(" %[^\n]", inventario[i].proveedor);
                        break;
                    case 9:
                        printf("Ingrese la nueva fecha de la ultima compra: ");
                        scanf(" %[^\n]", inventario[i].fecha_ultima_compra);
                        break;
                    default:
                        printf("Opcion no valida.\n");
                        return;
                }
                printf("Producto actualizado con exito.\n");
                return;
            }
        }
        printf("Error: Producto no encontrado.\n");
    } else {
        printf("Opcion no valida.\n");
    }
}
void eliminar_producto() {
    system("cls");  // Limpiar pantalla
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
    system("cls");  // Limpiar pantalla
    if (cantidad_transacciones == 0) {
        printf("No hay transacciones registradas.\n");
    } else {
        printf("\n--- LISTADO DE TRANSACCIONES ---\n");
        for (int i = 0; i < cantidad_transacciones; i++) {
            printf("ID Producto: %d | Nombre: %s | Fecha: %s | Tipo: %c | Cantidad: %d | Proveedor: %s\n",
                   transacciones[i].id_producto, transacciones[i].nombre_producto,
                   transacciones[i].fecha_transaccion, transacciones[i].tipo_transaccion,
                   transacciones[i].cantidad, transacciones[i].proveedor);
        }
    }
    printf("\nPresione cualquier tecla para continuar...");
    getch();  // Esperar a que el usuario presione una tecla
}


void registrar_transaccion() { 
    system("cls");  // Limpiar pantalla
    Transaccion nueva_transaccion;
    printf("\n--- REGISTRAR TRANSACCION ---\n");
    printf("Ingrese el ID del producto: ");
    scanf("%d", &nueva_transaccion.id_producto);

    // Buscar el producto en el inventario
   /* int producto_encontrado = -1;
    for (int i = 0; i < cantidad_productos; i++) {
        if (inventario[i].id == nueva_transaccion.id_producto) {
            producto_encontrado = i;
            strcpy(nueva_transaccion.nombre_producto, inventario[i].nombre);
            break;
        }
    }

    if (producto_encontrado == -1) {
        printf("Error: Producto no encontrado en el inventario.\n");
        return;
    }*/
    int producto_encontrado = 0;                                              
int encontrado = 0;  // Nueva bandera para indicar si el producto se encontró

for (int i = 0; i < cantidad_productos; i++) {
    if (inventario[i].id == nueva_transaccion.id_producto) {
        producto_encontrado = i;
        strcpy(nueva_transaccion.nombre_producto, inventario[i].nombre);
        encontrado = 1;  // Marca que el producto fue encontrado
        break;
    }
}

if (!encontrado) {  // Verifica si no se encontró el producto
    printf("Error: Producto no encontrado en el inventario.\n");
    return;
}


    printf("Producto: %s\n", nueva_transaccion.nombre_producto);
    printf("Ingrese la fecha de la transaccion: ");
    scanf(" %[^\n]", nueva_transaccion.fecha_transaccion);
    printf("Ingrese el tipo de transaccion (e=entrada, s=salida, a=ajuste): ");
    scanf(" %c", &nueva_transaccion.tipo_transaccion);
    printf("Ingrese la cantidad: ");
    scanf("%d", &nueva_transaccion.cantidad);

    // Actualizar inventario y registrar transacción
    if (nueva_transaccion.tipo_transaccion == 'e') {
        inventario[producto_encontrado].existencia += nueva_transaccion.cantidad;
        strcpy(inventario[producto_encontrado].fecha_ultima_compra, nueva_transaccion.fecha_transaccion);
    } 
    
    else if (nueva_transaccion.tipo_transaccion == 's') {
        if (inventario[producto_encontrado].existencia >= nueva_transaccion.cantidad) {
            inventario[producto_encontrado].existencia -= nueva_transaccion.cantidad;
            strcpy(inventario[producto_encontrado].fecha_ultima_venta, nueva_transaccion.fecha_transaccion);
        } else {
            printf("Error: Inventario insuficiente.\n");
            return;
        }
    } 
    
    else if (nueva_transaccion.tipo_transaccion == 'a') {
        inventario[producto_encontrado].existencia += nueva_transaccion.cantidad;
    } 
    
    else {
        printf("Error: Tipo de transaccion no valido.\n");
        return;
    }

    transacciones[cantidad_transacciones++] = nueva_transaccion;
    printf("Transaccion registrada con exito.\n");
    factura();
}

void factura() {
    system("cls");  // Limpiar pantalla
    printf("\n--- FACTURA ---\n");

    // Buscar el producto en el inventario por ID
    int id_producto = transacciones[cantidad_transacciones - 1].id_producto;
    int producto_encontrado = -1;
    for (int i = 0; i < cantidad_productos; i++) {
        if (inventario[i].id == id_producto) {
            producto_encontrado = i;
            break;
        }
    }

    if (producto_encontrado == -1) {
        printf("Error: Producto no encontrado en el inventario.\n");
        return;
    }

    // Imprimir factura
    printf("ID Producto: %d | Nombre: %s | Cantidad: %d | Precio unidad: %.2f | Precio total: %.2f\n",
           id_producto,
           inventario[producto_encontrado].nombre,
           transacciones[cantidad_transacciones - 1].cantidad,
           inventario[producto_encontrado].precio_venta,
           (transacciones[cantidad_transacciones - 1].cantidad * inventario[producto_encontrado].precio_venta));

    getch();
}



void salir_programa() {
    printf("Gracias por utilizar el programa. Adios.\n");
    exit(0);

    //return 0; // es lo mismo que exit(0)
}