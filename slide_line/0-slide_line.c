#include "slide_line.h"

/**
 * compact_left - move all non-zero elements to the left
 * @line: array of integers
 * @size: number of elements
 */
static void compact_left(int *line, size_t size)
{
	size_t w = 0;
	size_t r;

	for (r = 0; r < size; r++)
		if (line[r] != 0)
			line[w++] = line[r];
	for (; w < size; w++)
		line[w] = 0;
}

/**
 * compact_right - move all non-zero elements to the right
 * @line: array of integers
 * @size: number of elements
 */
static void compact_right(int *line, size_t size)
{
	size_t wr = size - 1;
	size_t r;
	size_t zero_end;
	size_t i;

	r = size;
	while (r > 0)
	{
		r--;
		if (line[r] != 0)
			line[wr--] = line[r];
	}
	zero_end = (wr >= size) ? size - 1 : wr;
	for (i = 0; i <= zero_end && i < size; i++)
		line[i] = 0;
}

/**
 * merge_left - merge adjacent equal values left-to-right (each pair once)
 * @line: array of integers
 * @size: number of elements
 */
static void merge_left(int *line, size_t size)
{
	size_t i;

	for (i = 0; i + 1 < size; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
			i++; /* skip next so we don't merge it again */
		}
	}
}

/**
 * merge_right - merge adjacent equal values right-to-left (each pair once)
 * @line: array of integers
 * @size: number of elements
 */
static void merge_right(int *line, size_t size)
{
	size_t i;

	i = size;
	while (i >= 1)
	{
		i--;
		if (i >= 1 && line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
			if (i >= 2)
				i--; /* skip so we don't merge again */
		}
	}
}

/**
 * slide_line - slide and merge a line of integers (2048-style)
 * @line: array of integers
 * @size: number of elements
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure (invalid direction)
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
		return (0);
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		compact_left(line, size);
		merge_left(line, size);
		compact_left(line, size);
	}
	else
	{
		compact_right(line, size);
		merge_right(line, size);
		compact_right(line, size);
	}
	return (1);
}
