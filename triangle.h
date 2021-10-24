//
// Created by Таня Куликова on 26.09.2021.
//

#ifndef COMPUTER_SYSTEM_ARCHITECTURE_HW1_TRIANGLE_H
#define COMPUTER_SYSTEM_ARCHITECTURE_HW1_TRIANGLE_H

#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - this is the header for describing the triangle.
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "random.h"
#include "figure.h"

//------------------------------------------------------------------------------
// The struct with triangle parameters (coordinates of each angle).


class triangle: public figure {
private:

    int ax;
    int ay;
    int bx;
    int by;
    int cx;
    int cy;

public:

    triangle(enum key k, enum color color, int ax, int ay, int bx, int by, int cx,int cy);
    triangle();
    ~triangle() override;

    // Inputting parameters from file.

    figure* inputFromFile(ifstream &file_in);


    // Random input of the triangle parameters.

    figure* randomInput();

    // Output to the file.

    virtual void output(ofstream &file_out) override;

    // Counting the triangle square.

    virtual double square() override;
};


#endif

#endif
