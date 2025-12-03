#include <stdio.h>

/* Calcula longitud.
El programa calcula la longitud de la cadena sin utilizar la funcion strlen. */

int cuenta(char *cadena);    /* Prototipo de funcion. */

int main(void)
{
    int i;
    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, 50, stdin);

    i = cuenta(cad);
    printf("\nLongitud de la cadena: %d\n", i);
}

int cuenta(char *cadena)
/* La funcion calcula la longitud de la cadena. */
{
    int c = 0;
    while (cadena[c] != '\0');
        c++;
    return c;
}
