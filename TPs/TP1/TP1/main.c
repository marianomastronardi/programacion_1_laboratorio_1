#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"
#include "Validador.h"

int main()
{
    int x=0;
    int y=0;
    char a[20];
    int option;
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
           do{
            printf("==========================================\n");
            printf("==          Elija una opcion            ==\n");
            printf("==========================================\n");
            printf("|   1. Suma                              |\n");
            printf("|   2. Resta                             |\n");
            printf("|   3. Dividion                          |\n");
            printf("|   4. Multiplicacion                    |\n");
            printf("|   5. Factorial                         |\n");
            printf("|   6. Salir                             |\n");
            printf("==========================================\n");
            scanf("%d", &option);
            //mostrarResultado(option, x, y);

            printf("El valor del 1er operando A=%d \n\n", x);
            printf("El valor del 2do operando B=%d \n\n", y);

            switch(option){
            case 1:
                //suma
                printf("El resultado de A+B es: %d \n\n",suma(x,y));
                break;
            case 2:
                //resta
                printf("El resultado de A-B es: %d \n\n",resta(x,y));
                break;
            case 3:
                //division
                  if(!(y==0)){
                    printf("El resultado de A/B es: %.2f \n\n", dividir(x,y));
                  }
                  else{
                    printf("No es posible dividir por cero\n\n");
                  };
                  break;
            case 4:
                //producto
                printf("El resultado de A*B es: %d\n\n", multiplicar(x,y));
                break;
            case 5:
                //factorial
                printf("El factorial de A es: %d y El factorial de B es: %d\n\n", factorial(x), factorial(y));
                break;
            case 6:
                //salir
                return 0;
                break;
            default:
                printf("Seleccione una opcion correcta");
                break;
            };

            }while(option < 1 || option > 6);

            };
    return 0;
}

/*
void mostrarResultado(int option, int x, int y){

};
*/
