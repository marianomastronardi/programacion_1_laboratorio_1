typedef struct
{
    int legajo;
    char nombre[30];
    float promedio;
    int edad;
}sAlumno;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarAlumno(sAlumno);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarAlumnos(sAlumno[], int);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void pedirAlumnos(sAlumno[], int);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

sAlumno pedirAlumno();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void OrdenarAlumnosXNombre(sAlumno[], int);
