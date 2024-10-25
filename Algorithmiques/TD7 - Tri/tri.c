#include "tri.h"


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Quick Sort
void Qsort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        Qsort(arr, low, pi - 1);
        Qsort(arr, pi + 1, high);
    }
}

void quicksort(vect_t tab) {
    Qsort(tab->data, 0, tab->actual_size - 1);
}

// Merge Sort
void fusion(vect_t tab, vect_t tmp, size_t gauche, size_t droit) {
    size_t milieu = (gauche + droit) / 2;
    size_t i = gauche;
    size_t j = milieu + 1;
    size_t k = gauche;

    while (i <= milieu && j <= droit) {
        if (tab->data[i] <= tab->data[j]) {
            tmp->data[k++] = tab->data[i++];
        } else {
            tmp->data[k++] = tab->data[j++];
        }
    }

    while (i <= milieu) {
        tmp->data[k++] = tab->data[i++];
    }

    while (j <= droit) {
        tmp->data[k++] = tab->data[j++];
    }

    for (i = gauche; i <= droit; i++) {
        tab->data[i] = tmp->data[i];
    }
}

void _trifusionrec(vect_t tab, vect_t tmp, size_t gauche, size_t droit) {
    if (gauche < droit) {
        size_t milieu = (gauche + droit) / 2;
        _trifusionrec(tab, tmp, gauche, milieu);
        _trifusionrec(tab, tmp, milieu + 1, droit);
        fusion(tab, tmp, gauche, droit);
    }
}

// Merge Sort
void merge_sort(vect_t tab) {
    vect_t tmp = vect_new(tab->actual_size, NULL, NULL, NULL);
    if (tmp->data != NULL) {
        _trifusionrec(tab, tmp, 0, tab->actual_size - 1);
        vect_delete(tmp);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void hsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void heap_sort(vect_t tab) {
    hsort(tab->data, tab->actual_size);
}