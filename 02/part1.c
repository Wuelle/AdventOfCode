#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OP_SIZE 10

int main() {
    int val;
    char op[MAX_OP_SIZE];
    int depth = 0;
    int pos = 0;

    FILE *fp;

    // Open the input file
    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }

    // Read the file line by line
    while(fscanf(fp, "%s %d\n", op, &val) != EOF) {
        if(strcmp(op, "forward") == 0) {
            pos += val;
        }
        else if(strcmp(op, "up") == 0) {
            depth -= val;
        }
        else if(strcmp(op, "down") == 0) {
            depth += val;
        }
    }
    printf("%d\n", depth * pos);

    fclose(fp);
    exit(EXIT_SUCCESS);
}
