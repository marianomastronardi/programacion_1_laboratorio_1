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

    do
    {
        system("cls");
        printf("\n*** Menu de Opciones ***\n\n");
        printf(" 1-  Alta de Cliente\n");
        printf(" 2-  Baja de Cliente\n");
        printf(" 3-  Modificacion de Cliente\n");
        printf(" 4-  Listar Clientes\n");
        printf(" 5-  Alta de Alquiler\n");
        printf(" 6-  Listar Alquileres\n");
        //SP
        printf(" 7-  Mostrar Juego X Categoria de Mesa\n");
        printf(" 8-  Mostrar Juegoa X Cliente\n");
        printf(" 9-  Mostrar Total Importe X Cliente\n");
        printf(" 10-  Mostrar Cliente que no alquilaron Juegos\n");

        printf(" 11-  Listar Juegos\n");
        printf(" 12-  Listar Categorias\n");

        printf(" 20- Salir\n\n");
        printf("\n Ingrese opcion: \n");
        scanf("%d", &opcion);

        if(opcion < 1 || opcion > 20)
        {
            printf("\nOpcion incorrecta\n");
        }
    }
    while(opcion < 1 || opcion > 20);
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

    do
    {
        system("cls");
        printf("\n*** Seleccione una Opcion ***\n\n");
        printf(" 1-  Nombre\n");
        printf(" 2-  Sexo\n");
        printf(" 3-  Telefono\n");
        printf("\n Ingrese opcion: \n");
        scanf("%d", &opcion);

        if(opcion < 1 || opcion > 3)
        {
            printf("\nOpcion incorrecta\n");
            system("pause");
            fflush(stdin);
        }
    }
    while(opcion < 1 || opcion > 3);
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
    int validar = rOK;

    do
    {
        printf("\nIngrese un Nombre\n\n");
        fflush(stdin);
        gets(vnombre);
        validar = validarNombre(vnombre);

    }
    while(validar == ERR);

    do
    {
        fflush(stdin);
        printf("\nIngrese el sexo\n\n");
        fflush(stdin);
        scanf("%c", &vsexo);
        cli.sexo = vsexo;
        validar = validarSexo(vsexo);

    }
    while(validar == ERR);

    do
    {
        fflush(stdin);
        printf("\nIngrese un Telefono\n\n");
        fflush(stdin);
        scanf("%s", vtelefono);
        strcpy(cli.Telefono,vtelefono);
        validar = validarTelefono(vtelefono);
    }
    while(validar == ERR);

    fflush(stdin);


    for(int i = 0; i < tam; i++)
    {
        if(vCliente[i].Codigo == 0)
        {
            cod = (tam + i);
            //cli.Codigo = cod;
            //vCliente[i] = cli;
            vCliente[i].Codigo = cod;
            strcpy(vCliente[i].Nombre, vnombre);
            vCliente[i].sexo = vsexo;
            strcpy(vCliente[i].Telefono, vtelefono);
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
    printf("\nIngrese un Codigo\n\n");
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

/** \brief verifica si hay alquileres en el vector
 *
 * \param vector alquiler
 * \param tamaño vector
 * \return ok or err
 *
 */

int hayAlquileres(eAlquileres vAlquiler[], int tam)
{
    int ret = ERR;

    for(int i = 0; i < tam; i++)
    {
        if(vAlquiler[i].CodigoAlquiler > 0)
        {
            ret = rOK;
        }
    }
    return ret;
}

/** \brief verifica si hay clientes en el cursor
 *
 * \param vector clientes
 * \param tamaño vector
 * \return ok si hay clientes, err si no hay
 *
 */

int hayClientes(eCliente vCliente[], int tam)
{
    int ret = ERR;

    for(int i = 0; i < tam; i++)
    {
        if(vCliente[i].Codigo > 0)
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
    int validar;
    int opc;

    opc = submenu();

    printf("\nIngrese un Codigo de Cliente\n");
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
                    do
                    {
                        fflush(stdin);
                        system("cls");
                        printf("\nIngrese un Nombre\n");
                        fflush(stdin);
                        //scanf("%s", sNombre);
                        gets(sNombre);
                        validar = validarNombre(sNombre);
                    }
                    while(validar == ERR);
                    fflush(stdin);
                    strcpy(vCliente[i].Nombre,sNombre);
                    ret = rOK;
                    break;
                case 2:
                    do
                    {
                        fflush(stdin);
                        printf("\nIngrese un sexo\n");
                        scanf("%c", &sSexo);
                        validar = validarSexo(sSexo);
                    }
                    while(validar == ERR);
                    vCliente[i].sexo = sSexo;
                    ret = rOK;
                    break;
                case 3:
                    do
                    {
                        fflush(stdin);
                        printf("\nIngrese un Telefono\n");
                        scanf("%s", sTelefono);
                        validar = validarTelefono(sTelefono);
                    }
                    while(validar == ERR);
                    strcpy(vCliente[i].Telefono,sTelefono);
                    ret = rOK;
                    break;
                }
            }
        }

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
            printf("%4d    %20s      %c        %s\n", vClientes[i].Codigo, vClientes[i].Nombre, vClientes[i].sexo, vClientes[i].Telefono);
        }
    }
}

