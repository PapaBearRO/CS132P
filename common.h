#pragma once

// These constants in mm are values that we
// have found to be okay. It is very likely you
// will need to adjust them.
#define EXTRUSION_FACTOR (0.075)
#define FILAMENT_WIDTH (0.60)
#define LAYER_HEIGHT (0.30)

#ifndef M_PI
#	define M_PI 3.14159265358979323846264338327
#endif

// A coordinate data structure.
typedef struct position
{
	double x, y, z;
} position_t;

void init_position(position_t* pos);


void print_start(void);
void print_end(void);

void print_move_to(const position_t* pos);
