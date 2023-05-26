#include "monty.h"
buf_t buf = {NULL, NULL, NULL, 0};
/**
 * main - to interprate monty code
 * @argv: the monty file
 * @argc: the arguments number
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	char contents[1024];
	FILE *file;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	buf.file = file;


	while (fgets(contents, sizeof(contents), file))
	{
		line_number++;
		buf.contents = contents;
		execute(&stack, line_number, contents, file);
	}

	fclose(file);
	stack_free(stack);

	return (EXIT_SUCCESS);
}
