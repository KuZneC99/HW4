#include "arr_handler.h"

void single_array(void) {
    FILE *output;
    output = fopen("../results.txt", "w");
    int size;
    printf("\nEnter the number of array elements: ");
    scanf("%d", &size);
    printf("\n");
    
    int* array;
    int* array_copy;
    clock_t start, end;
    double time_taken;

    srand(time(NULL));

    array = arr_gen(size);

    for (int i = 0; i < size; i++)
        fprintf(output, "%d\n", array[i]);
    fprintf(output, "\n\n");

    array_copy = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        array_copy[i] = array[i];
        
    start = clock();
    merge_sort(array, 0, size - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by merge sort: %f\n", time_taken);

    start = clock();
    selection_sort(array_copy, size);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by selection sort: %f\n\n", time_taken);

    for (int i = 0; i < size; i++)
        fprintf(output, "%d\n", array[i]);

    fclose(output);
}