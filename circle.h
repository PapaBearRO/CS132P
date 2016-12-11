#pragma once

#include "common.h"

int circle_main(int argc, char** argv);
int filled_circle_main(int argc, char** argv);

int cylinder_main(int argc, char** argv);

void print_circle(position_t* pos, double size);
void print_filled_circle(position_t* pos, double size);

void print_cylinder(position_t* pos, double size);
#include "circle.h" 
