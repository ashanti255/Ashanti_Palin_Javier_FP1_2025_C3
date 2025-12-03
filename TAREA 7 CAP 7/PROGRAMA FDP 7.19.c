#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Cuenta palabra.
El programa calcula el numero de palabra que hay en la cadena de caracteres. */

int cuentap(char *);     /* Prototipo de funcion. */

void main(void)
{
    int i;
    char fra[50];
    printf("\nIngrese la inea de texto: ");
    gets(fra);
    strcat(fra," ");     /* Se agrega un espacio en blanco al final de la cadena. */

    i = cuentap(fra);
    printf("\nLa linea de texto tiene %d palabra", i);
}

int cuentap(char *cad)
{
    /* La funcion cuenta el numero de palabras que hay en la cadena de caracteres. */
    char *cad0 = "";
    int i = 0;
    cad0 = strstr(cad, " ");     /* Se localiza el primer espacio en blaco en la cadena. */

    while (strcmp(cad, " "))
    {
        strcpy(cad, cad0);
        i++;
        cad0 = strstr (cad + 1, " ");
        /* Se busca un espacio en blanco a partir de la siguiente posicion. */
    }
    return (i);
}
