#include "luhn.h"

#include <string.h>
#include <ctype.h>

bool luhn(const char *num)
{
	size_t i, j;
	size_t len = strlen(num);
	int sum = 0, digit;
	char num_normalized[64];

	for (i = 0, j = 0; i < len; ++i) {
		if (num[i] == ' ')
			continue;
		if (!isdigit(num[i]))
			return false;

		num_normalized[j++] = num[i];
	}
	num_normalized[j] = '\0';
	len = strlen(num_normalized);
	
	if (len <= 1)
		return false;

	bool doubling = strlen(num_normalized) % 2 == 0;
	
	for (i = 0; i < len; ++i) {
		digit = num_normalized[i] - '0';
		if (digit < 0 || digit > 9)
			return false;
		if (doubling) {
			digit *= 2;
			if (digit > 9)
				sum -= 9;
		}
		sum += digit;
		doubling = !doubling;
	}

	return sum % 10 == 0;
}
