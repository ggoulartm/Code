#include <stdio.h>
#include "Tas.h"

int main() {
    // Test heap_new and heap_is_empty
    heap_t tas = heap_new(10, NULL, NULL, NULL);
    printf("Is heap empty? %d\n", heap_is_empty(tas));

    // Test heap_add
    int value1 = 10;
    int value2 = 20;
    int value3 = 30;
    heap_add(&value1, tas);
    heap_add(&value2, tas);
    heap_add(&value3, tas);

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