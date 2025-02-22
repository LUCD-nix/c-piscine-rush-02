#ifndef NUM2WORDS_H
# define NUM2WORDS_H

# define DEFAULT_DICT_PATH "../numbers.dict"

# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_dictionary
{
	char	**nums;
	char	**words;
}	t_dictionary;

int				ft_atoi(char *str);
void			ft_putstr(char *str);
t_dictionary	*get_dictionary(char *dict_path);

# define PRINT_GOT_ERROR -1;
# define PRINT_HORIZONTAL_LINE -2;
# define PRINT_COMMA -3;
# define PRINT_AND -4;

#endif
