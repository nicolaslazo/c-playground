%{ 
	#include <stdio.h>
	int charCount = 0;
%}

number	[0-9]+
letter	[a-zA-Z]

%%

{number}	{ printf("Number found: %s\n", yytext); }
{letter}	{ charCount++; }

%%

int main() {
	yylex();
	printf("%d\n", charCount);

	return 0;
}
