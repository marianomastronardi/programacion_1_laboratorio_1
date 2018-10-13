#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 5
#define rOK 0
#define ERR 1

int main()
{
    int opc;
    char resp = 's';
    int ret;
    int idcliente;
    eJuego vJuego[TAM];
    eCategoria vCategoria[TAM];
    eCliente vCliente[TAM];
    eAlquileres vAlquiler[TAM];

    inicializarJuegos(vJuego, TAM);
    inicializarCategoria(vCategoria, TAM);
    cargarCategorias(vCategoria, TAM);
    cargarJuegos(vJuego, TAM, vCategoria, TAM);
    inicializarClientes(vCliente, TAM);
    inicializarAlquileres(vAlquiler, TAM);
    do
    {
        opc = menu();

        switch(opc)
        {
        case 1:
            ret = altaCliente(vCliente, TAM);

            if(ret == ERR)
            {
                printf("\nNo hay espacio para dar de alta clientes\n");
            }
            break;
        case 2:
            ret = hayClientes(vCliente, TAM);
            if(ret == rOK)
            {

                ret = bajaCliente(vCliente, TAM);
                if(ret == ERR)
                {
                    printf("\nNo existe el cliente ingresado\n");
                }

            }
            else
            {
                printf("\n No hay clientes para dar de baja\n");
            }
            break;
        case 3:
            ret = hayClientes(vCliente, TAM);
            if(ret == rOK)
            {
                ret = modificarCliente(vCliente, TAM);
                if(ret == ERR)
                {
                    printf("\nNo existe el cliente ingresado\n");
                }
            }
            else
            {
                printf("\nNo hay clientes para modificar\n");
            }
            break;
        case 4:
            ret = hayClientes(vCliente, TAM);
            if(ret == rOK)
            {
                listarClientes(vCliente, TAM);
            }
            else
            {
                printf("\nNo hay Clientes para listar\n");
            }
            break;
        case 5:
            ret = altaAlquiler(vAlquiler, TAM, vJuego, TAM, vCliente, TAM);
            if(ret == ERR)
            {
                printf("\nNo hay clientes dados de alta.\n");
            }
            break;
        case 6:
            ret = hayAlquileres(vAlquiler, TAM);
            if(ret == rOK)
            {
                listarAlquileres(vAlquiler, TAM, vCliente, TAM, vJuego, TAM, vCategoria, TAM);
            }
            else
            {
                printf("\nNo hay alquileres para listar\n");
            }
            break;
        case 7:
            listarJuegosXCategoria(vJuego,TAM, 101);
            break;
        case 8:
            idcliente = askCliente(vCliente, TAM);
            listarAlquilerXCliente(vAlquiler, TAM, vCategoria, TAM, vJuego, TAM, vCliente, TAM, idcliente);
            break;
        case 9:
            idcliente = askCliente(vCliente, TAM);
            listarTotalImporteXCliente(vJuego, TAM, vAlquiler, TAM, idcliente);
            break;
        case 10:
            listarClientesSinAlquileres(vAlquiler, TAM, vCliente, TAM);
            break;
        case 11:
            listarJuegos(vJuego, TAM, vCategoria, TAM);
            break;
        case 12:
            listarCategoria(vCategoria, TAM);
            break;
        case 20:
            exit(0);
            break;
        default:
            break;
        }

        do
        {
            fflush(stdin);
            printf("\nDesea continuar? [s/n]\n");
            scanf("%c", &resp);
        }
        while(resp != 's' && resp != 'n');
    }
    while(resp == 's');
    return 0;
}




