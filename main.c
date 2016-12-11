#include "line.h"
#include "square.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		const char* const name = argv[1];

		// You will need to add any additional main functions here.
		// You can call your new function using "gcode-gen <name> <args...>".

		// For example the line main function takes 4 parameters the x, y coordinates
		// where the line starts and the x, y coordinates where the line ends.
		// You could call it like so to draw a line from (10, 20) to (30, 40):
		//		"gcode-gen line 10 20 30 40"

		if (strcmp(name, "line") == 0)
		{
			return line_main(argc, argv);
		}
		else if (strcmp(name, "square") == 0)
		{
			return square_main(argc, argv);
		}
		else if (strcmp(name, "filled-square") == 0)
		{
			return filled_square_main(argc, argv);
		}
		else if (strcmp(name, "cube") == 0)
		{
			return cube_main(argc, argv);
		}
		else if(strcmp(name, "circle") == 0)
		{
			return circle_main(argc, argv);
		}
		else if(strcmp(name, "filled-circle") == 0)
		{
			return filled_circle_main(argc, argv);
		}
		else if(strcmp(name, "cylinder") == 0)
		{
			return cylinder_main(argc, argv);
		}
		else if(strcmp(name, "shot") == 0)
		{
			return shot_main(argc, argv);
		}
		else
		{
			fprintf(stderr, "Unknown shape '%s'\n", name);
		}
	}
	else
	{
		fprintf(stderr, "Incorrect number of parameters provided.\n");
	}

	return 0;
}
