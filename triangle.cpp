//
// Created by Таня Куликова on 26.09.2021.
//


#include "triangle.h"
#include <cmath>

//------------------------------------------------------------------------------
// triangle.cpp - contains functions for working with triangle.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Default constructor.

triangle::triangle() = default;

//------------------------------------------------------------------------------
// Default destructor.

triangle::~triangle() = default;

//------------------------------------------------------------------------------
// The constructor for initializing triangle parameters.

triangle::triangle(enum key k, enum color color, int ax, int ay, int bx, int by, int cx, int cy) : figure(k, color) {
    this->ax = ax;
    this->ay = ay;
    this->bx = bx;
    this->by = by;
    this->cx = cx;
    this->cy = cy;
}

//------------------------------------------------------------------------------
// Inputting the parameters of the triangle.

figure *triangle::inputFromFile(ifstream &file_in) {
    file_in >> ax >> ay >> bx >> by >> cx >> cy;
    return new triangle(figure::TRIANGLE, figure::RED, ax, ay, bx, by, cx, cy);
}

//------------------------------------------------------------------------------
// Random inputting of the triangle parameters.

figure *triangle::randomInput() {
    double a;
    double b;
    double c;
    do {
        ax = Random();
        ay = Random();
        bx = Random();
        by = Random();
        cx = Random();
        cy = Random();
        a = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
        b = sqrt(pow(cx - bx, 2) + pow(cy - by, 2));
        c = sqrt(pow(cx - ax, 2) + pow(cy - ay, 2));

    } while ((c >= (a + b))
             || (a >= (b + c))
             || (b >= (c + a)));
    return new triangle(figure::TRIANGLE, figure::RED, ax, ay, bx, by, cx, cy);
}
//------------------------------------------------------------------------------
// Outputting of the triangle parameters.

void triangle::output(ofstream &file_out) {

    double a = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
    double b = sqrt(pow(cx - bx, 2) + pow(cy - by, 2));
    double c = sqrt(pow(cx - ax, 2) + pow(cy - ay, 2));
    if (a < b + c && b < a + c && c < a + b) {
        file_out << "It is Triangle:\nA = " << a << " B = " << b << " C = " << c << " Square = "
                 << square();
    } else {
        file_out << "It is Triangle:\n" << "Something wrong with triangle coordinates! " << " Square = "
                 << 0.0;
    }
}

//------------------------------------------------------------------------------
// Counting the triangle square.

double triangle::square() {
    double a = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
    double b = sqrt(pow(cx - bx, 2) + pow(cy - by, 2));
    double c = sqrt(pow(cx - ax, 2) + pow(cy - ay, 2));
    if (a < b + c && b < a + c && c < a + b) {
        return 0.5 * abs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
    } else {
        return 0.0;
    }
}
