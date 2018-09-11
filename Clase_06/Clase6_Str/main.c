#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void LetraCapital(char cadena[]);

int main()
{
    char nombre[20] = "MarIAna INes";
    char apellido[20] = "PEREz";
    char nombrecompleto[40];

    strlwr(nombre);
    strlwr(apellido);

    strcpy(nombrecompleto,strcat(strcat(nombre, " "),apellido));
    nombrecompleto[0] = toupper(nombrecompleto[0]);
    for(int i = 0; i < strlen(nombrecompleto); i++)
    {
        if(nombrecompleto[i] == ' ')
        {
            nombrecompleto[i + 1] = toupper(nombrecompleto[i + 1]);
        }
    }
    printf("%s\n", nombrecompleto);
    printf("%d",strlen(nombre));
    gets(nombre);
    fgets(nombre, 20,stdin);
    return 0;
}

