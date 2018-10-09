#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define rOK 0
#define ERR 1

/** \brief muestra el menu de opciones
 *
 * \return opcion seleccionada por el usuario
 *
 */

int menu()
{
    int opcion;

    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1-  Alta de Cliente\n");
    printf(" 2-  Baja de Cliente\n");
    printf(" 3-  Modificacion de Cliente\n");
    printf(" 4-  Listar Clientes\n");
    printf(" 5-  Alta de Alquiler\n");
    printf(" 6-  Listar Alquileres\n");
    printf(" 7- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief menu de opciones de la modificacion
 *
 * \return  opcion
 *
 */

int submenu()
{
    int opcion;

    system("cls");
    printf("\n*** Seleccione una Opcion ***\n\n");
    printf(" 1-  Nombre\n");
    printf(" 2-  Sexo\n");
    printf(" 3-  Telefono\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief de alta un cliente siempre q su codigo sea 0
 *
 * \param vector clientes
 * \param tamaño
 * \return OK or ERR
 *
 */

int altaCliente(eCliente vCliente[], int tam)
{
    int ret = ERR;
    eCliente cli;
    char vnombre[51];
    char vsexo;
    char vtelefono[21];
    int cod;

    printf("Ingrese un Nombre\n\n");
    fflush(stdin);
    gets(vnombre);
    //scanf("%s", vnombre);
    //strcpy(cli.Nombre,vnombre);

    fflush(stdin);
    printf("Ingrese el sexo\n\n");
    fflush(stdin);
    scanf("%c", &vsexo);
    cli.sexo = vsexo;

    fflush(stdin);
    printf("Ingrese un Telefono\n\n");
    fflush(stdin);
    scanf("%s", vtelefono);
    strcpy(cli.Telefono,vtelefono);

    fflush(stdin);


    for(int i = 0; i < tam; i++)
    {
        if(vCliente[i].Codigo == 0){
            cod = (tam + i);
            //cli.Codigo = cod;
            //vCliente[i] = cli;
            vCliente[i].Codigo = cod;
            strcpy(vCliente[i].Nombre , vnombre);
            vCliente[i].sexo = vsexo;
            strcpy(vCliente[i].Telefono , vtelefono);
            ret = rOK;
            break;
        }
    }
    return ret;
}


/** \brief baja logica del cliente
 *
 * \param vector clientes
 * \param tamaño
 * \return OK or ERR
 *
 */

int bajaCliente(eCliente vCliente[], int tam)
{
    int ret = ERR;
    int cod;
    int existe;
    printf("Ingrese un Codigo\n\n");
    scanf("%d", &cod);
    existe = existeCliente(vCliente, tam, cod);
    if(existe == rOK)
    {
        for(int i = 0; i < tam; i++)
    {
        if(vCliente[i].Codigo == cod)
        {
            ret = rOK;
            vCliente[i].Codigo = 0;
            break;
        }
    }
    }
    return ret;
}

/** \brief retorna si existe el empleado
 *
 * \param vcctor cliente
 * \param tamaño
 * \param codigo
 * \return OK or ERR
 *
 */

int existeCliente(eCliente vCliente[], int tam, int codigo)
{
    int ret = ERR;

    for(int i = 0; i < tam; i++)
    {
        if(vCliente[i].Codigo == codigo)
        {
            ret = rOK;
            break;
        }
    }

    return ret;
}


/** \brief modifica un campo del cliente
 *
 * \param vector cliente
 * \param  tamaño del vector
 * \return opcion seleccionada por el usuario
 *
 */

int modificarCliente(eCliente vCliente[], int tam)
{
    int ret = ERR;
    int codigocliente;
    char sNombre[51];
    char sSexo;
    char sTelefono[21];
    int existe;

    int opc;

    opc = submenu();

    printf("Ingrese un Codigo de Cliente\n");
    scanf("%d", &codigocliente);

    existe = existeCliente(vCliente, tam, codigocliente);

    if(existe == rOK)
    {

        for(int i = 0; i < tam; i++)
        {
            if(vCliente[i].Codigo == codigocliente)
            {
                switch(opc)
                    {
                    case 1:
                        printf("Ingrese un Nombre\n");
                        scanf("%s", sNombre);
                        strcpy(vCliente[i].Nombre,sNombre);
                        ret = rOK;
                        break;
                    case 2:
                        printf("Ingrese un sexo\n");
                        scanf("%c", &sSexo);
                        vCliente[i].sexo = sSexo;
                        ret = rOK;
                        break;
                    case 3:
                        printf("Ingrese un Telefono\n");
                        scanf("%s", sTelefono);
                        strcpy(vCliente[i].Telefono,sTelefono);
                        ret = rOK;
                        break;
                    }
            }
        }

    }
    else
    {
        printf("No existe el cliente");
    }
    return ret;
}


/** \brief mostrar la lista de clientes
 *
 * \param vector clientes
 * \param tamaño del vector
 *
 */

void listarClientes(eCliente vClientes[], int tam)
{
    ordenarClientes(vClientes, tam);

    printf("\nCodigo    Nombre      Sexo        Telefono\n");

    for(int i = 0; i < tam; i++)
    {
        fflush(stdin);
        if(vClientes[i].Codigo != 0)
        {
         printf("%4d    %s      %c        %s\n", vClientes[i].Codigo, vClientes[i].Nombre, vClientes[i].sexo, vClientes[i].Telefono);
        }
    }
}

void inicializarClientes(eCliente vCliente[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vCliente[i].Codigo = 0;
        strcpy(vCliente[i].Nombre,"");
        vCliente[i].sexo = "";
        strcpy(vCliente[i].Telefono,"");
    }
}

void ordenarClientes(eCliente vCliente[], int tam)
{
    //ordenar por sexo y nombre

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(vCliente[i].sexo > vCliente[j].sexo)
            {
                eCliente aux;
                aux = vCliente[i];
                vCliente[i] = vCliente[j];
                vCliente[j] = aux;
            }
            else if(vCliente[i].sexo == vCliente[j].sexo  && strcmp(vCliente[i].Nombre,vCliente[j].Nombre) > 0)
            {
                eCliente aux;
                aux = vCliente[i];
                vCliente[i] = vCliente[j];
                vCliente[j] = aux;
            }
        }
    }
}

void altaAlquiler(eAlquileres vAlquiler[], int tam)
{
    int codigoalquiler;
    int codigojuego;
    int codigocliente;
    eAlquileres unAlquiler;
    printf("Ingrese el codigo del juego\n");
    scanf("%d", &unAlquiler.CodigoJuego);

    printf("Ingrese el codigo del cliente\n");
    scanf("%d", &unAlquiler.CodigoCliente);

    printf("Ingrese un dia\n");
    scanf("%d", &unAlquiler.fecha.dia);

    printf("Ingrese un mes\n");
    scanf("%d", &unAlquiler.fecha.mes);

    printf("Ingrese un año\n");
    scanf("%d", &unAlquiler.fecha.anio);

    for(int i = 0; i < tam; i++)
    {
        if(vAlquiler[i].CodigoAlquiler == 0)
        {
            unAlquiler.CodigoAlquiler = tam + i;
            vAlquiler[i] = unAlquiler;
            break;
        }
    }
}

void listarAlquileres(eAlquileres vAlquiler[], int tam)
{
    printf("\nCodigoAlquiler    CodigoJuego     CodigoCliente       Fecha\n");
    fflush(stdin);

    for(int i = 0; i < tam; i++)
    {
        if(vAlquiler[i].CodigoAlquiler > 0)
        {
           printf("\n%d    %d     %d       %d%d%d\n", vAlquiler[i].CodigoAlquiler, vAlquiler[i].CodigoJuego, vAlquiler[i].CodigoCliente, vAlquiler[i].fecha.dia, vAlquiler[i].fecha.mes, vAlquiler[i].fecha.anio);
        }
    }
}

void inicializarAlquileres(eAlquileres vAlquiler[], int tam)
{
    eFecha dFecha;
    dFecha.dia = 1;
    dFecha.mes = 1;
    dFecha.anio = 1900;
    for(int i = 0; i < tam; i++)
    {
        vAlquiler[i].CodigoAlquiler = 0;
        vAlquiler[i].CodigoCliente = 0;
        vAlquiler[i].CodigoJuego = 0;
        vAlquiler[i].fecha = dFecha;
    }
}

