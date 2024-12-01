//
//  main.cpp
//  AEROLINEA
//
//  Created by Andrea Alessandra Ortiz Jaime on Johana Rubio Arriaga 03/11/24.
//

#include <stdio.h>
#define FILAS 5
#define COLUMNAS 4
void mostrarAsientos(char asientos[FILAS][COLUMNAS]);
int seleccionarFila();
char seleccionarColumna();
int validarFila(int fila);
int validarColumna(char columna);
int asientoOcupado(char asientos[FILAS][COLUMNAS], int fila, int columna);
void reservarAsiento(char asientos[FILAS][COLUMNAS], int fila, int columna);

int main() {
//
    char asientos[FILAS][COLUMNAS] = {
        {'A', 'B', 'C', 'D'},
        {'A', 'B', 'C', 'D'},
        {'A', 'B', 'C', 'D'},
        {'A', 'B', 'C', 'D'},
        {'A', 'B', 'C', 'D'}
    };

    int filaSeleccionada;
    char columnaSeleccionada;
    while (1) {
        mostrarAsientos(asientos);
    filaSeleccionada = seleccionarFila();
        if (filaSeleccionada == 0) {
            printf("\nSaliendo del programa...\n");
            break;
        }

        if (!validarFila(filaSeleccionada)) {
            printf("\nError: Fila no encontrada. Intenta de nuevo.\n");
            continue;
        }

        columnaSeleccionada = seleccionarColumna();
        int columnaIndex = columnaSeleccionada - 'A';

        if (!validarColumna(columnaSeleccionada)) {
            printf("\nError: Columna no válida. Intenta de nuevo.\n");
            continue;
        }

        if (asientoOcupado(asientos, filaSeleccionada - 1, columnaIndex)) {
            printf("\nError: El asiento ya está ocupado. Intenta de nuevo.\n");
            continue;
        }

        reservarAsiento(asientos, filaSeleccionada - 1, columnaIndex);
        printf("\nAsiento %d%c reservado con éxito.\n", filaSeleccionada, columnaSeleccionada);
    }

    return 0;
}

void mostrarAsientos(char asientos[FILAS][COLUMNAS]) {
    printf("Bienvenidos a Aerolineas JA SKY\n");
    printf("---------------------\n");
    printf("Asientos disponibles\n");
    printf("---------------------\n");

    for (int i = 0; i < FILAS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c ", asientos[i][j]);
        }
        printf("\n");
    }

    printf("---------------------\n");
    printf("\nSelecciona tu fila de agrado (1-5) y asiento con letra Mayuscula de (A-D).\n");
    printf("\nCuando el asiento esté ocupado, se mostrará una X.\n");
    printf("\nPara terminar tu proceso selecciona 0 en la fila para salir del programa.\n");
}

int seleccionarFila() {
    int fila;
    printf("Fila: ");
    scanf("%d", &fila);
    return fila;
}

char seleccionarColumna() {
    char columna;
    printf("Columna (A-D): ");
    scanf(" %c", &columna);
    return columna;
}

int validarFila(int fila) {
    return fila >= 1 && fila <= FILAS;
}

int validarColumna(char columna) {
    int columnaIndex = columna - 'A';
    return columnaIndex >= 0 && columnaIndex < COLUMNAS;
}

int asientoOcupado(char asientos[FILAS][COLUMNAS], int fila, int columna) {
    return asientos[fila][columna] == 'X';
}

void reservarAsiento(char asientos[FILAS][COLUMNAS], int fila, int columna) {
    asientos[fila][columna] = 'X';
}