/** \brief inicializa el vector de clientes
 *
 * \param vector clientes
 * \param tamaño del vector
 * \return nothing
 *
 */

void inicializarClientes(eCliente vCliente[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vCliente[i].Codigo = 0;
        strcpy(vCliente[i].Nombre,"");
        //vCliente[i].sexo = "";
        strcpy(vCliente[i].Telefono,"");
    }
}

void inicializarJuegos(eJuego vJuego[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vJuego[i].Codigo= 0;
        strcpy(vJuego[i].Descripcion,"");
        vJuego[i].idCategoria= 0;
        vJuego[i].Importe = 0;
    }
}

void inicializarCategoria(eCategoria vCategoria[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vCategoria[i].id= 0;
        strcpy(vCategoria[i].Descripcion,"");
    }
}
/** \brief ordena el vector de clientes
 *
 * \param vector clientes
 * \param tamaño vector
 * \return nothing
 *
 */

void ordenarClientes(eCliente vCliente[], int tam)
{
    //ordenar por sexo y nombre

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(vCliente[i].sexo > vCliente[j].sexo && vCliente[i].Codigo > 0 && vCliente[j].Codigo > 0)
            {
                eCliente aux;
                aux = vCliente[i];
                vCliente[i] = vCliente[j];
                vCliente[j] = aux;
            }
            else if(vCliente[i].sexo == vCliente[j].sexo  && strcmp(vCliente[i].Nombre,vCliente[j].Nombre) > 0 && vCliente[i].Codigo > 0 && vCliente[j].Codigo > 0)
            {
                eCliente aux;
                aux = vCliente[i];
                vCliente[i] = vCliente[j];
                vCliente[j] = aux;
            }
        }
    }
}

/** \brief da de alta un alquiler y lo almacena en el vector alquileres
 *
 * \param VECTOR alquileres
 * \param tamaño vector alquileres
 * \param vector juegos
 * \param tamaño vector juegos
 * \param vector clientes
 * \param tamaño vector clientes
 * \return OK or ERR
 *
 */

