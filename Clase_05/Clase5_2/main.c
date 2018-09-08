#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void mostrarValoresVector(int v[], int tam);
void inicializarVector(int v[], int tam);
int getMayor(int v[], int tam);
void sortVector(int v[], int tam);

int main()
{
    int vec[SIZE];
    int valor;
    int index;
    char res = 's';

    inicializarVector(vec, SIZE);

    do
    {
        printf("Ingrese un valor\n");
        scanf("%d",&valor);

        printf("Ingrese un indice de 0 a 4\n");
        scanf("%d",&index);

        vec[index] = valor;

        fflush(stdin);
        printf("Desea continuar [s/n]? \n");
        scanf("%c",&res);
    }
    while(res=='s');

    mostrarValoresVector(vec, SIZE);

    printf("El maximo valor del vector es %d\n\n", getMayor(vec,SIZE));

    printf("Los valores ordenados del vector son: \n\n");
    sortVector(vec,SIZE);

    mostrarValoresVector(vec,SIZE);

    return 0;
}

void mostrarValoresVector(int v[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("Indice %d - Valor %d\n\n", i, v[i]);
    }
}

void inicializarVector(int v[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        v[i] = 0;
    }
}

int getMayor(int v[], int tam)
{

    int mayor;

    for(int i = 0; i < tam; i++)
    {
        if(i == 0)
        {
            mayor = v[i];
        }
        else
        {
            if(v[i] > mayor)
            {
                mayor = v[i];
            }
        }
    }

    return mayor;
}

void sortVector(int v[], int tam)
{

    int aux;

    for(int i = 0; i < tam - 1; i++)
    {
        if(i != 0)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(v[i]<v[j])
                {
                    aux=v[j];
                    v[j] = v[i];
                    v[i] = aux;
                }
            }
        }
    }
}

