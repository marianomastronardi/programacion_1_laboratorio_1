#include <stdio.h>
#include <stdlib.h>

int main()
{
     int* puntero;
    int* aux;

    puntero = (int*) malloc(sizeof(int) * 5);

    for(int i = 0; i < 5; i++)
    {
        printf("\nIngrese un numero ");
        scanf("%d", puntero + i);
    };

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", *(puntero +  i));
    };

    //reasigno espacio
    aux = (int*) realloc(puntero, sizeof(int) * 10);

    if(aux != NULL)
    {
        puntero = aux;

        for(int i = 5; i < 10; i++)
        {
            printf("\nIngrese un numero ");
            scanf("%d", puntero + i);
        };

        for(int i = 5; i < 10; i++)
        {
            printf("%d ", *(puntero +  i));
        };

    }
    else
    {
        printf("\nNo hay espacio");
    }

    printf("\nReasigno espacio\n\n");

    puntero = (int*) realloc(puntero, sizeof(int) * 3);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", *(puntero +  i));
    };

    free(puntero);
    return 0;
}
