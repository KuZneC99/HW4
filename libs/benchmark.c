#include "arr_handler.h"

void benchmark(void) {
    int* array;
    int* array_copy;
    clock_t start, end;
    FILE *results;
    results = fopen("../results.csv", "w");
    fprintf(results, "size,merge sort,selection sort\n");

    for (int size = 0; size <= 5000; size += 50) {

        double ms_time_taken;
        double ss_time_taken;
        array_copy = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < 5; i++) {
            srand(time(NULL));
            array = arr_gen(size);

            for (int j = 0; j < size; j++)
                array_copy[j] = array[j];
            
            start = clock();
            merge_sort(array, 0, size - 1);
            end = clock();
            ms_time_taken += ((double)(end - start)) / (5 * CLOCKS_PER_SEC);

            start = clock();
            selection_sort(array, size);
            end = clock();
            ss_time_taken += ((double)(end - start)) / (5 * CLOCKS_PER_SEC);
        }
        fprintf(results, "%d,%f,%f\n", size, ms_time_taken, ss_time_taken);
    }
    fclose(results);
}