//------------------------------------------------------------------------------
// main.cpp - contains the main function
//------------------------------------------------------------------------------

#include <iostream>
#include "container.h"
#include <ctime>
#include <cstdlib>


void output(container &container, std::ofstream &file_out, int size);

//------------------------------------------------------------------------------
// The main function. Here the dialog with the user is organised.

int main() {
    unsigned int start_time = clock();
    std::ifstream file_in;
    file_in.open("tests.txt", std::ios::in);
    int size = 10001;
    container cont{};
    std::ofstream file_out;
    file_out.open("output.txt", std::ios::out);
    int command_number;
    std::cout << "1 - input from file\n" << "2 - random input\n" << "Choose the way of data input:\n";
    std::cin >> command_number;
    if (command_number == 2) {
        printf("Input the seed for generation\n");
        int seed;
        std::cin >> seed;
        srand(seed);
        size = rand() % 10001;
        cont.initialization(size);
        cont.randomInput(size);
        output(cont, file_out, size);
    } else if (command_number == 1) {
        while (!file_in.eof()) {
            file_in >> size;
            if ((size < 0) || (size > 10000)) {
                file_out << "incorrect number of figures = " << size;
                std::cout << "Set 0 < number <= 10000\n";
                return 3;
            }
            cont.initialization(size);
            cont.input(size, file_in);
            output(cont, file_out, size);
            file_out << "\n";
        }
    } else {
        printf("Incorrect command!");
    }
    file_in.close();
    file_out.close();
    unsigned int end_time = clock();
    unsigned int time = end_time - start_time;
    std::cout << "Time: " << time << " ms";
    return 0;
}

// Function, which calls functions for outputting container and sorting container.

void output(container &c, std::ofstream &file_out, int size) {
    c.output(file_out);
    c.binarySort(size);
    file_out << "\n" << "Sorted container:\n";
    for (int i = 0; i < size; ++i) {
        c.container[i]->output(file_out);
        c.container[i]->outputColor(file_out);
    }
    c.clear(size);
}