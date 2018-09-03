#include "Validador.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

/** \brief valida que el valor ingresado sea numerico
 *
 * \param numero es de tipo string
 * \return retorna 1 si es un numero, sino 0
 *
 */

int validarnumero(char numero[]){

    for(int i=0; i<strlen(numero); i++){
        if(!(isdigit(numero[i]))){
            return 0;
        };
    };
    return 1;
};
