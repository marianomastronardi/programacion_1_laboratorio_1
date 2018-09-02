#include "Validador.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int validarnumero(char numero[]){

    for(int i=0; i<strlen(numero); i++){
        if(!(isdigit(numero[i]))){
            return 0;
        };
    };
    return 1;
};
