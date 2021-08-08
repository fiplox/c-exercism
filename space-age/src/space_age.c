#include "space_age.h"

const double earth_year_in_seconds = 31557600.0;
const double mercury_year_in_earth_years = 0.2408467;
const double venus_year_in_earth_years = 0.61519726;
const double mars_year_in_earth_years = 1.8808158;
const double jupiter_year_in_earth_years = 11.862615;
const double saturn_year_in_earth_years = 29.447498;
const double uranus_year_in_earth_years = 84.016846;
const double neptune_year_in_earth_years = 164.79132;

float age(planet_t planet, int64_t seconds)
{
	switch(planet) {
		case MERCURY:
			return seconds / earth_year_in_seconds / mercury_year_in_earth_years;
		case VENUS:
			return seconds / earth_year_in_seconds / venus_year_in_earth_years;
		case EARTH:
			return seconds / earth_year_in_seconds;
		case MARS:
			return seconds / earth_year_in_seconds / mars_year_in_earth_years;
		case JUPITER:
			return seconds / earth_year_in_seconds / jupiter_year_in_earth_years;
		case SATURN:
			return seconds / earth_year_in_seconds / saturn_year_in_earth_years;
		case URANUS:
			return seconds / earth_year_in_seconds / uranus_year_in_earth_years;
		case NEPTUNE:
			return seconds / earth_year_in_seconds / neptune_year_in_earth_years;
	}
	return 0.0; // should not reach here.
}
