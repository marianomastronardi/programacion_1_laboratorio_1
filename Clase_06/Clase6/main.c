#include <stdio.h>
#include <stdlib.h>
void mostrarArrayLetras(char letras[], int tam);
void mostrarArrayNumeros(int numeros[], int tam);
void ordenarNumeros(int numeros[], int tam, int sort);
void SortByASCII(char letras[], int tam, int sort);

int main()
{
    char letras[] = {'d','c','a','f','A','C','b','Z'};
    int numeros[] = {100,55,48,0,-1,5,46,12};

    mostrarArrayLetras(letras, 8);
    mostrarArrayNumeros(numeros, 8);
    ordenarNumeros(numeros, 8, 0);
    SortByASCII(letras,8, 0);
    mostrarArrayLetras(letras, 8);
    mostrarArrayNumeros(numeros, 8);
    return 0;
}

/** \brief muestra un array char
 *
 * \param array
 * \param tamaño
 * \return void
 *
 */

void mostrarArrayLetras(char letras[], int tam)
{

    for(int i = 0; i < tam; i++)
    {
        printf("Indice %d - Valor %c\n",i,letras[i]);
    }
    printf("\n\n");
    fflush(stdin);
}

/** \brief muestra el contenido de un array de tipo int
 *
 * \param array
 * \param tamaño
 * \return void
 *
 */

void mostrarArrayNumeros(int numeros[], int tam)
{

    for(int i = 0; i < tam; i++)
    {
        printf("Indice %d - Valor %d\n",i,numeros[i]);
    }
    printf("\n\n");
    fflush(stdin);
}

/** \brief ordena los numeros de un array en forma ASC o DESC
 *
 * \param array
 * \param tamaño
 * \param 0 = ASC, 1 = DESC
 * \return void
 *
 */

void ordenarNumeros(int numeros[], int tam, int sort)
{
    int aux;
    for(int i = 0; i < tam; i++)
    {
        for(int j = i + 1; j  <= tam; j++)
        {
            if(sort==0)
            {
                if(numeros[j] < numeros[i])
                {
                    aux = numeros[i];
                    numeros[i] = numeros[j];
                    numeros[j] = aux;
                }
            }
            else
            {
                if(numeros[j] > numeros[i])
                {
                    aux = numeros[i];
                    numeros[i] = numeros[j];
                    numeros[j] = aux;
                }
            }

        }
    }
    fflush(stdin);
}

/** \brief ordena los caracteres de un array en forma ASC o DESC
 *
 * \param array
 * \param tamaño
 * \param 0 = ASC, 1 = DESC
 * \return void
 *
 */

void SortByASCII(char letras[], int tam, int sort)
{
    char aux;
    for(int i = 0; i < tam; i++)
    {
        for(int j = i + 1; j  <= tam; j++)
        {
            if(sort == 0)
            {
                if(letras[j] < letras[i])
                {
                    aux = letras[i];
                    letras[i] = letras[j];
                    letras[j] = aux;
                }
            }
            else
            {
                if(letras[j] > letras[i])
                {
                    aux = letras[i];
                    letras[i] = letras[j];
                    letras[j] = aux;
                }
            }

        }
    }
    fflush(stdin);
}
