#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"
#include "Validador.h"

int mostrarResultado(int x, int y);

int main(){
    int x=0;
    int y=0;
    char a[20];
    int flagprimeroperando=0;
    int flagsegundooperando=0;

    do
    {
        printf("Ingresar 1er operando (A=x): \n\n");
        scanf("%s/n/n", a);
    }while(validarnumero(a)==0);
    flagprimeroperando=1;
    x=atoi(a);
    fflush(stdout);

    do
    {
        printf("Ingresar 2do operando (B=y)): \n\n");
        scanf("%s/n/n", a);
    }while(validarnumero(a)==0);
    flagsegundooperando=1;
    y=atoi(a);

        if(flagprimeroperando && flagsegundooperando){

                printf("==========================================\n");
                printf("==          Elija una opcion            ==\n");
                printf("==========================================\n");
                printf("|   1. Suma                              |\n");
                printf("|   2. Resta                             |\n");
                printf("|   3. Division                          |\n");
                printf("|   4. Multiplicacion                    |\n");
                printf("|   5. Factorial                         |\n");
                printf("|   6. Salir                             |\n");
                printf("==========================================\n");

                mostrarResultado(x, y);

            };
    return 0;
}


int mostrarResultado(int x, int y){

   printf("El valor del 1er operando A=%d \n\n", x);
   printf("El valor del 2do operando B=%d \n\n", y);

   //suma
    printf("El resultado de A+B es: %d \n\n",suma(x,y));

   //resta
    printf("El resultado de A-B es: %d \n\n",resta(x,y));

   //division
    if(!(y==0)){
      printf("El resultado de A/B es: %.2f \n\n", dividir(x,y));
    }
    else{
       printf("No es posible dividir por cero\n\n");
    }

    //producto
      printf("El resultado de A*B es: %d\n\n", multiplicar(x,y));

    //factorial
       printf("El factorial de A es: %d y El factorial de B es: %d\n\n", factorial(x), factorial(y));

    return 0;
}

