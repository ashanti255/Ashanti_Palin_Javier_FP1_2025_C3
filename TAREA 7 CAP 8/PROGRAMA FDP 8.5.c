#include <stdio.h>
#include <string.h>

/* Uniones.
   El programa muestra la manera como se declara una union, así como la forma
   de acceso a los campos de las variables de tipo union tanto para asignación
   de valores como para lectura y escritura. */

union datos   /* Declaración de una union. */
{
    char celular[15];
    char correo[20];
};

typedef struct    /* Declaración de una estructura utilizando typedef. */
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;  /* Uno de los campos es una union. */
} alumno;

void Lectura(alumno *a);   /* Prototipo de función. */

void main(void)
{
    alumno a1 = {120, "Maria", "Contabilidad", 8.9, "5-158-40-50"}, a2, a3;

    /* Solo el primer campo de la union puede recibir valores con inicialización. */

    printf("Alumno 2\n");
    printf("Ingrese la matricula: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);

    printf("Ingrese el nombre: ");
    gets(a2.nombre);

    fflush(stdin);
    printf("Ingrese la carrera: ");
    gets(a2.carrera);

    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);

    fflush(stdin);
    printf("Ingrese el correo electronico: ");
    gets(a2.personales.correo);

    /* El campo correo recibe el valor en la union. */

    printf("Alumno 3\n");
    Lectura(&a3);   /* Se leen los datos de a3 mediante una función. */

    /* Impresión de resultados */
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular); /* Aquí se imprime el número celular. */
    /* puts(a1.personales.correo);  Escribiría basura (no se debe). */

    /* Ejemplo del comportamiento de una union (se sobreescriben los campos) */

    strcpy(a1.personales.correo, "hgimenez@hotmail.com");

    puts(a1.personales.celular);  /* Ahora escribe basura. */
    puts(a1.personales.correo);   /* Escribe el correo asignado. */

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);

    puts(a2.personales.celular); /* Basura */
    puts(a2.personales.correo);  /* Valor correcto */

    printf("Ingrese el telefono celular del alumno 2: ");
    fflush(stdin);
    gets(a2.personales.celular);

    puts(a2.personales.celular); /* Ahora imprime celular actualizado */
    puts(a2.personales.correo); /* Ahora imprime basura */

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular);
    puts(a3.personales.correo); /* Escribe basura */
}

void Lectura(alumno *a)
/* Esta función lee los campos de una variable tipo alumno. */
{
    printf("\nIngrese la matricula: ");
    scanf("%d", &a->matricula);

    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a->nombre);

    fflush(stdin);
    printf("Ingrese la carrera: ");
    gets(a->carrera);

    printf("Ingrese el promedio: ");
    scanf("%f", &a->promedio);

    fflush(stdin);
    printf("Ingrese el telefono celular: ");
    gets(a->personales.celular);
}
