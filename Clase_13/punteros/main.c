#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct{
int dia;
int mes;
int anio;
} eFecha;

typedef struct{
int legajo;
char nombre[20];
float sueldo;
eFecha Fecha;
}eEmpleado;

void miFuncion(int*);
void altaEmpleado(eEmpleado*);
void printEmpleado(eEmpleado*);

int main()
{
    /*
    int vector[TAM];

    for(int i = 0; i < TAM; i++)
    {
      printf("\nIngrese un numero: ");
      scanf("%d", vector + i);
    }

    for(int i = 0; i < TAM; i++)
    {
       printf("%d ", *(vector + i));
    }

    printf("\n\n");
*/
    return 0;
}

void miFuncion(int* x)
{
    *x = 38;
}

void altaEmpleado(eEmpleado* pEmpleado)
{
    char cNombre[20];
    printf("\nIngrese el legajo: ");
    scanf("%d", &pEmpleado->legajo);
    printf("\nIngrese el nombre: ");
    scanf("%s", cNombre);
    strcpy(pEmpleado->nombre, cNombre);
    printf("\nIngrese el sueldo: ");
    scanf("%d", &pEmpleado->sueldo);
    printf("\nIngrese el dia: ");
    scanf("%d", &pEmpleado->Fecha.dia);
    printf("\nIngrese el mes: ");
    scanf("%d", &pEmpleado->Fecha.mes);
    printf("\nIngrese el anio: ");
    scanf("%d", &pEmpleado->Fecha.anio);
}

void printEmpleado(eEmpleado* pEmpleado)
{

}
