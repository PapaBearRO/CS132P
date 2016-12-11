#include "line.h"

#include "common.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

float extrusionFormula(position_t* from, const position_t* to);

int line_main(int argc, char** argv)
{
	printf(" ; Generating a line\n");

	if (argc != 6)
	{
		fprintf(stderr, "Invalid number of arguments (%d)\n", argc);
		return 1;
	}

	position_t from, to;

	// C structs need to be initialised to some default values.
	// Here we set them to 0.
	init_position(&from);
	init_position(&to);

	// Convert the string provided on the command line to a double.
	from.x = strtod(argv[2], NULL);
	from.y = strtod(argv[3], NULL);
	to.x = strtod(argv[4], NULL);
	to.y = strtod(argv[5], NULL);

	print_start();

	print_move_to(&from);

	print_line(&from, &to);

	print_end();

	return 0;
}

float extrusionFormula(position_t* from, const position_t* to)
{
	float result = 0.0;

	result = sqrt(pow((to->x - from->x), 2) + pow((to->y - from->y), 2) + pow((to->z - from->z), 2));
	result *= EXTRUSION_FACTOR;

	return result;	
}

void print_line(position_t* from, const position_t* to)
{
	// You will need to print G1 here.

	// You may assume that the nozzle is already at the from position given.
	// The important thing to consider is how much filament to extrude.

	// Do some experiments here with different extrusion settings.
	// We recommend extruding about one tenth the distance moved.

	printf("G1 X%lf Y%lf Z%lf E%lf, ; print_line called but not implemented\n", to->x, to->y, to->z, extrusionFormula(from, to));

	// Update the current location of the nozzle.
	*from = *to;
}

