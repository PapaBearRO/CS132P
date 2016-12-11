#include "square.h"

#include "common.h"
#include "line.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef void (*printfn_t)(position_t*, double);

static int square_main_common(int argc, char** argv, printfn_t print_function)
{
	if (argc != 5)
	{
		fprintf(stderr, "Invalid number of arguments (%d)\n", argc);
		return 1;
	}

	position_t pos;

	init_position(&pos);

	pos.x = strtod(argv[2], NULL);
	pos.y = strtod(argv[3], NULL);
	const double size = strtod(argv[4], NULL);

	print_start();

	print_move_to(&pos);

	print_function(&pos, size);
	print_square(&pos, size);
	print_end();

	return 0;
}

int square_main(int argc, char** argv)
{
	printf(" ; Generating a square\n");

	return square_main_common(argc, argv, &print_square);
}

int filled_square_main(int argc, char** argv)
{
	printf(" ; Generating a filled square\n");

	return square_main_common(argc, argv, &print_filled_square);
}

int cube_main(int argc, char** argv)
{
	printf(" ; Generating a cube\n");

	return square_main_common(argc, argv, &print_cube);
}

void print_square(position_t* pos, double size)
{

	//printf("G2 X%lf Y%lf I%lf J%lf E%lf", 90.6 13.8 5 10 22.4);
	
	//printf("G2 X%lf Y%lf I%lf J%lf E%lf\n", pos->x + size, pos->y, pos->x, pos->y, extrusionFormulaCircumference(size));
	//printf("G2 X%lf Y%lf I%lf J%lf E%lf\n", pos->x - size, pos->y, pos->x, pos->y, extrusionFormulaCircumference(size));
	printf(" ; Printing Square at (%f,%f,%f) of size %f.\n", pos->x, pos->y, pos->z, size);

	float l = sqrt(size);
	float var = l * sqrt(2) / 2;

	position_t origin;
	origin.x = pos->x-var;
	origin.y = pos->y-var;
	origin.z = pos->z;

	position_t aux = origin;

	position_t corner1;
	corner1.x = pos->x-var;
	corner1.y = pos->y+var;
	corner1.z = pos->z;

	position_t corner2;
	corner2.x = pos->x+var;
	corner2.y = pos->y+var;
	corner2.z = pos->z;

	position_t corner3;
	corner3.x = pos->x+var;
	corner3.y = pos->y-var;
	corner3.z = pos->z;

	print_move_to(&origin);
	print_line(&origin, &corner1);
	print_line(&corner1, &corner2);
	print_line(&corner2, &corner3);
	print_line(&corner3, &aux);
	// Use the print_line function to print a square.

	// You can assume that the nozzle is at the position provided.
	// You will want *pos to contain the coordinates the nozzle is located at the end of the function.
	printf(" ; print_square called but not implemented\n");
}

void print_filled_square(position_t* pos, double size)
{
	printf(" ; Printing Filled Square at (%f,%f,%f) of size %f.\n", pos->x, pos->y, pos->z, size);
	float l = sqrt(size);
	float var = l * sqrt(2) / 2;

	while(l > 0)
	{
		print_square(pos, l*l);
		l -= 1;
	}
	// Print a square of the given dimensions that is filled with plastic

	printf(" ; print_filled_square called but not implemented\n");
}

void print_cube(position_t* pos, double size)
{
	printf(" ; Printing Cube at (%f,%f,%f) of size %f.\n", pos->x, pos->y, pos->z, size);
	float l = sqrt(size);

	pos->z = 0;
	while(pos->z < l)
	{
		printf("G4 P5000");
		print_filled_square(pos, size);
		pos->z += 0.5;
	}


	// Now you have the ability to print a filled in square, print upwards and print a cube

	printf(" ; print_cube called but not implemented\n");
}
