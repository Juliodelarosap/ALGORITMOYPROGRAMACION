#include <stdlib.h>
#include <stdio.h>

int suma(val1, val2);
int resta(val1, val2);
int multiplicacion(val1, val2);
int division(val1, val2);


main() {

	int opcion, pvalor, svalor;

	do {

		system("clear");

		printf("CALCULADORA\n\n");
		printf("1. Suma\n");
		printf("2. Resta\n");
		printf("3. Multiplicacion\n");
		printf("4. Division\n");
		printf("5. Salir\n\n");


		scanf("%d",&opcion);
		printf("Introduce un numero: ");
		scanf("%d",&pvalor);
		printf("Introduce otro numero: ");
		scanf("%d",&svalor);

		switch(opcion) {
			case 1:
				printf("Resultado: %d\n", suma(pvalor, svalor));
				break;
			case 2:
				printf("Resultado: %d\n", resta(pvalor, svalor));
				break;
			case 3:
				printf("Resultado: %d\n", multiplicacion(pvalor, svalor));
				break;
			case 4:
				if(svalor==0){
					printf("No se puede dividir entre 0, intentalo otra  vez...\n ");
				} else {
					printf("Resultado: %d\n", division(pvalor, svalor));   
				}
				break;
			case 5:
				printf("Saliendo...\n\n");
		}
		sleep(3);
	
	} while(!(opcion==5));

}

int suma(int val1, int val2) {
    return val1 + val2;
}

int resta(int val1, int val2) {
    return val1 - val2;
}

int multiplicacion(int val1, int val2) {
    return val1 * val2;
}

int division(int val1, int val2) {
    return val1 / val2;
}


