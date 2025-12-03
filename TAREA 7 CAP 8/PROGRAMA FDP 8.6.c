#include <stdio.h>
#include <string.h>

/* Comercializadora farmaceutica.
   Manejo de ventas, inventario, reabastecimiento y nuevos productos. */

typedef struct
{
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;

void Lectura(producto *, int);
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);

void main(void)
{
    producto INV[100];
    int TAM, OPE;

    do
    {
        printf("Ingrese el numero de productos: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);

    Lectura(INV, TAM);

    printf("\nIngrese operacion a realizar.\n"
           "\t1 - Ventas\n"
           "\t2 - Reabastecimiento\n"
           "\t3 - Nuevos Productos\n"
           "\t4 - Inventario\n"
           "\t0 - Salir: ");
    scanf("%d", &OPE);

    while (OPE)
    {
        switch (OPE)
        {
            case 1: Ventas(INV, TAM); break;
            case 2: Reabastecimiento(INV, TAM); break;
            case 3: Nuevos_Productos(INV, &TAM); break;
            case 4: Inventario(INV, TAM); break;
        }

        printf("\nIngrese operacion a realizar.\n"
               "\t1 - Ventas\n"
               "\t2 - Reabastecimiento\n"
               "\t3 - Nuevos Productos\n"
               "\t4 - Inventario\n"
               "\t0 - Salir: ");
        scanf("%d", &OPE);
    }
}

void Lectura(producto A[], int T)
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\nIngrese informacion del producto %d", I+1);
        printf("\n\tClave: ");
        scanf("%d", &A[I].clave);
        fflush(stdin);

        printf("\tNombre: ");
        gets(A[I].nombre);

        printf("\tPrecio: ");
        scanf("%f", &A[I].precio);

        printf("\tExistencia: ");
        scanf("%d", &A[I].existencia);
    }
}

/* ---------------- VENTAS ---------------- */

void Ventas(producto A[], int T)
{
    int CLA, CAN, I;
    float TOT = 0;

    printf("\nIngrese la clave del producto (-0 para salir): ");
    scanf("%d", &CLA);

    while (CLA)
    {
        I = 0;

        while ((I < T) && (A[I].clave < CLA))
            I++;

        if (I == T || A[I].clave > CLA)
            printf("La clave del producto ingresada es incorrecta\n");
        else
        {
            printf("\tCantidad: ");
            scanf("%d", &CAN);

            if (CAN > A[I].existencia)
                printf("\nNo hay suficiente cantidad en existencia");
            else
            {
                A[I].existencia -= CAN;
                TOT += CAN * A[I].precio;
            }
        }

        printf("\nIngrese la siguiente clave del producto (-0 para salir): ");
        scanf("%d", &CLA);
    }

    printf("\nTotal de la venta: %.2f", TOT);
}

/* ---------------- REABASTECIMIENTO ---------------- */

void Reabastecimiento(producto A[], int T)
{
    int CLA, CAN, I;

    printf("\nIngrese clave del producto (-0 para salir): ");
    scanf("%d", &CLA);

    while (CLA)
    {
        I = 0;
        while ((I < T) && (A[I].clave < CLA))
            I++;

        if (I == T || A[I].clave > CLA)
            printf("La clave del producto es incorrecta\n");
        else
        {
            printf("\tCantidad: ");
            scanf("%d", &CAN);
            A[I].existencia += CAN;
        }

        printf("\nIngrese otra clave del producto (-0 para salir): ");
        scanf("%d", &CLA);
    }
}

/* ---------------- NUEVOS PRODUCTOS ---------------- */

void Nuevos_Productos(producto A[], int *T)
{
    int CLA, I, J;

    printf("\nIngrese clave del producto (-0 para salir): ");
    scanf("%d", &CLA);

    while ((*T < 30) && CLA)
    {
        I = 0;
        while (I < *T && A[I].clave < CLA)
            I++;

        if (I == *T)
        {
            A[I].clave = CLA;
            printf("\tNombre: ");
            fflush(stdin);
            gets(A[I].nombre);
            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);
            printf("\tCantidad: ");
            scanf("%d", &A[I].existencia);
            *T = *T + 1;
        }
        else if (A[I].clave == CLA)
            printf("\nEl producto ya existe en el inventario");
        else
        {
            for (J = *T; J > I; J--)
                A[J] = A[J-1];

            A[I].clave = CLA;
            fflush(stdin);
            printf("\tNombre: ");
            gets(A[I].nombre);
            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);
            printf("\tCantidad: ");
            scanf("%d", &A[I].existencia);

            *T = *T + 1;
        }

        printf("\nIngrese otra clave del producto (-0 para salir): ");
        scanf("%d", &CLA);
    }

    if (*T == 30)
        printf("\nYa no hay espacio para incorporar nuevos productos");
}

/* ---------------- INVENTARIO ---------------- */

void Inventario(producto A[], int T)
{
    int I;

    for (I=0; I<T; I++)
    {
        printf("\nClave: %d", A[I].clave);
        printf("\tNombre: %s", A[I].nombre);
        printf("\tPrecio: %.2f", A[I].precio);
        printf("\tExistencia: %d\n", A[I].existencia);
    }
}
