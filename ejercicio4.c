#include<stdio.h>

int main(){
    int n_salario;
    int t_salario = 0;
    int t_profesores;
    float promedio;

    printf("Ingrese la cantidad de profesores para calcular salario:\n");
    scanf("%i", &t_profesores);

    for ( int i = 0; i < t_profesores; i++)
    {
        printf("Ingrese el salario del profesor %i: ", i+1);
        scanf("%i", &n_salario);

        if (n_salario > 0)
        {
            t_salario += n_salario;
        }
        
        else
        {
            printf("El salario ingresado no es valido.\n");
            i--;
        }

    }
    promedio = t_salario / t_profesores;
    printf("La suma total de salarios es: %i\n", t_salario);
    printf("El promedio de salarios es: %.2f\n", promedio);
    
}