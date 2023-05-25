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
	unsigned int count = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	buf.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(contents, sizeof(contents), file) != NULL)
	{
		contents[strcspn(contents, "\n")] = '\0';

		buf.contents = contents;
		execute_func(contents, &stack, count, file);
		count++;
	}

	stack_free(stack);
	fclose(file);

return (0);
}
