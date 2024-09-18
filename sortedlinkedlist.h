#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <functional>

using namespace std;

// Nodo de la lista enlazada
template<typename T>
struct Node {
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

// Definición de la Sorted Linked List
template<typename T>
class SortedLinkedList {
private:
    Node<T>* head;  // Puntero al primer nodo

public:
    // Constructor
    SortedLinkedList() : head(nullptr) {}

    // Destructor
    ~SortedLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Función para insertar un valor de forma ordenada
    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr || head->data >= value) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr && current->next->data , value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Función para buscar un elemento
    bool search(T value) {
        Node<T>* current = head;
        while (current != nullptr && current->data <= value) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Función para limpiar la lista
    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};

// Función para generar el peor caso (valores en orden inverso)
template<typename T>
void peorcasoll(vector<T>& data, int n) {
    data.clear();
    for (int i = 0; i < n; i++) {
        data.push_back(n - i);  // Orden inverso
    }
}

// Función para generar el mejor caso (valores ya ordenados)
template<typename T>
void mejorcasoll(vector<T>& data, int n) {
    data.clear();
    for (int i = 0; i < n; i++) {
        data.push_back(i);  // Orden creciente
    }
}

// Función para generar un caso promedio (valores aleatorios)
template<typename T>
void casopromedioll(vector<T>& data, int n) {
    data.clear();
    for (int i = 0; i < n; i++) {
        data.push_back(rand() % 1000);  // Valores aleatorios
    }
}

// Función para medir el tiempo de ejecución de la inserción
template<typename T>
void tiempoinsertll(SortedLinkedList<T>& list, vector<T>& data, int n, const string& caseType) {
    list.clear();
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        list.insert(data[i]);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Tiempo de insercion para el " << caseType << " caso con N=" << n << ": " << duration.count() << " segundos." << endl;
}

// Función para medir el tiempo de ejecución de la búsqueda
template<typename T>
void tiemposearchll(SortedLinkedList<T>& list, vector<T>& data, int n, const string& caseType) {
    auto start = chrono::high_resolution_clock::now();

    // Búsqueda del último valor como peor caso
    bool found = list.search(data[n - 1]);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Tiempo de busqueda para el " << caseType << " caso con N=" << n << ": " << duration.count() << " segundos." << endl;
}

// Función para realizar pruebas con la Sorted Linked List
void testSortedLinkedList() {
    SortedLinkedList<int> list;
    vector<int> data;
    const int N_vals[] = {100, 1000, 5000, 10000};  // Diferentes valores de N
    int num_tests = sizeof(N_vals) / sizeof(N_vals[0]);

    for (int i = 0; i < num_tests; i++) {
        int N = N_vals[i];

        // Caso peor (orden inverso)
        peorcasoll(data, N);
        tiempoinsertll(list, data, N, "peor");
        tiemposearchll(list, data, N, "peor");

        // Caso mejor (orden creciente)
        mejorcasoll(data, N);
        tiempoinsertll(list, data, N, "mejor");
        tiemposearchll(list, data, N, "mejor");

        // Caso promedio (valores aleatorios)
        casopromedioll(data, N);
        tiempoinsertll(list, data, N, "promedio");
        tiemposearchll(list, data, N, "promedio");
    }
}

#endif //SORTEDLINKEDLIST_H