int altaAlquiler(eAlquileres vAlquiler[], int tam, eJuego vJuego[], int tamj, eCliente vCliente[], int tamc)
{
    //int codigoalquiler;
    //int codigojuego;
    //int codigocliente;
    int ret = rOK;
    eAlquileres unAlquiler;
    int existe = rOK;
    int hayclientesenvector;

    hayclientesenvector = hayClientes(vCliente, tamc);

    if(hayclientesenvector == rOK)
    {

        do
        {
            fflush(stdin);
            if(existe == ERR)
            {
                printf("\nCodigo de Juego incorrecto\n");
            }
            fflush(stdin);
            printf("\nIngrese el codigo del juego\n");
            fflush(stdin);
            scanf("%d", &unAlquiler.CodigoJuego);
            int cod = unAlquiler.CodigoJuego;
            existe = existeJuego(vJuego, tamj, cod);
        }
        while(existe == ERR);


        do
        {
            if(existe == ERR)
            {
                printf("\nCodigo de cliente incorrecto\n");
            }
            fflush(stdin);
            printf("\nIngrese el codigo del cliente\n");
            fflush(stdin);
            scanf("%d", &unAlquiler.CodigoCliente);
            int icli = unAlquiler.CodigoCliente;
            existe = existeCliente(vCliente, tamc, icli);
        }
        while(existe == ERR);


        printf("\nIngrese un dia\n");
        scanf("%d", &unAlquiler.fecha.dia);

        printf("\nIngrese un mes\n");
        scanf("%d", &unAlquiler.fecha.mes);

        printf("\nIngrese un año\n");
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
    else
    {
        ret = ERR;
    }
    return ret;
}

/** \brief muestra la lista del contenido del vector alquileres
 *
 * \param vector alquileres
 * \param tamaño vector alquiler
 * \return
 *
 */

void listarAlquileres(eAlquileres vAlquiler[], int tama, eCliente vCliente[], int tamcl, eJuego vJuego[], int tamj, eCategoria vCategoria[], int tamca)
{
    printf("\nCodAlquiler       Juego               Categoria               Cliente     Fecha\n");
    fflush(stdin);

    char desccategoria[51] = "";
    char descjuego[21] = "";
    char nombrecliente[51] = "";

    for(int i = 0; i < tama; i++)
    {
        if(vAlquiler[i].CodigoAlquiler > 0)
        {
            fflush(stdin);
            getJuego(vJuego, tamj, vAlquiler[i].CodigoJuego, descjuego);
            fflush(stdin);
            getCliente(vCliente, tamcl, vAlquiler[i].CodigoCliente, nombrecliente);
            fflush(stdin);
            getCategoria(vCategoria, tamca, vJuego, tamj, vAlquiler[i].CodigoJuego, desccategoria);

            printf("\n%4d %20s %20s %20s %d/%d/%d\n", vAlquiler[i].CodigoAlquiler, descjuego, desccategoria, nombrecliente, vAlquiler[i].fecha.dia, vAlquiler[i].fecha.mes, vAlquiler[i].fecha.anio);
        }
    }
}

/** \brief devuelve la descripcion del codigo del juego seleccionado
 *
 * \param vector juego
 * \param tamaño vector
 * \param codigo juego
 */

void getJuego(eJuego vJuego[], int tamj, int codj, char desc[])
{
    for(int i = 0; i < tamj; i++)
    {
        if(vJuego[i].Codigo == codj)
        {
            strcpy(desc, vJuego[i].Descripcion);
            break;
        }
    }
}

/** \brief devuelve la categoria del juego
 *
 * \param vector categoria
 * \param tamaño vector categoria
 * \param vector juego
 * \param tamaño vector juego
 * \param codigo juego
 *
 */

void getCategoria(eCategoria vCategoria[], int tamc, eJuego vJuego[], int tamj, int codj, char desc[])
{
    int flag = ERR;
    for(int i = 0; i < tamj; i++)
    {
        if(vJuego[i].Codigo == codj)
        {
            for(int j = 0; j < tamc; j++)
            {
                if(vCategoria[j].id == vJuego[i].idCategoria)
                {
                    strcpy(desc, vCategoria[j].Descripcion);
                    flag = rOK;
                    break;
                }
            }
            if(flag == rOK)
            {
                break;
            }
        }
    }
}

/** \brief devuelve el nombre del cliente
 *
 * \param vector cliente
 * \param tamaño vector cliente
 * \param codigo cliente
 *
 */

void getCliente(eCliente vCliente[], int tamc, int codcliente, char nombre[])
{
    for(int i = 0; i < tamc; i++)
    {
        if(vCliente[i].Codigo == codcliente)
        {
            strcpy(nombre, vCliente[i].Nombre);
        }
    }
}

/** \brief inicializa el vector de alquileres
 *
 * \param vector alquiler
 * \param tamaño vector alquiler
 * \return nothing
 *
 */

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

/** \brief verifica si existe el juego ingresado
 *
 * \param vector juegos
 * \param tamaño vector
 * \param codigo juego ingresado por el usuario
 * \return OK or ERR
 *
 */

int existeJuego(eJuego vJuego[], int tam, int cod)
{
    int ret = ERR;

    for(int i = 0; i < tam; i++)
    {
        if(vJuego[i].Codigo == cod)
        {
            ret = rOK;
        }
    }

    return ret;
}

/** \brief valida el tamaño del nombre
 *
 * \param string nombre
 * \param
 * \return OK or ERR
 *
 */

int validarNombre(char nombre[])
{
    int ret = rOK;

    if(strlen(nombre) > 50)
    {
        ret = ERR;
        printf("\nEl nombre es demasiado extenso\n");
    }
    return ret;
}

/** \brief valida si el sexo es valido
 *
 * \param sexo ingresado por el usuario
 * \param
 * \return OK or ERR
 *
 */

int validarSexo(char sexo)
{
    int ret = rOK;

    if(sexo != 'm' && sexo != 'f')
    {
        ret = ERR;
        printf("\nEl sexo es incorrecto\n");
    }
    return ret;
}

/** \brief valida que el telefono sea valido
 *
 * \param telefono ingresado por el usuario
 * \param
 * \return OK or ERR
 *
 */

int validarTelefono(char tel[])
{
    int ret = rOK;

    if(strlen(tel) > 20)
    {
        ret = ERR;
        printf("\nEl telefono es demasiado extenso\n");
    }
    return ret;
}

/** \brief devuelve el id de categoria segun el indice
 *
 * \param vector categoria
 * \param tamaño vector
 * \param indice a buscar
 * \return idcategori
 *
 */

int getIDCategoria(eCategoria vCategoria[], int tam, int indice)
{
    int id;

    for(int i = 0; i < tam; i++)
    {
        if(i == indice)
        {
            id = vCategoria[i].id;
        }
    }

    return id;
}

/** \brief harcode cargar vector juegos
 *
 * \param vector juegos
 * \param tamaño vector
 * \return nothing
 *
 */

void cargarJuegos(eJuego vJuego[], int tam, eCategoria vCategoria[], int tamc)
{
    eJuego sJuego[] =
    {
        {1, "Estanciero", 210.56, getIDCategoria(vCategoria, tamc, 0)},
        {2, "Generala", 311.77, getIDCategoria(vCategoria, tamc, 1)},
        {3, "TEG", 215.97, getIDCategoria(vCategoria, tamc, 2)},
        {4, "Mi salon", 877.12, getIDCategoria(vCategoria, tamc, 3)},
        {5, "Mi magia", 500.01, getIDCategoria(vCategoria, tamc, 4)}
    };

    for(int i = 0; i < tam; i++)
    {
        vJuego[i] = sJuego[i];
    }
}

/** \brief harcode categorias
 *
 * \param vector categorias
 * \param tamaño vector
 * \return nothing
 *
 */

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

    for(int i = 0; i < tam; i++)
    {
        vCategoria[i] = sCategoria[i];
    }
}

