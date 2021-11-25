#include "arr_handler.h"


void get_settings(int* lower_lim, int* upper_lim, int* step, int* retries) {
    FILE *settings;
    settings = fopen("../benchmark_settings.txt", "r");
    fscanf(settings, "%*[^\n]\n");
    fscanf(settings, "%*[^\n]\n");
    fscanf(settings, "%d\n", lower_lim);
    fscanf(settings, "%*[^\n]\n");
    fscanf(settings, "%d\n", upper_lim);
    fscanf(settings, "%*[^\n]\n");
    fscanf(settings, "%d\n", step);
    fscanf(settings, "%*[^\n]\n");
    fscanf(settings, "%d\n", retries);
}

void benchmark(void) {
    int* array;
    int* array_copy;
    clock_t start, end;

    FILE *results;
    results = fopen("../results.csv", "w");
    fprintf(results, "size,merge sort,selection sort\n");

    int lower_lim, upper_lim, step, retries;
    get_settings(&lower_lim, &upper_lim, &step, &retries);


    for (int size = lower_lim; size <= upper_lim; size += step) {

        double ms_time_taken = 0;
        double ss_time_taken = 0;
        double ms_res, ss_res;
        array_copy = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < retries; i++) {
            srand(time(NULL));
            array = arr_gen(size);

            for (int j = 0; j < size; j++)
                array_copy[j] = array[j];
            
            start = clock();
            merge_sort(array, 0, size - 1);
            end = clock();
            ms_time_taken += (end - start);

            start = clock();
            selection_sort(array, size);
            end = clock();
            ss_time_taken += (end - start);
        }

        ms_res = (double)ms_time_taken / (retries * CLOCKS_PER_SEC);
        ss_res = (double)ss_time_taken / (retries * CLOCKS_PER_SEC);
        fprintf(results, "%d,%f,%f\n", size, ms_res, ss_res);
    }

    fclose(results);

    system("python3 ../plots.py");
}