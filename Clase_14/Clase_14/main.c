#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char marca[20];
    int capacidad;
    float precio;
} ePenDrive;

int cargarPenDrive(ePenDrive* pen);
void mostrarPenDrive(ePenDrive* pen);

int main()
{
    ePenDrive pen;

    if(cargarPenDrive(&pen) == 0)
    {
       mostrarPenDrive(&pen);
    }


    return 0;
}

int cargarPenDrive(ePenDrive* pen)
{
    int ret = -1;

    if(pen != NULL)
    {
        printf("\nIngrese un codigo: \n");
        scanf("%d", &pen->codigo);

        printf("\nIngrese una marca: \n");
        fflush(stdin);
        gets(pen->marca);

        printf("\nIngrese una capacidad: \n");
        scanf("%d", &pen->capacidad);

        printf("\nIngrese un precio: \n");
        scanf("%f", &pen->precio);

        ret = 0;
    }

    return ret;
};


void mostrarPenDrive(ePenDrive* pen)
{
    printf("\nCodigo            Marca       Capacidad[GB]   Precio\n");
    printf("\n-----------------------------------------------------\n");
    printf("%4d     %20s    %4d     %.2f\n", pen->codigo, pen->marca, pen->capacidad, pen->precio);
}

