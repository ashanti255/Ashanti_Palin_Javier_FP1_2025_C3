#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Estructuras-2.
El programa muestra la manera en que se declara una estructura, asi como la
forma en que se tiene acceso a los campos de los apuntadores de tipo estructura
tanto para lectura como para escritura.
Se utiliza ademas una funcion que recibe como parametro un apuntador de tipo estructura. */

struct alumno   /* Declaracion de la estructura. */
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
};

void Lectura(struct alumno *); /* Prototipo de funcion. */

void main(void)
{
    struct alumno a0 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"};
    struct alumno *a3, *a4, *a5, a6;

    a3 = &a0;       /* a3 apunta a a0 */
    a4 = (struct alumno *) malloc(sizeof(struct alumno));  /* Correccion */
    a5 = (struct alumno *) malloc(sizeof(struct alumno));  /* Correccion */

    /* Lectura de los campos de a4 */
    printf("\nIngrese la matricula del alumno 4: ");
    scanf("%d", &(*a4).matricula);
    fflush(stdin);

    printf("Ingrese el nombre del alumno 4: ");
    gets(a4->nombre);

    printf("Ingrese la carrera del alumno 4: ");
    gets((*a4).carrera);

    printf("Ingrese promedio del alumno 4: ");
    scanf("%f", &a4->promedio);
    fflush(stdin);

    printf("Ingrese la direccion del alumno 4: ");
    gets(a4->direccion);

    /* Ahora se leen los valores de a5 con la funcion Lectura */
    Lectura(a5);

    /* Lectura de los campos de la estructura a6 enviando su direccion */
    Lectura(&a6);

    /* Impresion */
    printf("\nDatos del alumno 3\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n",
           a3->matricula, a3->nombre, a3->carrera,
           a3->promedio, a3->direccion);

    printf("\nDatos del alumno 4\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n",
           a4->matricula, a4->nombre, a4->carrera,
           a4->promedio, a4->direccion);

    printf("\nDatos del alumno 5\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n",
           a5->matricula, a5->nombre, a5->carrera,
           a5->promedio, a5->direccion);

    printf("\nDatos del alumno 6\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n",
           a6.matricula, a6.nombre, a6.carrera,
           a6.promedio, a6.direccion);

    /* Liberar memoria */
    free(a4);
    free(a5);
}

void Lectura(struct alumno *a)
/* Esta funcion permite leer los campos de un apuntador de tipo estructura alumno. */
{
    printf("\nIngrese la matricula del alumno: ");
    scanf("%d", &(*a).matricula);
    fflush(stdin);

    printf("Ingrese el nombre del alumno: ");
    gets(a->nombre);
    fflush(stdin);

    printf("Ingrese la carrera del alumno: ");
    gets(a->carrera);

    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    fflush(stdin);

    printf("Ingrese la direccion del alumno: ");
    gets(a->direccion);
}
