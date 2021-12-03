#include <stdio.h>
#include <stdlib.h>

#define N_LINES 1000
#define N_BITS 12

typedef unsigned int uint;

// Compute the most common bit A`s elements at ix bit_ix
// Move all values with that bit at bit_ix into B and return their count
// (optionally invert the filter using the invert argument)
uint split(uint A[], uint B[], uint len, uint bit_ix, uint invert) {
    uint num_ones = 0;
    for(int i = 0; i < len; i++) {
        if ((A[i] >> bit_ix) & 1 == 1) {
            num_ones++;
        }
    }

    // fuck readability
    uint filter = num_ones > (len - 1) / 2;
    filter ^= invert;

    uint k = 0;
    for(uint i = 0; i < len; i++) {
        if (((A[i] >> bit_ix) & 1) == filter) {
            B[k++] = A[i];
        }
    }
    return k;
}

// Copy a slice from A into B
void copy(uint A[], uint B[], uint start, uint end) {
    for(int i = start; i < end; i++) {
        B[i] = A[i];
    }
}

int main() {
    uint nums[N_LINES] = {0};
    uint store[N_LINES] = {0};
    uint save[N_LINES] = {0};
    char* current = malloc(N_BITS * sizeof(char));
    FILE *fp;
    uint oxygen_generator, co2_scrubber;

    // Open the input file
    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }

    // Read the file
    int i = 0;
    while(fscanf(fp, "%12s\n", current) != EOF) {
        nums[i] = (int)strtol(current, NULL, 2);
        i++;
    }
    copy(nums, save, 0, N_LINES);
    
    // Get the oxygen generator rating
    uint max = N_LINES;
    for(int bit_ix = N_BITS - 1; bit_ix >= 0; bit_ix--) {
        max = split(nums, store, max, bit_ix, 0);
        copy(store, nums, 0, max);
        if(max == 1) {
            break;
        }
    }
    oxygen_generator = nums[0];

    // Get the Co2 Scrubber rating
    max = N_LINES;
    for(int bit_ix = N_BITS - 1; bit_ix >= 0; bit_ix--) {
        max = split(save, store, max, bit_ix, 1);
        copy(store, save, 0, max);
        if(max == 1) {
            break;
        }
    }
    co2_scrubber = save[0];

    printf("Oxygen: %u\nCo2: %u\nProduct: %u\n", oxygen_generator, co2_scrubber, oxygen_generator * co2_scrubber);

    fclose(fp);
    exit(EXIT_SUCCESS);
}
