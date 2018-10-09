#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 5

void cargarJuegos(eJuego vJuego[], int tam);
void cargarCategorias(eCategoria vCategoria[], int tam);

int main()
{
    int opc;
    char resp = 's';
    eJuego vJuego[TAM];
    eCategoria vCategoria[TAM];
    eCliente vCliente[TAM];
    eAlquileres vAlquiler[TAM];

    cargarJuegos(vJuego, TAM);
    cargarCategorias(vCategoria, TAM);
    inicializarClientes(vCliente, TAM);
    inicializarAlquileres(vAlquiler, TAM);
    do
    {
        opc = menu();

        switch(opc)
        {
        case 1:
            altaCliente(vCliente, TAM);
            break;
        case 2:
            bajaCliente(vCliente, TAM);
            break;
        case 3:
            modificarCliente(vCliente, TAM);
            break;
        case 4:
            listarClientes(vCliente, TAM);
            break;
        case 5:
            altaAlquiler(vAlquiler, TAM);
            break;
        case 6:
            listarAlquileres(vAlquiler, TAM);
            break;
        default:
            break;
        }

        fflush(stdin);
        printf("Desea continuar? [s/n]\n");
        scanf("%c", &resp);
    }
    while(resp == 's');
    return 0;
}

void cargarJuegos(eJuego vJuego[], int tam)
{
    eJuego sJuego[] =
    {
        {1, "Estanciero", 210.56, 101},
        {2, "Generala", 311.77, 102},
        {3, "TEG", 215.97, 103},
        {4, "Mi salon", 877.12, 104},
        {5, "Mi magia", 500.01, 105}
    };

    for(int i = 0; i < tam; i++)
    {
        vJuego[i] = sJuego[i];
    }
}

void cargarCategorias(eCategoria vCategoria[], int tam)
{
    eCategoria sCategoria[] =
    {
        {101, "mesa"},
        {102, "azar"},
        {103, "estrategia"},
        {104, "salon"},
        {105, "magia"}
    };
}
