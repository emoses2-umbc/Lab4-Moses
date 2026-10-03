#include <stdio.h>
#include <stdlib.h>

extern int sum_array(const int *arr, int count);

int main(int argc, char* argv[]){
    if (argc != 2){
        fprintf(stderr, "Missing Filename\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    if(!f){
        perror(argv[1]);
        return 1;
    }

    int capacity = 16, count = 0;
    int *arr = malloc(capacity * sizeof *arr);
    if(!arr){
        fclose(f);
        return 1;
    }
    
    int n;
    while (fscanf(f, "%d", &n) == 1) {
        if (count == capacity) {
            capacity *= 2;
            int *tmp = realloc(arr, capacity * sizeof *arr);
            if (!tmp) {
                free(arr);
                fclose(f);
                return 1;
            }
            arr = tmp;
        }
        arr[count++] = n;
    }
    fclose(f);

    int total = sum_array(arr, count);
    printf("Sum: %d\n", total);
    free(arr);
    return 0;
}