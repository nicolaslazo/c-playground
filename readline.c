#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

/* REMINDER:
 * 	Remember to compile this file with the -lreadline flag
 * 	To use readline, you need the libreadline6 and libreadline6-dev packages installed
 */

int main() {
	char* input;

	while ( 1 ) {
		input = readline(">>> ");

		if (input) add_history(input);
		if (!strncmp(input, "exit", 4)) {
			free(input);
			break;
		}

		printf("%s", input);
		printf("\n");
	}

	return 0;
}


