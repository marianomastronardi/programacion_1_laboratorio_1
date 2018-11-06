#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 5

typedef struct
{
    int id;
    char nombre[20];
} eCategoria;

typedef struct
{
    int id;
    char nombre[20];
    int idCategoria;
} eJuego;

void initCategoria(eCategoria vCategoria[], int tam);
void initJuego(eJuego vJuego[], int tam);
void mostrarCategorias(eCategoria vCat[], int tamc);
void pedirCategotriayMostrarJuegos(eCategoria vCat[], int tamc, eJuego vJuego[], int tamj);
void mostrarJuegosMesa(eCategoria vCat[], int tamc, eJuego vJuego[], int tamj);
void mostrarTodosLosJuegos(eCategoria vCat[], int tamc, eJuego vJuego[], int tamj);
int mostrarmenu();

int main()
{
    eCategoria vCateg[TAM];
    eJuego vJuego[TAM];
    int opcion;

    initCategoria(vCateg, TAM);
    initJuego(vJuego, TAM);


    do
    {
        opcion = mostrarmenu();

        switch(opcion)
        {
        case 1:
            pedirCategotriayMostrarJuegos(vCateg, TAM, vJuego, TAM);
            break;
        case 2:
            mostrarJuegosMesa(vCateg, TAM, vJuego, TAM);
            break;
        case 3:
            mostrarTodosLosJuegos(vCateg, TAM, vJuego, TAM);
            break;
        case 4:
            exit(1);
            break;
        }
        system("pause");
    }while(opcion != 4);

    return 0;
}

void initCategoria(eCategoria vCategoria[], int tam)
{
    eCategoria vCat[] =
    {
        {1, "Mesa"},
        {2, "Estrategia"},
        {3, "Infantil"},
        {4, "Azar"},
        {5, "Ingenio"}
    };

    for(int i=0; i < tam; i++)
    {
        vCategoria[i] = vCat[i];
    }
}

void initJuego(eJuego vJuego[], int tam)
{
    eJuego vJuegos[] =
    {
        {1, "El Juego de la vida", 1},
        {2, "TEG", 2},
        {3, "Operacion", 3},
        {4, "Generala", 4},
        {5, "Memotest", 1}
    };

    for(int i=0; i < tam; i++)
    {
        vJuego[i] = vJuegos[i];
    }
}

void mostrarCategorias(eCategoria vCat[], int tamc)
{
    printf("\n---------CATEGORIAS-------\n");
    printf("\nID             Descripcion\n");

    for(int i=0; i < tamc; i++)
    {
        printf("%4d %20s\n", vCat[i].id, vCat[i].nombre);
    }
}

void pedirCategotriayMostrarJuegos(eCategoria vCat[], int tamc, eJuego vJuego[], int tamj)
{
    int cat;
    int flagExisteCat = 0;
    int flagExisteJuego = 0;

    mostrarCategorias(vCat, tamc);

    fflush(stdin);
    printf("\nElija un ID de Categoria ");
    scanf("%d", &cat);

    for(int i=0; i < tamc; i++)
    {
        if(vCat[i].id == cat)
        {
            flagExisteCat = 1;
            fflush(stdin);

            for(int j = 0; j < tamj; j++)
            {
                if(vJuego[j].idCategoria == cat)
                {
                    fflush(stdin);
                    if(flagExisteJuego == 0)
                    {
                        printf("\n--------------------JUEGOS---------------------\n");
                        printf("\nID            Descripcion             Categoria\n");
                    }
                    flagExisteJuego = 1;
                    printf("%4d %20s %20s\n", vJuego[j].id, vJuego[j].nombre, vCat[i].nombre);
                }
            }

            if(flagExisteJuego == 0)
            {
                printf("No existen Juegos para la Categoria %s\n", vCat[i].nombre);
            }
        }
    }

    if(flagExisteCat == 0)
    {
        printf("No existen Catogorias con el ID %d\n", cat);
    }
}

void mostrarJuegosMesa(eCategoria vCat[], int tamc, eJuego vJuego[], int tamj)
{
    int flagExisteCat = 0;
    int flagExisteJuego = 0;

    mostrarCategorias(vCat, tamc);

    for(int i=0; i < tamc; i++)
    {
        if(strcmp(vCat[i].nombre, "Mesa") == 0)
        {
            flagExisteCat = 1;
            fflush(stdin);

            for(int j = 0; j < tamj; j++)
            {
                if(vJuego[j].idCategoria == vCat[i].id)
                {
                    fflush(stdin);
                    if(flagExisteJuego == 0)
                    {
                        printf("\n---------------------JUEGOS--------------------\n");
                        printf("\n ID           Descripcion             Categoria\n");
                    }
                    flagExisteJuego = 1;
                    printf("%4d %20s %20s\n", vJuego[j].id, vJuego[j].nombre, vCat[i].nombre);
                }
            }

            if(flagExisteJuego == 0)
            {
                printf("No existen Juegos para la Categoria %s\n", vCat[i].nombre);
            }
        }
    }

    if(flagExisteCat == 0)
    {
        printf("No existen Catogorias de mesa\n");
    }
}

void mostrarTodosLosJuegos(eCategoria vCat[], int tamc, eJuego vJuego[], int tamj)
{
    printf("\n---------------------JUEGOS--------------------\n");
    printf("\n ID         Descripcion               Categoria\n");

    for(int i = 0; i < tamj; i++)
    {
        for(int j = 0; j < tamc; j++)
        {
            if(vCat[j].id == vJuego[i].idCategoria)
            {
                fflush(stdin);
                printf("%4d %20s %20s\n", vJuego[i].id, vJuego[i].nombre, vCat[j].nombre);
            }
        }
    }
}

int mostrarmenu()
{
    int opcion;

    do
    {
        system("cls");
        printf("\n*******************MENU******************\n");
        printf("1. Pedir una Categoria y mostrar Juegos\n");
        printf("2. Mostrar solo Juegos de Mesa\n");
        printf("3. Mostrar todos los Juegos\n");
        printf("4. Salir\n");
        printf("\n*****************************************\n");
        printf("\nElija una opcion ");
        scanf("%d", &opcion);
    }
    while(opcion < 1 || opcion > 4);

    return opcion;
}
