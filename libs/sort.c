#include "arr_handler.h"

/* --------------- Merge sort -------------------- */

void merge(int* arr, int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* l = (int*)malloc(n1 * sizeof(int));
	int* r = (int*)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		l[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		r[j] = arr[mid + j + 1];

	i = 0; j = 0; k = left;
	while ((i < n1) && (j < n2)) {
		if (l[i] <= r[j]) {
			arr[k] = l[i];
			i++;
		}
		else {
			arr[k] = r[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = l[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = r[j];
		j++;
		k++;
	}
}

void merge_sort(int* arr, int left, int right) {
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

/* ----------------------------------------------------------------- */




/*------------------------- Selection sort ------------------------- */

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int* arr, int n) {
	int min_idx;
	for (int i = 0; i < n - 1; i++) {
		min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		swap(&arr[i], &arr[min_idx]);
	}
}

/*------------------------------------------------------------------*/

