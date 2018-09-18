#include <stdio.h>
#include <stdlib.h>
#include "alumnos.h"

#define A 3

int main()
{
    //sAlumno miAlumno = {105, "Juan", 4.65};
    //printf("%d--%s--%.2f\n", miAlumno.legajo, miAlumno.nombre, miAlumno.promedio);
    sAlumno Alumnos[A];
//pedirAlumnos(Alumnos, A);
    /*
    for(int i = 0; i < A; i++){
        Alumnos[i] = pedirAlumno();
    }
    */
    pedirAlumnos(Alumnos, A);
    mostrarAlumnos(Alumnos, A);
    OrdenarAlumnosXNombre(Alumnos, A);
    mostrarAlumnos(Alumnos, A);
    //sAlumno miAlumno;
    //miAlumno = pedirAlumno();
    // mostrarAlumno(pedirAlumno());
    //mostrarAlumno(miAlumno);

    // otroAlumno = miAlumno;

    // printf("1er Alumno %d--%s--%.2f\n", miAlumno.legajo, miAlumno.nombre, miAlumno.promedio);
    // printf("2do Alumno %d--%s--%.2f\n", otroAlumno.legajo, otroAlumno.nombre, otroAlumno.promedio);

    return 0;
}
