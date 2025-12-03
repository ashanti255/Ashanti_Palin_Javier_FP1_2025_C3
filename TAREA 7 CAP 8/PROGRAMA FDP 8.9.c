#include <stdio.h>
#include <string.h>

/* Bienes raíces.
   El programa maneja información sobre las propiedades que tiene una empresa
   de bienes raíces de Lima, Perú, tanto para venta como renta. */

typedef struct
{
    char zona[20];
    char calle[20];
    char colo[20];   /* Colonia. */
} ubicacion;

typedef struct
{
    char clave[5];
    float scu;       /* Superficie cubierta. */
    float ste;       /* Superficie terreno. */
    char car[50];    /* Características. */
    ubicacion ubi;   /* Campo tipo estructura ubicacion. */
    float precio;
    char dispo;      /* Disponibilidad. */
} propiedades;

void Lectura(propiedades A[], int T);
void F1(propiedades *, int);
void F2(propiedades *, int);

void main(void)
{
    propiedades PROPIE[100];
    int TAM;

    do
    {
        printf("Ingrese el número de propiedades: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);

    Lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);
}

void Lectura(propiedades A[], int T)
/* Lectura del arreglo unidimensional de tipo propiedades. */
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("\n\tIngrese datos de la propiedad %d", I + 1);

        printf("\nClave: ");
        fflush(stdin);
        gets(A[I].clave);

        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);

        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);

        printf("Características: ");
        fflush(stdin);
        gets(A[I].car);

        printf("\tZona: ");
        fflush(stdin);
        gets(A[I].ubi.zona);

        printf("\tCalle: ");
        fflush(stdin);
        gets(A[I].ubi.calle);

        printf("\tColonia: ");
        fflush(stdin);
        gets(A[I].ubi.colo);

        printf("Precio: ");
        scanf("%f", &A[I].precio);

        printf("Disponibilidad (Venta-V Renta-R): ");
        fflush(stdin);
        scanf("%c", &A[I].dispo);
    }
}

void F1(propiedades A[], int T)
/* Propiedades disponibles para venta en Miraflores con precio entre
   450,000 y 650,000. */
{
    int I;
    printf("\n\t\tListado de Propiedades para Venta en Miraflores");

    for (I = 0; I < T; I++)
        if ((A[I].dispo == 'V') && (strcmp(A[I].ubi.zona, "Miraflores") == 0))
            if ((A[I].precio >= 450000) && (A[I].precio <= 650000))
            {
                printf("\nClave de la propiedad: ");
                puts(A[I].clave);

                printf("Superficie cubierta: %f", A[I].scu);
                printf("\nSuperficie terreno: %f", A[I].ste);

                printf("\nCaracterísticas: ");
                puts(A[I].car);

                printf("Calle: ");
                puts(A[I].ubi.calle);

                printf("Colonia: ");
                puts(A[I].ubi.colo);

                printf("Precio: %.2f\n", A[I].precio);
            }
}

void F2(propiedades A[], int T)
/* Propiedades disponibles para renta según zona y rango de precios. */
{
    int I;
    float li, ls;
    char zon[20];

    printf("\n\t\tListado de Propiedades para Renta");

    printf("\nIngrese zona geográfica: ");
    fflush(stdin);
    gets(zon);

    printf("Ingrese el límite inferior del precio: ");
    scanf("%f", &li);

    printf("Ingrese el límite superior del precio: ");
    scanf("%f", &ls);

    for (I = 0; I < T; I++)
        if ((A[I].dispo == 'R') && (strcmp(A[I].ubi.zona, zon) == 0))
            if ((A[I].precio >= li) && (A[I].precio <= ls))
            {
                printf("\nClave de la propiedad: ");
                puts(A[I].clave);

                printf("Superficie cubierta: %f", A[I].scu);
                printf("\nSuperficie terreno: %f", A[I].ste);

                printf("\nCaracterísticas: ");
                puts(A[I].car);

                printf("Calle: ");
                puts(A[I].ubi.calle);

                printf("Colonia: ");
                puts(A[I].ubi.colo);

                printf("Precio: %.2f\n", A[I].precio);
            }
}
