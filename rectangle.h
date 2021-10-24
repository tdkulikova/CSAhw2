//
// Created by Таня Куликова on 26.09.2021.
//

#ifndef COMPUTER_SYSTEM_ARCHITECTURE_HW1_RECTANGLE_H
#define COMPUTER_SYSTEM_ARCHITECTURE_HW1_RECTANGLE_H
#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - the header, which contains the description of the rectangle
//------------------------------------------------------------------------------

#include<cstdio>
# include "random.h"
#include "figure.h"

// The struct with rectangle parameters.

class rectangle: public figure {
private:
    // Coordinates of the upside left point and the downside right point.

    int left_up_x;
    int left_up_y;
    int right_down_x;
    int right_down_y;

public:

    // Default constructor.

    rectangle();

    // The default destructor.

    ~rectangle() override;

    // The constructor for initializing rectangle parameters.

    rectangle(enum key k, enum color color, int left_up_x,int left_up_y, int right_down_x, int right_down_y);

    // Input of rectangle parameters from the file.

    figure* inputFromFile(std::ifstream &file_in);

    // Random input of the rectangle parameters.

    figure* randomInput();

    // Output to the file.

    virtual void output(std::ofstream &file_out) override;

    // Counting the square of the rectangle.

    virtual double square() override;
};


#endif

#endif
