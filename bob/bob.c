#include "bob.h"

#include <ctype.h>
#include <string.h>
#include <stdbool.h>

static bool has_letter(char *s, int len)
{
	for (int i = 0; i < len; ++i) {
		if ((s[i] > 'a' && s[i] < 'z') || (s[i] > 'A' && s[i] < 'Z'))
			return true;
	}
	return false;
}

static char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

static char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

static char *trim(char *s)
{
    return rtrim(ltrim(s)); 
}

char *hey_bob(char *greeting)
{
	char trimmed[strlen(greeting) + 1];
	strcpy(trimmed, greeting);
	trim(trimmed);
	int len = strlen(trimmed);

	if (len == 0)
		return "Fine. Be that way!";

	char scream[len + 1];

	for (int i = 0; trimmed[i]; ++i) {
		scream[i] = toupper(trimmed[i]);
	}
	scream[len] = '\0';

	if (trimmed[len - 1] == '?') {

		if (strcmp(trimmed, scream) == 0) {
			if (!has_letter(trimmed, len))
				return "Sure.";
			return "Calm down, I know what I'm doing!";
		}
		return "Sure.";
	}

	if (strcmp(trimmed, scream) == 0) {
		if (!has_letter(trimmed, len))
			return "Whatever.";
		return "Whoa, chill out!";
	}

	return "Whatever.";
}
