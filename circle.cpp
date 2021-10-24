//
// Created by Таня Куликова on 26.09.2021.
//

#include "circle.h"
#include <cmath>
#include <iostream>

//------------------------------------------------------------------------------
// circle.cpp - contains functions for working with circle.
//------------------------------------------------------------------------------

// The default constructor.

circle::circle() = default;

// The default destructor.

circle::~circle() = default;

// The constructor for initializing the circle parameters.

circle::circle(enum key k, enum color color, int radius, int center_x, int center_y) : figure(k, color) {
    this->radius = radius;
    this->center_x = center_x;
    this->center_y = center_y;
}
//------------------------------------------------------------------------------
// Inputting the circle parameters.

figure *circle::inputFromFile(std::ifstream &file_in) {
    file_in >> center_x >> center_y >> radius;
    return new circle(figure::CIRCLE, figure::RED, radius, center_x, center_y);
}

// Random input of the circle parameters.

figure *circle::randomInput() {
    do {
        center_x = Random();
        center_y = Random();
        radius = Random();
    } while (radius <= 0);
    return new circle(figure::CIRCLE, figure::RED, radius, center_x, center_y);
}
//------------------------------------------------------------------------------
// Outputting the circle parameters.

void circle::output(std::ofstream &file_out) {

    if (radius > 0) {
        file_out << "It is Circle:\n" << "Center coordinates: x = " << center_x << " y = " <<
                 center_y << " Radius = " << radius << " Square = " << square();
    } else {
        file_out << "It is Circle:\n" << "There is an error. Radius can not be negative or zero." <<
                 " Square = " << square();
    }
}

//------------------------------------------------------------------------------
// Counting the circle square.

double circle::square() {
    if (radius > 0) {
        return M_PI * radius * radius;
    } else {
        return 0.0;
    }
}


