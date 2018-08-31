#include <stdio.h>
#include <stdlib.h>
//VARIABLES. ACUMULADORES. CONTADORES.
int main()
{
    //1.	Ingresar 5 n�meros y calcular su media
    int numero1;
    int numero2;
    int numero3;
    int numero4;
    int numero5;
    float promedio;

    //Comentario de prueba
    printf("Ingrese el numero 1: ");
    scanf("%d", &numero1);

    printf("Ingrese el numero 2: ");
    scanf("%d", &numero2);

    printf("Ingrese el numero 3: ");
    scanf("%d", &numero3);

    printf("Ingrese el numero 4: ");
    scanf("%d", &numero4);

    printf("Ingrese el numero 5: ");
    scanf("%d", &numero5);

    promedio = (float) (numero1+numero2+numero3+numero4+numero5)/5;
    printf("El promedio es: %.2f", promedio);

    return 0;
}
