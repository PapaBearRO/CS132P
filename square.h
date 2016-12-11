#pragma once

#include "common.h"

int square_main(int argc, char** argv);
int filled_square_main(int argc, char** argv);

int cube_main(int argc, char** argv);

void print_square(position_t* pos, double size);
void print_filled_square(position_t* pos, double size);

void print_cube(position_t* pos, double size);
