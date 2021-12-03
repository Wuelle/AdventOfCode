#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_BITS 12

int main() {
    unsigned int gamma = 0;
    unsigned int i = 0;
    unsigned int n_ones[N_BITS] = {0};
    char* current = malloc(N_BITS * sizeof(char));
    FILE *fp;

    // Open the input file
    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }

    // Read the file
    while(fscanf(fp, "%12s\n", current) != EOF) {
        for(int j = 0; j < N_BITS; j++) {
            // Strings have the "wrong" bit order
            if(current[N_BITS - j - 1] == '1') {
                n_ones[j] += 1;
            }
        }
        i++;
    }

    for(int j = 0; j < N_BITS; j++) {
        if(i >> 1 < n_ones[j]) {
            gamma |= 1 << j;
        }
    }

    unsigned int mask = (1 << N_BITS) -1;

    printf("%u x %u = %u\n", 
            gamma, 
            ~gamma & mask,
            gamma * (~gamma & mask)
            );

    fclose(fp);
    exit(EXIT_SUCCESS);
}
