//
// Created by Таня Куликова on 26.09.2021.
//

#ifndef COMPUTER_SYSTEM_ARCHITECTURE_HW1_CIRCLE_H
#define COMPUTER_SYSTEM_ARCHITECTURE_HW1_CIRCLE_H
#ifndef __circle__
#define __circle__

//------------------------------------------------------------------------------
// circle.h - the header, which contains the description of the circle
//------------------------------------------------------------------------------



#include <cstdio>
# include "random.h"
#include "figure.h"

// The struct with circle parameters.

class circle:public figure {

private:

    // Coordinates of the circle center.

    int center_x;
    int center_y;

    // The radius.

    int radius;

public:

    // The constructor for initializing the circle parameters.

    circle(enum key k, enum color color, int radius, int center_x, int center_y);

    // The default destructor.

    ~circle() override;

    // The default constructor.

    circle();

    // Input of circle parameters from the file.

    virtual figure* inputFromFile(std::ifstream &file_in);

    // Random input of the circle parameters.

    virtual figure* randomInput();

    // Output to the file.

    virtual void output(std::ofstream &file_out) override;

    // Counting the square of the circle.

    virtual double square() override;
};


#endif

#endif

