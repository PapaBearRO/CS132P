#include "circle.h"

#include "common.h"
#include "line.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef void (*printfn_t)(position_t*, double);
float extrusionFormulaCircumference(double radius);

static int circle_main_common(int argc, char** argv, printfn_t print_function)
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

	const double radius = strtod(argv[4], NULL);

	print_start();

	print_move_to(&pos);

	print_function(&pos, radius);
	//print_circle(&pos, radius);
	print_end();

	return 0;
} 

int circle_main(int argc, char** argv)
{
	printf(" ; Generating a square\n");

	return circle_main_common(argc, argv, &print_circle);
}

int filled_circle_main(int argc, char** argv)
{
	printf(" ; Generating a filled square\n");

	return circle_main_common(argc, argv, &print_filled_circle);
}

int cylinder_main(int argc, char** argv)
{
	printf(" ; Generating a cube\n");

	return circle_main_common(argc, argv, &print_cylinder);
}

int shot_main(int argc, char** argv)
{
	return circle_main_common(argc, argv, &print_shot);
}

float extrusionFormulaCircumference(double radius)
{
	float result = 0.0;

	result = M_PI * radius;
	result *= EXTRUSION_FACTOR;
	result *= 2;

	return result;	
}


void print_circle(position_t* pos, double radius)
{
	printf("G2 X%lf Y%lf I%lf J%lf E%lf\n", pos->x, pos->y, radius, radius, extrusionFormulaCircumference(radius));
	//printf("G3 X%lf Y%lf I%lf J%lf E%lf\n", pos->x, pos->y, pos->x - radius, pos->y, extrusionFormulaCircumference(radius));
}

void print_filled_circle(position_t* pos, double radius)
{
	double aux1 = pos->x;
	double aux2 = pos->y;
	double aux3 = radius;

	while(radius > 0)
	{
		print_circle(pos, radius);
		pos->x += 0.2;
		pos->y += 0.2;
		radius -= 0.2;
	}

	pos->x = aux1;
	pos->y = aux2;
	radius = aux3;
}

void print_cylinder(position_t* pos, double radius)
{
	
	pos->z = 0;
	while(pos->z < 5)
	{
		printf("G4 P2000\n");
		print_filled_circle(pos, radius);
		pos->z += 0.5;
		printf("G1 X%lf, Y%lf, Z%lf\n", pos->x, pos->y, pos->z);
		
	}
}	

void print_shot(position_t pos, double radius)
{

}