//SP

/** \brief mostrar los juegos por categoria
 *
 * \param vector juegos
 * \param tamaño vector
 * \param categoria seleccionada
 * \return void
 *
 */

void listarJuegosXCategoria(eJuego vJuego[], int tamj, int idCategoria)
{
    printf("\nCodigo    Descripcion     Importe\n");
    fflush(stdin);
    for(int i = 0; i < tamj; i++)
    {
        if(vJuego[i].idCategoria == idCategoria)
        {
            printf("%4d %21s %.2f", vJuego[i].Codigo, vJuego[i].Descripcion, vJuego[i].Importe);
            fflush(stdin);
        }
    }
}

/** \brief mostrar todos los alquileres de un cliente seleccionado
 *
 * \param vector alquiler
 * \param tamaño vector
 * \param id cliente seleccioado
 * \return void
 *
 */

void listarAlquilerXCliente(eAlquileres vAlquiler[], int tama, eCategoria vCategoria[], int tamca, eJuego vJuego[], int tamj, eCliente vCliente[], int tamcl, int idCliente)
{
    printf("\nCodAlquiler       Juego               Categoria               Cliente     Fecha\n");
    fflush(stdin);

    char desccategoria[51] = "";
    char descjuego[21] = "";
    char nombrecliente[51] = "";

    for(int i = 0; i < tama; i++)
    {
        if(vAlquiler[i].CodigoAlquiler > 0 && idCliente == vAlquiler[i].CodigoCliente)
        {
            fflush(stdin);
            getJuego(vJuego, tamj, vAlquiler[i].CodigoJuego, descjuego);
            fflush(stdin);
            getCliente(vCliente, tamcl, vAlquiler[i].CodigoCliente, nombrecliente);
            fflush(stdin);
            getCategoria(vCategoria, tamca, vJuego, tamj, vAlquiler[i].CodigoJuego, desccategoria);

            printf("\n%4d %20s %20s %20s %d/%d/%d\n", vAlquiler[i].CodigoAlquiler, descjuego, desccategoria, nombrecliente, vAlquiler[i].fecha.dia, vAlquiler[i].fecha.mes, vAlquiler[i].fecha.anio);
        }
    }
}

/** \brief muestra el total de todos los importes pagados por el cliente seleccionado
 *
 * \param vector juegos
 * \param tamaño vector juegos
 * \param vector alquiler
 * \param tamaño vector alquiler
 * \param id cliente seleccionado
 * \return void
 *
 */

void listarTotalImporteXCliente(eJuego vJuego[], int tamj, eAlquileres vAlquiler[], int tama, int idCliente)
{
    float suma = 0;

    for(int i = 0; i < tama; i++)
    {
        if(vAlquiler[i].CodigoCliente == idCliente)
        {
            for(int j = 0; j < tamj; j++)
            {
                if(vJuego[j].Codigo == vAlquiler[i].CodigoJuego)
                {
                    suma = (float) (suma + vJuego[j].Importe);
                }
            }
        }
    }

    printf("\nImporte Total: %.2f\n", suma);
}

