#include <stdio.h>
#include <string.h>

/* Escuela.
   El programa genera información estadística de los alumnos de una escuela. */

typedef struct
{
    int matricula;
    char nombre[30];
    float cal[5];   /* Arreglo unidimensional que almacena 5 calificaciones. */
} alumno;

void Lectura(alumno A[], int T);
void F1(alumno *A, int TAM);   /* Prototipos de funciones. */
void F2(alumno *A, int TAM);
void F3(alumno *A, int TAM);

void main(void)
{
    alumno ARRE[50];   /* Arreglo unidimensional de alumnos. */
    int TAM;

    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > 50 || TAM < 1);

    /* Se verifica que el tamaño sea válido. */

    Lectura(ARRE, TAM);
    F1(ARRE, TAM);
    F2(ARRE, TAM);
    F3(ARRE, TAM);
}

void Lectura(alumno A[], int T)
/* Lee un arreglo unidimensional de tipo alumno con T elementos. */
{
    int I, J;

    for (I = 0; I < T; I++)
    {
        printf("\nIngrese los datos del alumno %d", I + 1);

        printf("\nIngrese la matricula del alumno: ");
        scanf("%d", &A[I].matricula);
        fflush(stdin);

        printf("Ingrese el nombre del alumno: ");
        gets(A[I].nombre);

        for (J = 0; J < 5; J++)
        {
            printf("\tIngrese la calificacion %d del alumno %d: ", J + 1, I + 1);
            scanf("%f", &A[I].cal[J]);
        }
    }
}

void F1(alumno A[], int T)
/* Calcula e imprime la matrícula y el promedio de cada alumno. */
{
    int I, J;
    float SUM, PRO;

    for (I = 0; I < T; I++)
    {
        printf("\nMatricula del alumno: %d", A[I].matricula);

        SUM = 0.0;
        for (J = 0; J < 5; J++)
            SUM += A[I].cal[J];

        PRO = SUM / 5;
        printf("\t\tPromedio: %.2f", PRO);
    }
}

void F2(alumno A[], int T)
/* Imprime las matrículas de los alumnos con calificación mayor que 9 en la materia 3. */
{
    int I;

    printf("\nAlumnos con calificacion en la tercera materia > 9");

    for (I = 0; I < T; I++)
        if (A[I].cal[2] > 9)
            printf("\nMatricula del alumno: %d", A[I].matricula);
}

void F3(alumno A[], int T)
/* Calcula e imprime el promedio general de la materia 4. */
{
    int I;
    float SUM = 0.0, PRO;

    for (I = 0; I < T; I++)
        SUM += A[I].cal[3];

    PRO = SUM / T;

    printf("\n\nPromedio de la materia 4: %.2f", PRO);
}
