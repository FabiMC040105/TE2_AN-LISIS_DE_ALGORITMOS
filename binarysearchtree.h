#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <chrono>
#include <vector>
#include <functional>

using namespace std;

// Nodo del árbol binario de búsqueda
template<typename T>
struct BSTNode {
    T data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// Definición del Binary Search Tree (BST)
template<typename T>
class BinarySearchTree {
private:
    BSTNode<T>* root;  // Raíz del árbol

    // Función auxiliar para insertar un valor en el BST
    BSTNode<T>* insert(BSTNode<T>* node, T value) {
        if (node == nullptr) {
            return new BSTNode<T>(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Función auxiliar para buscar un valor en el BST
    bool search(BSTNode<T>* node, T value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    // Función auxiliar para eliminar todos los nodos del BST
    void clear(BSTNode<T>* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Destructor
    ~BinarySearchTree() {
        clear(root);
    }

    // Inserta un valor en el BST
    void insert(T value) {
        root = insert(root, value);
    }

    // Busca un valor en el BST
    bool search(T value) {
        return search(root, value);
    }

    // Limpia el árbol
    void clear() {
        clear(root);
        root = nullptr;
    }
};

// Función para generar el peor caso (valores en orden inverso)
template<typename T>
void peorcasobst(vector<T>& data, int n) {
    data.clear();
    for (int i = 0; i < n; i++) {
        data.push_back(n - i);  // Orden inverso
    }
}

// Función para generar el mejor caso (valores ya ordenados)
template<typename T>
void mejorcasobst(vector<T>& data, int n) {
    data.clear();
    for (int i = 0; i < n; i++) {
        data.push_back(i);  // Orden creciente
    }
}

// Función para generar un caso promedio (valores aleatorios)
template<typename T>
void casopromediobst(vector<T>& data, int n) {
    data.clear();
    for (int i = 0; i < n; i++) {
        data.push_back(rand() % 1000);  // Valores aleatorios
    }
}

// Función para medir el tiempo de ejecución de la inserción
template<typename T>
void tiempoinsertbst(BinarySearchTree<T>& tree, vector<T>& data, int n, const string& caseType) {
    tree.clear();
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        tree.insert(data[i]);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Tiempo de insercion para el " << caseType << " caso con N=" << n << ": " << duration.count() << " segundos." << endl;
}

// Función para medir el tiempo de ejecución de la búsqueda
template<typename T>
void tiemposearchbst(BinarySearchTree<T>& tree, vector<T>& data, int n, const string& caseType) {
    auto start = chrono::high_resolution_clock::now();

    // Búsqueda del último valor como peor caso
    bool found = tree.search(data[n - 1]);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Tiempo de busqueda para el " << caseType << " caso con N=" << n << ": " << duration.count() << " segundos." << endl;
}

// Función para realizar pruebas con el Binary Search Tree (BST)
void testBinarySearchTree() {
    BinarySearchTree<int> tree;
    vector<int> data;
    const int N_vals[] = {100, 1000, 5000, 10000};  // Diferentes valores de N
    int num_tests = sizeof(N_vals) / sizeof(N_vals[0]);

    for (int i = 0; i < num_tests; i++) {
        int N = N_vals[i];

        // Caso peor (orden inverso)
        peorcasobst(data, N);
        tiempoinsertbst(tree, data, N, "peor");
        tiemposearchbst(tree, data, N, "peor");

        // Caso mejor (orden creciente)
        mejorcasobst(data, N);
        tiempoinsertbst(tree, data, N, "mejor");
        tiemposearchbst(tree, data, N, "mejor");

        // Caso promedio (valores aleatorios)
        casopromediobst(data, N);
        tiempoinsertbst(tree, data, N, "promedio");
        tiemposearchbst(tree, data, N, "promedio");
    }
}

#endif //BINARYSEARCHTREE_H
