#include "common.h"

#include <stdio.h>

void init_position(position_t* pos)
{
	pos->x = pos->y = pos->z = 0;
}

void print_start(void)
{
	printf(" ; Parameters:\n");
	// TODO: Include the parameters you define here.

	printf("G21 ; Millimetre units\n");

	printf("M104 S230 ; Set extruder temperature to 200 degrees\n");

	printf("G90 ; Absolute coordinates\n");
	printf("M83 ; Relative extruder coordinates\n");

	printf("G92 E0 ; Reset extruder coordinate to 0\n");
	
	printf("G28 X Y Z ; Home all axis\n");
	printf("G29 ; Detailed Z-probe\n");

	printf("M109 S230 ; Wait for extruder to reach temperature\n");

	printf("M106 ; Turn fan on\n");

	printf("G1 F1260 ; Set feed rate\n");

	printf("G92 E0 ; Reset extruder coordinate to 0\n");
}

void print_end(void)
{
	printf("M107 ; Turn fan off\n");

	printf("G1 Z30 ; Move nozzle up and out of the way\n");
}

void print_move_to(const position_t* pos)
{
	printf("G1 X%f Y%f Z%f\n", pos->x, pos->y, pos->z);
}
