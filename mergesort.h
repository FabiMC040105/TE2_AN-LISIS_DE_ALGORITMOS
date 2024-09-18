#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>

#include "selectionsort.h"
using namespace std;

// Implementación genérica del algoritmo Merge Sort usando templates
template<typename T>
void merge(vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear arreglos temporales
    vector<T> L(n1), R(n2);

    // Copiar los datos a los arreglos temporales
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Mezclar los arreglos temporales
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si quedan
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si quedan
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función recursiva de Merge Sort
template<typename T>
void mergesort(vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenar la primera y segunda mitad
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        // Mezclar las mitades ordenadas
        merge(arr, left, mid, right);
    }
}

// Función para generar un caso peor (ordenado de forma inversa)
template<typename T>
void peorcasoms(vector<T>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) {
        arr.push_back(n - i); // Llena el vector con valores decrecientes
    }
}

// Función para generar un caso mejor (ya ordenado)
template<typename T>
void mejorcasoms(vector<T>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) {
        arr.push_back(i); // Llena el vector con valores crecientes
    }
}

// Función para generar un caso promedio (valores aleatorios)
template<typename T>
void casopromedioms(vector<T>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 1000); // Llena el vector con números aleatorios
    }
}

// Función para medir el tiempo de ejecución de una función de ordenamiento
template<typename T>
void tiempoms(void (*sortFunction)(vector<T>&, int, int), vector<T>& arr, int n, const string& caseType) {
    auto start = chrono::high_resolution_clock::now();
    sortFunction(arr, 0, n - 1); // Ejecuta la función de ordenamiento
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Tiempo de ejecucion para el " << caseType << " caso con N=" << n << ": " << duration.count() << " segundos." << endl;
}

// Función para realizar pruebas de Merge Sort con diferentes casos y tamaños
void testMergeSort() {
    vector<int> arr;
    const int N_vals[] = {100, 1000, 5000, 10000};  // Diferentes valores de N para probar
    int num_tests = sizeof(N_vals) / sizeof(N_vals[0]);

    // Pruebas para diferentes valores de N
    for (int i = 0; i < num_tests; i++) {
        int N = N_vals[i];

        // Caso peor (ordenado inversamente)
        peorcasoms(arr, N);
        tiempoms(mergesort<int>, arr, N, "peor");

        // Caso mejor (ya ordenado)
        mejorcasoms(arr, N);
        tiempoms(mergesort<int>, arr, N, "mejor");

        // Caso promedio (valores aleatorios)
        casopromedioms(arr, N);
        tiempoms(mergesort<int>, arr, N, "promedio");
    }
}
#endif //MERGESORT_H
