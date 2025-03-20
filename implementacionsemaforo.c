#include <stdio.h>
#include <unistd.h> 

void semaforo() {
    while (1) {
        printf("Luz ROJA\n");
        for (int i = 15; i > 0; i--) {
            printf("%d segundos\n", i);
            sleep(1);
        }

        printf("Luz VERDE\n");
        for (int i = 15; i > 0; i--) {
            printf("%d segundos\n", i);
            sleep(1);
        }

        printf("Luz AMARILLA\n");
        for (int i = 5; i > 0; i--) {
            printf("%d segundos\n", i);
            sleep(1);
        }
    }
}

int main() {
    printf("Iniciando semaforo...\n");
    semaforo();
    return 0;
}
