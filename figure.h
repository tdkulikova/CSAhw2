//
// Created by Таня Куликова on 26.09.2021.
//

#ifndef COMPUTER_SYSTEM_ARCHITECTURE_HW1_FIGURE_H
#define COMPUTER_SYSTEM_ARCHITECTURE_HW1_FIGURE_H
#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// figure.h - contains the description of the base class figure,
//------------------------------------------------------------------------------

#include <cstdio>
#include <fstream>


//------------------------------------------------------------------------------
// The class, which describes all figures.

class figure {

public:

    // Values of key for every figure.

    enum key {
        RECTANGLE,
        TRIANGLE,
        CIRCLE
    };

    // The key.

    key key;

    // The enum of the figure colors.

    enum color {
        RED = 1,
        ORANGE,
        YELLOW,
        GREEN,
        CYAN,
        BLUE,
        PURPLE
    };
    color color;

    figure(enum key k, enum color color);

    // The default constructor.

    figure();

    // The default destructor.

    virtual ~figure();

    // Inputting the parameters of the figure.

    static figure* inputFromFile(std::ifstream &file_in);

    // Inputting the color of the figure.

    static void inputColor(figure*figure, int color);

    // Random input of the figure.

    static figure* randomInput();

    // Output the figure to the file.

    virtual void output(std::ofstream& file_out);

    // Defining the color of the figure and outputting it.

    void outputColor(std::ofstream &file_out);

    // Counting the square of the figure.

    virtual double square();
};


#endif

#endif