/** \brief muestra los clientes sin alquileres
 *
 * \param vector alquiler
 * \param tamaño vector alquiler
 * \param vector cliente
 * \param tamaño vector cliente
 * \return void
 *
 */

void listarClientesSinAlquileres(eAlquileres vAlquiler[], int tama, eCliente vCliente[], int tamcl)
{
    eCliente sCliente;
    printf("\nCodigo    Nombre      Sexo    Telefono\n");

    for(int i = 0; i < tamcl; i++)
    {
        if(vCliente[i].Codigo > 0)
        {
            sCliente = initCliente();

            for(int j = 0; j < tama; j++)
            {
                if(vAlquiler[j].CodigoCliente == vCliente[i].Codigo)
                {
                   sCliente = vCliente[i];
                   //printf("%d", vCliente[i].Codigo);
                   //break;
                }
            }

            if(sCliente.Codigo == 0)
            {
                sCliente = vCliente[i];
                //printf("%d", sCliente.Codigo);
                printCliente(sCliente);
            }

        }
    }
}

/** \brief imprime un cliente
 *
 * \param struct cliente
 * \return void
 *
 */

void printCliente(eCliente sCliente)
{
    printf("\n%4d  %20s   %c      %20s\n", sCliente.Codigo, sCliente.Nombre, sCliente.sexo, sCliente.Telefono);
}

/** \brief inicializa struct cliente
 *
 * \param struct cliente
 * \return void
 *
 */

eCliente initCliente(void)
{
    eCliente sCliente;
    sCliente.Codigo = 0;
    strcpy(sCliente.Nombre, "");
    strcpy(sCliente.Telefono, "");

    return sCliente;
}

/** \brief pide un cliente al usuario
 *
 * \param vector cliente
 * \param tamaño vector
 * \return id cliente
 *
 */

int askCliente(eCliente vCliente[], int tamc)
{
    int existe = ERR;
    int c;
    do
    {
        system("cls");
        printf("\nIngrese un id de cliente\n");
        scanf("%d", &c);
        existe = existeCliente(vCliente, tamc, c);
    }
    while(existe == ERR);
    //printf("ask cliente");
    return c;
}

void listarJuegos(eJuego vJuego[], int tamj, eCategoria vCategoria[], int tamc)
{
    eCategoria sCategoria;
    printf("\nCodigo    Descripcion     Importe    idCategoria \n");
    fflush(stdin);

    for(int i = 0; i < tamj; i++)
    {
        for(int j = 0; j < tamc; j++)
        {
            if(vJuego[i].idCategoria == vCategoria[j].id)
            {
                sCategoria = vCategoria[j];
            }
        }
        printf("\%4d  %20s  %.2f %20s\n", vJuego[i].Codigo, vJuego[i].Descripcion, vJuego[i].Importe, sCategoria.Descripcion);
    }
}

void listarCategoria(eCategoria vCategoria[], int tamc)
{
    printf("\nID    Descripcion \n");
    fflush(stdin);

    for(int i = 0; i < tamc; i++)
    {
        printf("\%4d  %20s \n", vCategoria[i].id, vCategoria[i].Descripcion);
    }
}

void getJuegosNoAlquilados(eAlquileres vAlquiler[], int tama, eJuego vJuego[], int tamj)
{
    eJuego sJuego;
    printf("\nCodigo    Nombre      Sexo    Telefono\n");

    for(int i = 0; i < tama; i++)
    {
        if(vAlquiler[i].CodigoAlquiler > 0)
        {
            sJuego = initJuego();

            for(int j = 0; j < tamj; j++)
            {
                if(vAlquiler[i].CodigoJuego == vJuego[j].Codigo)
                {
                   sJuego = vJuego[i];
                   //printf("%d", vCliente[i].Codigo);
                   //break;
                }
            }

            if(sJuego.Codigo == 0)
            {
                sJuego = vJuego[i];
                //printf("%d", sCliente.Codigo);
                printCliente(sJuego);
            }

        }
    }
}



eJuego initJuego(void)
{
    eJuego sJuego;
    sJuego.Codigo = 0;
    strcpy(sJuego.Descripcion, "");
    sJuego.idCategoria = 0;
    sJuego.Importe = 0;
}
