#ifndef NUM2WORDS_H
# define NUM2WORDS_H

# include <stdbool.h>
# include <unistd.h>

typedef struct s_dictionary
{
	int	*nums;
	char **words;
}	t_dictionary;

int	ft_atoi(char *str);

#endif
