#include <stdio.h>
#include <stdlib.h>

void enumerate(int, int, int *);

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Correct usage: ./%s <positive_int>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);
    if (n < 1) {
        fprintf(stderr, "Number has to be a positive integer.\n");
        return EXIT_FAILURE;
    }
    printf("Enumerating through [1..%d]\n", n);

    int *seen_set = calloc(n, sizeof(int));
    if (seen_set == NULL) {
        fprintf(stderr, "enumerate: failed to allocate seen_set\n");
        return EXIT_FAILURE;
    }
    enumerate(1, n, seen_set);
    return 0;
}

void do_stuff_on_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void do_stuff_on_subset(int *arr, int *seen_set, int n) {
    for (int i = 0; i < n; i++) {
        if (seen_set[i]) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Common recursive enumeration problems - "exhaustive search" */

void subsets(int i, int n, int *arr, int *seen_set) {
    if (i == n) {
        do_stuff_on_subset(arr, seen_set, n);
    }
    seen_set[i] = 0;
    subsets(i+1, n, arr, seen_set);
    seen_set[i] = 1;
    subsets(i+1, n, arr, seen_set);
}

void bruteforce(int curr_index, int n, int *arr) {
    if (curr_index == n-1) {
        do_stuff_on_array(arr, n);
    }
    for (int i = curr_index; i < n; i++) {
        swap(arr, curr_index, i);
        bruteforce(curr_index+1, n, arr);
        swap(arr, curr_index, i);
    }
}