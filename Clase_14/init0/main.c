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

ePenDrive* new_pendrive();
ePenDrive* new_pendrive_param(int cod, char marca[20], int cap, float price);
void mostrarPenDrive(ePenDrive* pen);

int main()
{
    ePenDrive* pen1, *pen2;

    pen1 = new_pendrive();
    pen2 = new_pendrive_param(1, "Kingston", 8, 456.12);

    mostrarPenDrive(pen1);
    mostrarPenDrive(pen2);

    return 0;
}

ePenDrive* new_pendrive()
{
    ePenDrive* p;
    p = (ePenDrive*) malloc(sizeof(ePenDrive));

    if(p != NULL)
    {
       p->capacidad = 0;
       p->codigo = 0;
       p->precio = 0;
       fflush(stdin);
       strcpy(p->marca, "");
    }

    return p;
}

void mostrarPenDrive(ePenDrive* pen)
{
    printf("\nCodigo            Marca       Capacidad[GB]   Precio\n");
    printf("\n-----------------------------------------------------\n");
    printf("%4d     %20s    %4d     %.2f\n", pen->codigo, pen->marca, pen->capacidad, pen->precio);
}

ePenDrive* new_pendrive_param(int cod, char marca[20], int cap, float price)
{
    ePenDrive* p;
    p = (ePenDrive*) malloc(sizeof(ePenDrive));

    if(p != NULL)
    {
       p->capacidad = cap;
       p->codigo = cod;
       p->precio = price;
       fflush(stdin);
       strcpy(p->marca, marca);
    }

    return p;
}
