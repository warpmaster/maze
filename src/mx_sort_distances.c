#include "minilibmx.h"

void mx_sort_distances(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i-1]) {
            int index = i;
            int current = arr[i];

            for (; index > 0 && current < arr[index-1]; index--) {
                arr[index] = arr[index-1];
            }
            arr[index] = current;
        }
    }
    return;
}
