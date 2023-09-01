#include "../includes/string.h"

#define LINES	25										// Lines of the screen
#define COLUMNS	80										// Columns of the screen

void		kmain(void) {
	const char *str = "my first kernel in school 42 ";
	char *vidptr = (char*)0xb8000;						// Video memory begins here.
	unsigned int i = 0;
	unsigned int j = 0;

	// Clear screen
	// Each element takes 2 bytes. First for value, second for flags
	while(j < COLUMNS * LINES * 2) {
		vidptr[j] = ' ';
		vidptr[j+1] = 0x07; 		// Attribute-byte - light grey on black screen
		j += 2;
	}

	j = 0;

	// Writes the string to video memory
	while(str[j] != '\0') {
		/* the character's ascii */
		vidptr[i] = str[j];
		vidptr[i+1] = 0x07; 		// Attribute-byte - light grey on black screen
		j++;
		i += 2;
	}

	int length = ft_strlen(str);

	return ;
}