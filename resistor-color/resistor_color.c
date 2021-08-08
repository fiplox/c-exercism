#include "resistor_color.h"

int color_code(resistor_band_t color) {
	return color;
}

resistor_band_t* colors(void) {
	resistor_band_t *c;
	int i;
	i = 0;
	c = malloc(sizeof(resistor_band_t) * 10);

	for(i = 0; i < 10; i++)
		*(c+i) = color_code(i);
	
	return c;
}
