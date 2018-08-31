#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    3.	Escribir  un programa que realice las siguientes acciones
•	Limpie la pantalla
•	Asigne a 2 variables numero1 y numero2 valores distintos de cero
•	Efectúe el producto de dichas variables
•	Muestre el resultado pos pantalla
•	Obtenga el cuadrado de numero1 y lo muestre par pantalla
    */

    //Limpie la pantalla
    system("cls");

    //Asigne a 2 variables numero1 y numero2 valores distintos de cero
    int numero1=0;
    int numero2=0;

    while(numero1==0){
        printf("Ingrese el numero 1: ");
        scanf("%d", &numero1);
    }

    while(numero2==0){
        printf("Ingrese el numero 2: ");
        scanf("%d", &numero2);
    }

    //Efectúe el producto de dichas variables
    int producto = numero1*numero2;

    //Muestre el resultado pos pantalla
    printf("El producto de numero 1 y numero 2 es %d \n", producto);

    //Obtenga el cuadrado de numero1 y lo muestre par pantalla
    printf("El cuadrado de numero 1 es %d \n", numero1*numero1);

    return 0;
}
