#include <stdio.h>
#define maximi 10 // Máximo número de notas

// Declaración de funciones (prototipos)
void leerNotas();
void imprimirNotas();
float promedioPonderado();
void extremos();
void editarNota();
void eliminarNota();
void clasificacion();

// Variables globales
float notas[maximo], pesos[maximo];
int n = 0; // Número actual de notas

// Función principal con menú interactivo
int main() {
    int opcion;
    char salir;

    do {
        // Menú principal
        printf("\n--- Menú ---\n");
        printf("\n1. Ingresar notas");
        printf("\n2. Mostrar notas\n");
        printf("\n3. Promedio ponderado\n")
        printf("\n4. Nota más alta/baja\n");
        printf("\n5. Editar nota\n")
        printf("\n6. Eliminar nota\n")
        printf("\n7. Clasificación cualitativa\n");
        printf("\n0. Salir\n")
        scanf("%d", &opcion);

        // Redirige a la función correspondiente
        switch (opcion) {
            case 1: leerNotas(); break;
            case 2: imprimirNotas(); break;
            case 3: printf("Promedio ponderado: %.2f\n", promedioPonderado()); break;
            case 4: extremos(); break;
            case 5: editarNota(); break;
            case 6: eliminarNota(); break;
            case 7: clasificacion(); break;
            case 0:
                // Confirmación de salida
                printf("¿Seguro que desea salir? (s/n): ");
                scanf(" %c", &salir);
                if (salir != 's' && salir != 'S') opcion = -1;
                break;
            default: printf("Opción no válida.\n");
        }
    } while (opcion != 0); // Repite hasta que el usuario confirme la salida

    return 0;
} 

// Función para ingresar nuevas notas y pesos
void leerNotas() {
    int m;
    float pesoTotal = 0;
    printf("¿Cuántas notas? (maximo %d): ", maximo - n);
    scanf("%d", &m);
    if (m < 0 || m > maximo - n) return;

    for (int i = 0; i < m; i++) {
        float nota, peso;
        // Solicita nota y peso
        printf("Nota #%d (0-100): ", n + 1); 
        scanf("%f", &nota);
        printf("Peso (1-100): "); 
        scanf("%f", &peso);

        // Valida que nota y peso sean correctos y que la suma de pesos no exceda 100%
        if (nota < 0 || nota > 100 || peso <= 0 || peso > 100 || pesoTotal + peso > 100) {
            printf("Entrada inválida.\n"); 
            i--; 
            continue;
        }

        // Guarda nota y peso
        notas[n] = nota; 
        pesos[n] = peso;
        pesoTotal += peso; 
        n++;
    }
}

// Muestra todas las notas y pesos, y calcula promedio simple
void imprimirNotas() {
    if (n == 0) {
        printf("No hay notas ingresadas.\n");
        return;
    }
    
    float suma = 0;
    printf("Índice\tNota\tPeso\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%.2f\t%.2f\n", i, notas[i], pesos[i]);
        suma += notas[i];
    }
    printf("Promedio simple: %.2f\n", suma / n);
}

// Calcula y retorna el promedio ponderado
float promedioPonderado() {
    float suma = 0, totalPeso = 0;
    for (int i = 0; i < n; i++) {
        suma += notas[i] * pesos[i];
        totalPeso += pesos[i];
    }
    return totalPeso ? suma / totalPeso : 0;
}

// Muestra la nota más alta y más baja con sus índices
void extremos() {
    if (n == 0) {
        printf("No hay notas para analizar.\n");
        return;
    }

    int max = 0, min = 0;
    for (int i = 1; i < n; i++) {
        if (notas[i] > notas[max]) max = i;
        if (notas[i] < notas[min]) min = i;
    }

    printf("Nota más alta: %.2f (índice %d)\n", notas[max], max);
    printf("Nota más baja: %.2f (índice %d)\n", notas[min], min);
}

// Edita una nota y su peso por índice
void editarNota() {
    int i;
    float nuevaNota, nuevoPeso, pesoTotal = 0;

    printf("Índice a editar: "); 
    scanf("%d", &i);
    if (i < 0 || i >= n) {
        printf("Índice fuera de rango.\n");
        return;
    }

    // Solicita nueva nota y peso
    printf("Nueva nota: "); 
    scanf("%f", &nuevaNota);
    printf("Nuevo peso: "); 
    scanf("%f", &nuevoPeso);

    // Calcula suma de pesos sin contar el actual
    for (int j = 0; j < n; j++)
        if (j != i) pesoTotal += pesos[j];

    // Valida entrada
    if (nuevaNota < 0 || nuevaNota > 100 || nuevoPeso <= 0 || nuevoPeso > 100 || pesoTotal + nuevoPeso > 100) {
        printf("Valores inválidos.\n"); 
        return;
    }

    // Asigna nuevos valores
    notas[i] = nuevaNota; 
    pesos[i] = nuevoPeso;
    printf("Nota editada.\n");
}

// Elimina una nota por índice y reorganiza los arreglos
void eliminarNota() {
    int i;
    printf("Índice a eliminar: "); 
    scanf("%d", &i);
    if (i < 0 || i >= n) {
        printf("Índice fuera de rango.\n");
        return;
    }

    // Desplaza los elementos hacia la izquierda para eliminar la nota
    for (int j = i; j < n - 1; j++) {
        notas[j] = notas[j + 1];
        pesos[j] = pesos[j + 1];
    }

    n--; // Reduce la cantidad de notas
    printf("Nota eliminada.\n");
}

// Convierte el promedio ponderado a clasificación cualitativa (A–F)
void clasificacion() {
    float p = promedioPonderado();
    char c = (p >= 90) ? 'A' : (p >= 80) ? 'B' : (p >= 70) ? 'C' : (p >= 60) ? 'D' : 'F';
    printf("Clasificación: %c\n", c);
}
