#include "bubblesort.h"
#include "mergesort.h"
#include "selectionsort.h"

int main() {

    printf("Para BubbleSort:\n");
    testBubbleSort();
    printf("Para SelectionSort:\n");
    testSelectionSort();
    printf("Para Mergesort:\n");
    testMergeSort();

    return 0;
}