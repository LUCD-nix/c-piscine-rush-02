#ifndef NUM2WORDS_H
# define NUM2WORDS_H

# define DEFAULT_DICT_PATH "../numbers.dict"

# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_dictionary
{
	int		*sizes;
	char	**nums;
	char	**words;
}	t_dictionary;

void			ft_putstr(char *str);
t_dictionary	*get_dictionary(char *dict_path);
int				ft_strlen(char *str);

# define PRINT_START_STOP -1;
# define PRINT_HORIZONTAL_LINE -2;
# define PRINT_COMMA -3;
# define PRINT_AND -4;

#endif
