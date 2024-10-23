#include <stdio.h>

int main(){

    float monto;

    printf("Ingrese el monto de la compra: ");
    scanf("%f", &monto);

    if (monto > 5000.00) {
        printf("El cliente recibe un descuento del 10%%, de %.2f\n",monto);
        printf("El descuento es: %.2f\n", (monto * 0.10));
        printf("El monto a pagar es: %.2f\n", (monto - (monto * 0.10)));
    }
    if(monto >4500 && monto <= 5000){
        printf("El cliente recibe un descuento del 5%%, de %.2f\n",monto);
        printf("El descuento es: %.2f\n", (monto * 0.05));
        printf("El monto a pagar es: %.2f\n", (monto - (monto * 0.05)));
    }   
        else {
            printf("El cliente no recibe descuento.\n");
    }
return 0;
}