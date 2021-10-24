//
// Created by Таня Куликова on 26.09.2021.
//

#ifndef COMPUTER_SYSTEM_ARCHITECTURE_HW1_CONTAINER_H
#define COMPUTER_SYSTEM_ARCHITECTURE_HW1_CONTAINER_H

#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - contains the special data structure for storing figures.
//------------------------------------------------------------------------------

#include "figure.h"
#include <fstream>
#include <vector>
#define max_size 10000

//------------------------------------------------------------------------------
// The primitive container - one-dimensional array.

class  container {
public:

    // The current size of the container.

    int len;

    // The array of figures.

    figure* container[max_size];

    // Initialization of the container.

    void initialization(int n);

    // Clearing the elements of the container.

    void clear(int size);

    // Input of the container elements.

    void input(int n, std::ifstream &file_in);

    // Random input of the container elements.

    void randomInput(int size);

    // Output of the container elements to the file.

    void output(std::ofstream &f_out);

    // Function for searching the position, where to insert the element when sorting the container.

    int binarySearch(figure *fig, int left, int right);

    // Sorting the elements of container by descending order, according to the square.

    void binarySort(int n);
};



#endif

#endif
