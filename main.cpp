#include "bubblesort.h"
#include "mergesort.h"
#include "selectionsort.h"
#include "sortedlinkedlist.h"
#include "binarysearchtree.h"

int main() {

    printf("Para BubbleSort:\n");
    testBubbleSort();
    printf("Para SelectionSort:\n");
    testSelectionSort();
    printf("Para Mergesort:\n");
    testMergeSort();
    printf("Para BinarySearchTree:\n");
    testBinarySearchTree();
    printf("Para SortedLinkedList:\n");
    testSortedLinkedList();


    return 0;
}