#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// Implementación genérica del algoritmo Bubble Sort usando templates
template<typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Función para generar un caso peor (ordenado de forma inversa)
template<typename T>
void peorcasobs(vector<T>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) {
        arr.push_back(n - i); // Llena el vector con valores decrecientes
    }
}

// Función para generar un caso mejor (ya ordenado)
template<typename T>
void mejorcasobs(vector<T>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) {
        arr.push_back(i); // Llena el vector con valores crecientes
    }
}

// Función para generar un caso promedio (valores aleatorios)
template<typename T>
void casopromediobs(vector<T>& arr, int n) {
    arr.clear();
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 1000); // Llena el vector con números aleatorios
    }
}

// Función para medir el tiempo de ejecución de una función de ordenamiento
template<typename T>
void tiempobs(function<void(vector<T>&)> sortFunction, vector<T>& arr, int n, const string& caseType) {
    auto start = chrono::high_resolution_clock::now();
    sortFunction(arr); // Ejecuta la función de ordenamiento
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Tiempo de ejecucion para el " << caseType << " caso con N=" << n << ": " << duration.count() << " segundos." << endl;
}

// Función para realizar pruebas de Bubble Sort con diferentes casos y tamaños
void testBubbleSort() {
    vector<int> arr;
    const int N_vals[] = {100, 1000, 5000, 10000};  // Diferentes valores de N para probar
    int num_tests = sizeof(N_vals) / sizeof(N_vals[0]);

    // Pruebas para diferentes valores de N
    for (int i = 0; i < num_tests; i++) {
        int N = N_vals[i];

        // Caso peor (ordenado inversamente)
        peorcasobs(arr, N);
        tiempobs<int>([](vector<int>& v) { bubbleSort(v); }, arr, N, "peor");

        // Caso mejor (ya ordenado)
        mejorcasobs(arr, N);
        tiempobs<int>([](vector<int>& v) { bubbleSort(v); }, arr, N, "mejor");

        // Caso promedio (valores aleatorios)
        casopromediobs(arr, N);
        tiempobs<int>([](vector<int>& v) { bubbleSort(v); }, arr, N, "promedio");
    }
}
