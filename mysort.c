#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define USE "./mysort <input file> <output file> <number of threads>"
#define BUFFER_SIZE 100

// TODO implement external sort
void mysort(char* inputFile, char* outputFile, int numThreads)
{
    char* buffer;
    FILE* fin;
    FILE* fout;

    // Open input file
    fin = fopen(inputFile, "r");
    if (fin == NULL) {
        fprintf(stderr, "fopen(%s) failed", inputFile);
        return;
    }

    // Open output file
    fout = fopen(outputFile, "w");
    if (fout == NULL) {
        fprintf(stderr, "fopen(%s) failed", outputFile);
        return;
    }

    // Allocate memory for the buffer
    buffer = (char*) malloc(sizeof(char) * BUFFER_SIZE);

    // Read the entries line by line
    // TODO sort the entries
    while (fread(&buffer[0], sizeof(char), BUFFER_SIZE, fin) == BUFFER_SIZE) {
        fwrite(&buffer[0], sizeof(char), BUFFER_SIZE, fout);
    }

    // Clear buffer and close files
    free(buffer);
    fclose(fout);
    fclose(fin);
}

int main(int argc, char** argv) {
    char* inputFile;
    char* outputFile;
    int numThreads;
    struct timeval start, end;
    double executionTime;

    if (argc != 4) {
        fprintf(stderr, USE);
        return 1;
    }

    // Read arguments
    inputFile = argv[1];
    outputFile = argv[2];
    numThreads = atoi(argv[3]);

    // Execute sort and measure execution time
    gettimeofday(&start, NULL);
    mysort(inputFile, outputFile, numThreads);
    gettimeofday(&end, NULL);
    executionTime = ((double) end.tv_sec - (double) start.tv_sec)
            + ((double) end.tv_usec - (double) start.tv_usec) / 1000000.0;
    
    printf("input file: %s\n", inputFile);
    printf("output file: %s\n", outputFile);
    printf("number of threads: %d\n", numThreads);
    printf("execution time: %lf\n", executionTime);

    return 0;
}