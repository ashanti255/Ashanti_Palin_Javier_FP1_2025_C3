// ===============================================================
//                CALCULUS C  -  Calculadora ashanti A
// ===============================================================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ===== STRUCT para números complejos =====
typedef struct {
    double real;
    double imag;
} Complejo;

// ====== Historial ======
char historial[200][300];
int contador_historial = 0;

// ====== Prototipos ======
void limpiar_buffer();
void Limpiar_pantalla();
void guardar_historial(const char *texto);
void mostrar_historial();
void guardar_historial_en_archivo();

void menu_operaciones_basicas();
void menu_complejos();
void menu_matrices();

// ====== UTILIDADES ======
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void Limpiar_pantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void guardar_historial(const char *texto) {
    if (contador_historial < 200) {
        sprintf(historial[contador_historial], "%s", texto);
        contador_historial++;
    }
}
void mostrar_historial() {
    printf("\n========== HISTORIAL ==========\n");
    if (contador_historial == 0) {
        printf("No hay operaciones registradas.\n");
        return;
    }
    for (int i = 0; i < contador_historial; i++) {
        printf("[%02d] %s\n", i + 1, historial[i]);
    }
}
void guardar_historial_en_archivo() {
    FILE *f = fopen("historial_calculusC.txt", "w");
    if (!f) {
        printf("Error al crear archivo.\n");
        return;
    }
    for (int i = 0; i < contador_historial; i++) {
        fprintf(f, "%s\n", historial[i]);
    }
    fclose(f);
    printf("Historial guardado correctamente en 'historial_calculusC.txt'\n");
}

// ===============================================================
//                 OPERACIONES BÁSICAS
// ===============================================================
void menu_operaciones_basicas() {
    double a, b, r;
    int op;
    char buffer[200];

    printf("\n========= OPERACIONES BÁSICAS =========\n");
    printf("[1] Sumar\n[2] Restar\n[3] Multiplicar\n[4] Dividir\n");
    printf("Seleccione una opción: ");

    if (scanf("%d", &op) != 1) { limpiar_buffer(); return; }

    printf("Ingrese A: "); scanf("%lf", &a);
    printf("Ingrese B: "); scanf("%lf", &b);

    switch (op) {
        case 1:
            r = a + b;
            sprintf(buffer, "Suma: %.2lf + %.2lf = %.2lf", a, b, r);
            break;
        case 2:
            r = a - b;
            sprintf(buffer, "Resta: %.2lf - %.2lf = %.2lf", a, b, r);
            break;
        case 3:
            r = a * b;
            sprintf(buffer, "Multiplicación: %.2lf * %.2lf = %.2lf", a, b, r);
            break;
        case 4:
            if (b != 0) sprintf(buffer, "División: %.2lf / %.2lf = %.2lf", a, b, a / b);
            else sprintf(buffer, "Error: división entre cero.");
            break;
        default:
            printf("Opción inválida.\n");
            return;
    }

    printf("%s\n", buffer);
    guardar_historial(buffer);
}

