//
// Created by Таня Куликова on 26.09.2021.
//

#include "container.h"
#include <iostream>

//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Container initialization.

void container::initialization(int size) {
    len = 0;
    for (int i = 0; i < size; ++i) {
        container[i] = new figure;
    }
}

//------------------------------------------------------------------------------
// Clearing the containers from the elements.

void container::clear(int size) {
    for (int i = 0; i < size; ++i) {
        delete container[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Inputting figures from the file to the container.

void container::input(int size, std::ifstream &file_in) {
    for (int i = 0; i < size; ++i) {
        try {
            if (!file_in.eof()) {
                container[i] = figure::inputFromFile(file_in);
                len++;
            }
        } catch (int a) {}
    }
}

//------------------------------------------------------------------------------
// Input of the random figures to the container.

void container::randomInput(int size) {
    while (len < size) {
        try {
            container[len] = figure::randomInput();
            ++len;
        } catch (int a) {}
    }
}

//------------------------------------------------------------------------------
// Output of the container figures.

void container::output(std::ofstream &file_out) {
    file_out << "Container contains " << len << " elements.\n";
    for (int i = 0; i < len; ++i) {
        container[i]->output(file_out);
        container[i]->outputColor(file_out);
    }
}

//--------------------------------------------------------------------------------------------
// Function for searching the position, where to insert the element when sorting the container.

int container::binarySearch(figure *fig, int left, int right) {
    if (right <= left) {
        return (fig->square() < container[left]->square() ? (left + 1) : left);
    }
    int middle = (left + right) / 2;
    if (fig->square() == container[middle]->square()) {
        return middle + 1;
    }
    if (fig->square() < container[middle]->square()) {
        return binarySearch(fig, middle + 1, right);
    }
    return binarySearch(fig, left, middle - 1);
}

// -------------------------------------------------------------------------------------------
// Function for sorting the container by descending order.

void container::binarySort(int size) {
    int i, position, right_bound;
    figure *selected_figure;
    for (i = 1; i < size; ++i) {
        right_bound = i - 1;
        selected_figure = container[i];

        // Searching for the position where selected figure should be inserted.

        position = binarySearch(selected_figure, 0, right_bound);

        // Move all elements after location to create space for inserting the element.

        while (right_bound >= position) {
            container[right_bound + 1] = container[right_bound];
            --right_bound;
        }
        container[right_bound + 1] = selected_figure;
    }
}


