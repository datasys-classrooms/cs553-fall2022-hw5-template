#include <iostream>
#include <string>
#include <array>
#include <cstdio>
#include <chrono>

#define USE "./mysort <input file> <output file> <number of threads>"
#define BUFFER_SIZE 100

// TODO implement sorting
class MySort
{
    private:
        std::string inputFile;
        std::string outputFile;
        int num_threads;
    
    public:
        explicit MySort(std::string inputFile, std::string outputFile, int num_threads) :
            inputFile(inputFile), outputFile(outputFile), num_threads(num_threads) { }
        virtual ~MySort() = default;

        void sort();
        
};

void MySort::sort()
{
    std::array<char, BUFFER_SIZE> buffer;
    std::FILE* fin = std::fopen(inputFile.c_str(), "r");
    std::FILE* fout = std::fopen(outputFile.c_str(), "w");

    while (std::fread(&buffer[0], sizeof(buffer[0]), buffer.size(), fin) == BUFFER_SIZE) {
        std::fwrite(&buffer[0], sizeof(buffer[0]), buffer.size(), fout);
        // TODO extrac elements and sort them
    }

    std::fclose(fin);
    std::fclose(fout);
}

int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << USE << std::endl;
        return 1;
    }

    std::string inputFile(argv[1]);
    std::string outputFile(argv[2]);
    int numThreads(std::stoi(std::string(argv[3])));
    MySort mysort(inputFile, outputFile, numThreads);

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<double> diff;
    double exec_time = 0.0;

    start = std::chrono::high_resolution_clock::now();
    mysort.sort();
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    exec_time = diff.count();

    std::cout << "input file: " << inputFile << std::endl;
    std::cout << "output file: " << outputFile << std::endl;
    std::cout << "number of threads: " << numThreads << std::endl;
    std::cout << "execution time: " << exec_time << " seconds" << std::endl;

    return 0;
}