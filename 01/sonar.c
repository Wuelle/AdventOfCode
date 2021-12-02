#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_increased = 0;
    int previous = -1;
    int current;
    FILE *fp;

    // Open the input file
    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }

    // Read the file line by line
    while(fscanf(fp, "%d\n", &current) != EOF) {
        if(previous != -1) {
            if(previous < current) {
                num_increased++;
            }
        }
        previous = current;
    }
    printf("The depth increased %d times\n", num_increased);

    fclose(fp);
    exit(EXIT_SUCCESS);
}