// ===============================================================
//                 OPERACIONES COMPLEJOS
// ===============================================================
Complejo leer_complejo() {
    Complejo c;
    printf("Parte real: "); scanf("%lf", &c.real);
    printf("Parte imaginaria: "); scanf("%lf", &c.imag);
    return c;
}
void print_complejo(Complejo c) {
    printf("%.2lf %c %.2lfi", c.real, (c.imag >= 0 ? '+' : '-'), fabs(c.imag));
}
void menu_complejos() {
    int op;
    char buffer[300];
    Complejo a, b, r;

    printf("\n========== OPERACIONES CON COMPLEJOS ==========\n");
    printf("[1] Sumar\n[2] Restar\n[3] Multiplicar\n[4] Dividir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &op);

    printf("\nIngrese número complejo A:\n");
    a = leer_complejo();
    printf("\nIngrese número complejo B:\n");
    b = leer_complejo();

    switch (op) {
        case 1:
            r.real = a.real + b.real;
            r.imag = a.imag + b.imag;
            sprintf(buffer, "Complejos Suma: (%.2lf + %.2lfi) + (%.2lf + %.2lfi) = %.2lf + %.2lfi",
                    a.real, a.imag, b.real, b.imag, r.real, r.imag);
            break;
        case 2:
            r.real = a.real - b.real;
            r.imag = a.imag - b.imag;
            sprintf(buffer, "Complejos Resta: (%.2lf + %.2lfi) - (%.2lf + %.2lfi) = %.2lf + %.2lfi",
                    a.real, a.imag, b.real, b.imag, r.real, r.imag);
            break;
        case 3:
            r.real = a.real*b.real - a.imag*b.imag;
            r.imag = a.real*b.imag + a.imag*b.real;
            sprintf(buffer, "Complejos Multiplicación: ... Resultado = %.2lf + %.2lfi",
                    r.real, r.imag);
            break;
        case 4: {
            double denom = b.real*b.real + b.imag*b.imag;
            if (denom == 0) {
                sprintf(buffer, "Error: división entre complejo 0.");
            } else {
                r.real = (a.real*b.real + a.imag*b.imag) / denom;
                r.imag = (a.imag*b.real - a.real*b.imag) / denom;
                sprintf(buffer, "Complejos División Resultado = %.2lf + %.2lfi",
                        r.real, r.imag);
            }
        } break;
        default:
            printf("Opción inválida.\n");
            return;
    }

    printf("%s\n", buffer);
    guardar_historial(buffer);
}

// ===============================================================
//                 OPERACIONES MATRICES
// ===============================================================
void leer_matriz(double m[3][3]) {
    printf("\nIngrese matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%lf", &m[i][j]);
}
void print_matriz(double m[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++)
            printf("%8.2lf ", m[i][j]);
        printf("|\n");
    }
}

void menu_matrices() {
    int op;
    double A[3][3], B[3][3], R[3][3];
    char buffer[300];

    printf("\n========== OPERACIONES CON MATRICES 3x3 ==========\n");
    printf("[1] Suma\n[2] Resta\n[3] Multiplicación\n");
    printf("Seleccione: ");
    scanf("%d", &op);

    leer_matriz(A);
    leer_matriz(B);

    // OPERACIONES
    if (op == 1) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                R[i][j] = A[i][j] + B[i][j];
        sprintf(buffer, "Suma de matrices realizada.");
    }
    else if (op == 2) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                R[i][j] = A[i][j] - B[i][j];
        sprintf(buffer, "Resta de matrices realizada.");
    }
    else if (op == 3) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                R[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    R[i][j] += A[i][k] * B[k][j];
            }
        sprintf(buffer, "Multiplicación de matrices realizada.");
    }
    else {
        printf("Opción inválida.\n");
        return;
    }

    printf("\nResultado:\n");
    print_matriz(R);

    guardar_historial(buffer);
}

// ===============================================================
//                          MAIN
// ===============================================================
int main() {
    int opcion;

    printf("\n=====================================\n");
    printf("      ***  CALCULUS C (Avanzado) ***\n");
    printf("=====================================\n");

    do {
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("[1] Operaciones básicas (double)\n");
        printf("[2] Operaciones con números complejos\n");
        printf("[3] Operaciones con matrices 3x3\n");
        printf("[4] Ver historial\n");
        printf("[5] Guardar historial en archivo\n");
        printf("[6] Salir\n");
        printf("Seleccione una opción: ");

        if (scanf("%d", &opcion) != 1) { limpiar_buffer(); continue; }

        switch (opcion) {
            case 1: menu_operaciones_basicas(); break;
            case 2: menu_complejos(); break;
            case 3: menu_matrices(); break;
            case 4: mostrar_historial(); break;
            case 5: guardar_historial_en_archivo(); break;
            case 6: printf("Saliendo del sistema... ¡Hasta luego!\n"); break;
            default: printf("Opción inválida.\n");
        }

    } while (opcion != 6);

    return 0;
}
