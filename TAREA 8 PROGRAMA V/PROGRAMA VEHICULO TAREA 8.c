#include <stdio.h>
#include <stdlib.h>

/* Definición de la estructura Vehiculo */
struct Vehiculo {
    int codigo;
    char marca[30];
    char modelo[30];
    int anio;
    float precio;
};

/* Función para cargar vehículos inventados solo una vez */
void cargarVehiculosIniciales() {
    FILE *archivo;

    archivo = fopen("vehiculos.txt", "r");
    if (archivo != NULL) {
        fclose(archivo);
        return;  // Si el archivo ya existe, no vuelve a cargar datos
    }

    archivo = fopen("vehiculos.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return;
    }

    /* Datos inventados */
    fprintf(archivo, "1001 Dodge Charger 2021 32000\n");
    fprintf(archivo, "1002 Ford Mustang 2020 30000\n");

    fclose(archivo);
}

/* Función para agregar un nuevo vehículo */
void agregarVehiculo() {
    FILE *archivo;
    struct Vehiculo v;

    archivo = fopen("vehiculos.txt", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("\nIngrese el código del vehículo: ");
    scanf("%d", &v.codigo);

    printf("Ingrese la marca: ");
    scanf("%s", v.marca);

    printf("Ingrese el modelo: ");
    scanf("%s", v.modelo);

    printf("Ingrese el año: ");
    scanf("%d", &v.anio);

    printf("Ingrese el precio: ");
    scanf("%f", &v.precio);

    fprintf(archivo, "%d %s %s %d %.2f\n",
            v.codigo, v.marca, v.modelo, v.anio, v.precio);

    fclose(archivo);

    printf("\nVehículo agregado correctamente.\n");
}

/* Función para listar todos los vehículos */
void listarVehiculos() {
    FILE *archivo;
    struct Vehiculo v;

    archivo = fopen("vehiculos.txt", "r");
    if (archivo == NULL) {
        printf("\nNo hay vehículos registrados.\n");
        return;
    }

    printf("\n===== LISTA DE VEHÍCULOS =====\n");

    while (fscanf(archivo, "%d %s %s %d %f",
                  &v.codigo, v.marca, v.modelo, &v.anio, &v.precio) != EOF) {

        printf("\nCódigo : %d", v.codigo);
        printf("\nMarca  : %s", v.marca);
        printf("\nModelo : %s", v.modelo);
        printf("\nAño    : %d", v.anio);
        printf("\nPrecio : %.2f USD", v.precio);
        printf("\n----------------------------");
    }

    fclose(archivo);
}

/* Función principal */
int main() {
    int opcion;

    cargarVehiculosIniciales();

    do {
        printf("\n\n===== MENU DE VEHICULOS =====");
        printf("\n1. Agregar vehículo");
        printf("\n2. Listar vehículos");
        printf("\n3. Salir");
        printf("\nSeleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarVehiculo();
                break;
            case 2:
                listarVehiculos();
                break;
            case 3:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpción inválida.\n");
        }

    } while (opcion != 3);

    return 0;
}
