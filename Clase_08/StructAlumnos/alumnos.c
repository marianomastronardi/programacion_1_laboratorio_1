#include "alumnos.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void pedirAlumnos(sAlumno Alumnos[], int tam)
{

    for(int i = 0; i < tam; i++)
    {
        printf("Ingrese un legajo: ");
        scanf("%d", &Alumnos[i].legajo);

        printf("Ingrese un nombre: ");
        scanf("%s", Alumnos[i].nombre);
        fflush(stdin);

        printf("Ingrese un promedio: ");
        scanf("%f", &Alumnos[i].promedio);

        printf("Ingrese un edad: ");
        scanf("%d", &Alumnos[i].edad);
    }

}

sAlumno pedirAlumno()
{
    sAlumno miAlumno;

    printf("Ingrese un legajo: ");
    scanf("%d", &miAlumno.legajo);

    printf("Ingrese un nombre: ");
    scanf("%s", miAlumno.nombre);
    fflush(stdin);

    printf("Ingrese un promedio: ");
    scanf("%f", &miAlumno.promedio);

    printf("Ingrese un edad: ");
    scanf("%d", &miAlumno.edad);

    return miAlumno;
}

void mostrarAlumno(sAlumno miAlumno)
{
    fflush(stdin);
    printf("%d--%s--%.2f-%d\n", miAlumno.legajo, miAlumno.nombre, miAlumno.promedio, miAlumno.edad);
}

void mostrarAlumnos(sAlumno Alumnos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        fflush(stdin);
        printf("%8d%20s%8.2f%8d\n\n\n", Alumnos[i].legajo, Alumnos[i].nombre, Alumnos[i].promedio, Alumnos[i].edad);
    }
}

void OrdenarAlumnosXNombre(sAlumno Alumnos[], int tam)
{
    sAlumno aux;
    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(strcmp(Alumnos[i].nombre, Alumnos[j].nombre) > 0)
            {
                aux = Alumnos[i];
                Alumnos[i] = Alumnos[j];
                Alumnos[j] = aux;
            }
        }
    }
}

