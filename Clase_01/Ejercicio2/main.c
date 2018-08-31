#include <stdio.h>
#include <stdlib.h>

int main()
{
    //2.	Escribir el programa necesario para calcular la suma de dos números. Mostrar el resultado
    int numero1;
    int numero2;

    printf("Ingrese el numero 1: ");
    scanf("%d", &numero1);

    printf("Ingrese el numero 2: ");
    scanf("%d", &numero2);

    printf("La suma de los numeros es %d", numero1+numero2);

    return 0;
}
