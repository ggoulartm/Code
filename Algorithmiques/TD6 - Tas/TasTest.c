#include <stdio.h>
#include "Tas.h"



int main() {
    // Test heap_new and heap_is_empty
    heap_t tas = heap_newD(10);
    printf("Is heap empty? %d\n", heap_is_empty(tas));

    // Test heap_add
    // Add random values to the heap
    int random_values[] = {20, 2, 15, 10, 8, 7, 6, 9, 5, 1};
    
    for(int i = 0; i < 10; i++) {
        heap_add(&random_values[i], tas);
    }

    // Print heap
    heap_printf(tas);

    // Test heap_get_extrema
    int* extrema = heap_get_extrema(tas);
    printf("Extrema: %d\n", *extrema);

    // Test heap_delete_extrema
    heap_delete_extrema(tas);
    extrema = heap_get_extrema(tas);
    printf("New extrema: %d\n", *extrema);

    // Test heap_verification
    int verification_result = heap_verification(tas);
    printf("Heap verification result: %d\n", verification_result);

    // Test heap_delete
    heap_t deleted_tas = heap_delete(tas);
    printf("Is deleted heap empty? %d\n", heap_is_empty(deleted_tas));

    return 0;
}