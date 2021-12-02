#include <stdio.h>
#include <stdlib.h>

// Same as sonar.c, except we compare sliding averages
int main() {
    int num_increased = 0;
    int previous_1 = -1;
    int previous_2 = -1;
    int previous_3 = -1;
    int current;
    FILE *fp;

    // Open the input file
    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }

    // Read the file line by line
    while(fscanf(fp, "%d\n", &current) != EOF) {
        if(previous_1 != -1 && previous_2 != -1 && previous_3 != -1) {
            if(previous_1 + previous_2 + previous_3 < previous_2 + previous_3 + current) {
                num_increased++;
            }

        }

        // Shift values over
        previous_1 = previous_2;
        previous_2 = previous_3;
        previous_3 = current;
    }
    printf("The depth increased %d times\n", num_increased);

    fclose(fp);
    exit(EXIT_SUCCESS);
}
