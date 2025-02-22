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

#endif
