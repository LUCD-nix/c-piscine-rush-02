#include "./includes/num2words.h"
#include <stdio.h>

bool	write_hundreds();

void print_printer(int *printer)
{
	printf("{ ");
	while (*printer != -1)
		printf("%d, ", *printer++);
	printf("}\n");
}

int main()
{
	t_dictionary	dict;

	char *words[] = { "hundred", "yoyoyo", "fourty", "two", "one", 0};
	char *nums[] =  { "100", "343", "40", "2", "1", 0};
	int sizes[] = { 3, 3, 2, 1 , 1};
	int printer[256] = { 0 };

	dict.sizes = sizes;
	dict.words = words;
	dict.nums = nums;

	printer[10] = -1;

	write_hundreds(dict, "343", printer);

	print_printer(printer);
	return (0);
}
