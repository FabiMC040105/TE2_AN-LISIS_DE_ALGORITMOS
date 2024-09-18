#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H


#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// Implementación genérica del algoritmo Selection Sort usando templates
template<typename T>
void selectionsort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Encuentra el elemento mínimo en el arreglo no ordenado
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Intercambia el elemento mínimo encontrado con el primer elemento
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Función para generar un caso peor (ordenado de forma inversa)
template<typename T>
void peorcasoss(vector<T>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) {
        arr.push_back(n - i); // Llena el vector con valores decrecientes
    }
}

// Función para generar un caso mejor (ya ordenado)
template<typename T>
void mejorcasoss(vector<T>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) {
        arr.push_back(i); // Llena el vector con valores crecientes
    }
}

// Función para generar un caso promedio (valores aleatorios)
template<typename T>
void casopromedioss(vector<T>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 1000); // Llena el vector con números aleatorios
    }
}

// Función para medir el tiempo de ejecución de una función de ordenamiento
template<typename T>
void tiemposs(void (*sortFunction)(vector<T>&), vector<T>& arr, int n, const string& caseType) {
    auto start = chrono::high_resolution_clock::now();
    sortFunction(arr); // Ejecuta la función de ordenamiento
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Tiempo de ejecucion para el " << caseType << " caso con N=" << n << ": " << duration.count() << " segundos." << endl;
}

// Función para realizar pruebas de Selection Sort con diferentes casos y tamaños
void testSelectionSort() {
    vector<int> arr;
    const int N_vals[] = {100, 1000, 5000, 10000};  // Diferentes valores de N para probar
    int num_tests = sizeof(N_vals) / sizeof(N_vals[0]);

    // Pruebas para diferentes valores de N
    for (int i = 0; i < num_tests; i++) {
        int N = N_vals[i];

        // Caso peor (ordenado inversamente)
        peorcasoss(arr, N);
        tiemposs(selectionsort<int>, arr, N, "peor");

        // Caso mejor (ya ordenado)
        mejorcasoss(arr, N);
        tiemposs(selectionsort<int>, arr, N, "mejor");

        // Caso promedio (valores aleatorios)
        casopromedioss(arr, N);
        tiemposs(selectionsort<int>, arr, N, "promedio");
    }
}


#endif //SELECTIONSORT_H
