//
// Created by Таня Куликова on 26.09.2021.
//

//------------------------------------------------------------------------------
// rectangle.cpp - contains functions for working with the rectangle.
//------------------------------------------------------------------------------

#include "rectangle.h"

//------------------------------------------------------------------------------
// Default constructor.

rectangle::rectangle() = default;

//------------------------------------------------------------------------------
// The default destructor.

rectangle::~rectangle() = default;

//------------------------------------------------------------------------------
// The constructor for initializing rectangle parameters.

rectangle::rectangle(enum key k, enum color color, int left_up_x, int left_up_y, int right_down_x, int right_down_y)
        : figure(k, color) {
    this->left_up_x = left_up_x;
    this->left_up_y = left_up_y;
    this->right_down_x = right_down_x;
    this->right_down_y = right_down_y;
}
//------------------------------------------------------------------------------
// Inputting of the rectangle parameters.

figure *rectangle::inputFromFile(std::ifstream &file_in) {
    file_in >> left_up_x >> left_up_y >> right_down_x >> right_down_y;
    return new rectangle(figure::RECTANGLE, figure::RED, left_up_x, left_up_y, right_down_x, right_down_y);
}

//------------------------------------------------------------------------------
// Random inputting of the rectangle parameters.

figure *rectangle::randomInput() {
    do {
        left_up_x = Random();
        left_up_y = Random();
        right_down_x = Random();
        right_down_y = Random();
    } while (left_up_x == right_down_x || left_up_y == right_down_y);
    return new rectangle(figure::RECTANGLE, figure::RED, left_up_x, left_up_y, right_down_x, right_down_y);
}

//------------------------------------------------------------------------------
// Outputting of the rectangle parameters.

void rectangle::output(std::ofstream &file_out) {

    if (right_down_x != left_up_x && right_down_y != left_up_y) {
        file_out << "It is Rectangle:\nA = " << abs(left_up_y - right_down_y) << " B = "
                 << abs(right_down_x - left_up_x) << " Square = " << square();
    } else {
        file_out << "It is Rectangle:\n" << "Something wrong with rectangle coordinates! " << " Square = "
                 << square();
    }
}

//------------------------------------------------------------------------------
// Counting the rectangle square.

double rectangle::square() {
    return abs(left_up_y - right_down_y) * abs(right_down_x - left_up_x);
}

