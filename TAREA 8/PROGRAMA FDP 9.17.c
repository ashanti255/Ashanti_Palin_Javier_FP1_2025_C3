#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/* Reemplaza palabras.
El programa lee cadenas de caracteres de un archivo y cada que vez que
encuentra la palabra México escrita en forma incorrecta —la primera con
minúscula— la reemplaza por su forma correcta y escribe la cadena en otro
archivo. */

void cambia(FILE *, FILE *);

void main(void)
{
    FILE *ar;
    FILE *ap;
    ar = fopen("arc.txt", "r");
    ap = fopen("arc1.txt", "w");
    if ((ar != NULL) && (ap != NULL))
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    }
    else
        printf("No se pueden abrir los archivos");
}

void cambia(FILE *ap1, FILE *ap2)
{
    int i, j, k;
    char cad[30], *cad1="", *cad2="", aux[30];
    while (!feof(ap1))
    {
      fgets(cad, 30, ap1);
      strpy(cad1, cad);
      cad2 = strstr(cad1, "méxico");
      while (cad2!=NULL)
      {
         cad2[0]='M';
         i = strlen(cad1);
         j = strlen(cad2);
         k = i - j;
         if (k)
            {
                strncpy(aux, cad1, k);
                aux[k] = '\0';
                strcat(aux, cad2);
                strcpy(cad1, aux);
            }
            else
                cpy(cad1, cad2);
            cad2 = strstr(cad1, "méxico");

      }
      puts(cad1, ap2);
   }
}
