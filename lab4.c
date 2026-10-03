#include <stdio.h>

int COUNT = 51;

extern int sum_array(const int *arr, int count);

int main(int argc, char* argv[]){
    if (argc != 2){
        fprintf(stderr, "Missing Filename\n");
        return 1;
    }

    int count = strtol(argv[2]);
    if (count <= 0){
        fprintf(stderr, "Count must be a positive integer\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    if(!f){
        perror(argv[1]);
        return 1;
    }

    int *arr = malloc(count*sizeof*arr);
    if(!arr){
        fclose(f);
        return 1;
    }
    
    for (int i = 0; i < count; i++) {
        if (fscanf(f, "%d", &arr[i]) != 1) {
            fprintf(stderr, "Expected %d numbers, got %d\n", count, i);
            free(arr);
            fclose(f);
            return 1;
        }
    }
    fclose(f);

    int total = sum_array(arr, count);
    printf("Sum: %d\n", total);
    return 0;
}