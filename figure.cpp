//
// Created by Таня Куликова on 26.09.2021.
//

#include "figure.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include <iostream>

//------------------------------------------------------------------------------
// figure.cpp - contains functions for working with the base figure.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// The constructor for initializing figure parameters.

figure::figure(enum key k, enum color color) {
    this->key = k;
    this->color = color;
}

//------------------------------------------------------------------------------
// The default constructor.

figure::figure() = default;

//------------------------------------------------------------------------------
// The default destructor.

figure::~figure() = default;

//------------------------------------------------------------------------------
// Inputting the base figure parameters.

figure *figure::inputFromFile(ifstream &file_in) {
    int figure_key = 0;
    file_in >> figure_key;
    int col = 0;
    switch (figure_key) {
        case 1: {
            enum key k = figure::RECTANGLE;
            auto *rect = new rectangle;
            rect->inputFromFile(file_in);
            auto *fig = rect;
            fig->key = k;
            file_in >> col;
            inputColor(fig, col);
            return fig;
        }
        case 2: {
            enum key k = figure::TRIANGLE;
            auto *tr = new triangle;
            tr->inputFromFile(file_in);
            auto *fig = tr;
            fig->key = k;
            file_in >> col;
            inputColor(fig, col);
            return fig;
        }
        case 3: {
            enum key k = figure::CIRCLE;
            auto *circ = new circle;
            circ->inputFromFile(file_in);
            auto *fig = circ;
            file_in >> col;
            fig->key = k;
            inputColor(fig, col);
            return fig;
        }

        default: {
            printf("Something wrong in the file. Incorrect figure.");
            exit(0);
        }
    }
}

// --------------------------------------------------------------------------
// Random input of the base figure.

void figure::inputColor(figure *fig, int color) {
    if (color == 1)
        fig->color = figure::RED;
    else if (color == 2)
        fig->color = figure::ORANGE;
    else if (color == 3)
        fig->color = figure::YELLOW;
    else if (color == 4)
        fig->color = figure::GREEN;
    else if (color == 5)
        fig->color = figure::CYAN;
    else if (color == 6)
        fig->color = figure::BLUE;
    else if (color == 7)
        fig->color = figure::PURPLE;
    else fig->color = figure::RED;
}

//------------------------------------------------------------------------
// Forming a random figure.

figure *figure::randomInput() {
    auto *fig = new figure;
    int figure_key = rand() % 3 + 1;
    int col = rand() % 6 + 1;
    switch (figure_key) {
        case 1: {
            enum key k = figure::RECTANGLE;
            auto *rect = new rectangle;
            rect->randomInput();
            fig = rect;
            fig->key = k;
            inputColor(fig, col);
            break;
        }
        case 2: {
            enum key k = figure::TRIANGLE;
            auto *tr = new triangle;
            tr->randomInput();
            fig = tr;
            fig->key = k;
            inputColor(fig, col);
            break;
        }
        case 3: {
            enum key k = figure::CIRCLE;
            auto *circ = new circle;
            circ->randomInput();
            fig = circ;
            fig->key = k;
            inputColor(fig, col);
            break;
        }
        default:
            break;
    }
    return fig;
}

//------------------------------------------------------------------------------
// Outputting of the base figure parameters.

void figure::output(ofstream &file_out) {
    if (key >= 1 && key <= 3) {
        output(file_out);
        outputColor(file_out);
    } else {
        printf("Incorrect figure!");
    }
}

// -------------------------------------------------------------------------------
// Outputting the figure color.

void figure::outputColor(std::ofstream &file_out) {
    if (color == figure::BLUE)
        file_out << " Color = BLUE";
    if (color == figure::CYAN)
        file_out << " Color = CYAN";
    if (color == figure::GREEN)
        file_out << " Color = GREEN";
    if (color == figure::PURPLE)
        file_out << " Color = PURPLE";
    if (color == figure::YELLOW)
        file_out << " Color = YELLOW";
    if (color == figure::ORANGE)
        file_out << " Color = ORANGE";
    if (color == figure::RED)
        file_out << " Color = RED";
    file_out << "\n";
}

//------------------------------------------------------------------------------
// Counting the figure square.

double figure::square() {
    if (key >= 1 && key <= 3) {
        return square();
    } else return 0.0;
}
