/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:49:39 by arcornil          #+#    #+#             */
/*   Updated: 2025/02/22 14:09:04 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/num2words.h"
#include <stddef.h>
#define BUFFER_SIZE 4096

size_t	get_file_size(char *file_path)
{
	char 	buffer[BUFFER_SIZE];
	size_t	size;
	int		fd;

	fd = open(file_path, O_RDONLY);
	size = read(fd, buffer, BUFFER_SIZE);
	close(fd);
	return (size);
}

char *get_file_content(char *file_path)
{
	int		fd;
	size_t	size;
	char	*buffer;

	size = get_file_size(file_path);
	if (!size)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * size);
	if (!buffer)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	read(fd, buffer, size);
	close(fd);
	return (buffer);
}

int	get_nbr_lines(char *str)
{
	int	nbr_line;

	nbr_line = 1;
	while (*str)
	{
		if (*str == '\n')
			nbr_line ++;
		str ++;
	}
	return (nbr_line);
}

t_dictionary *get_dictionary(char *dict_path)
{
	char 			*raw_dict;
	t_dictionary	*dict;
	int				curr_line;
	int				nbr_lines;
	int				i;
	int				j;

	raw_dict = get_file_content(dict_path);
	if (!raw_dict)
		return (NULL);
	dict = (t_dictionary *)malloc(sizeof(t_dictionary));
	if (!dict)
		return (NULL);
	nbr_lines = get_nbr_lines(raw_dict);
	curr_line = 0;
	i = 0;
	while (curr_line < nbr_lines)
	{
		j = 0;
		while ((raw_dict + i)[j] != '\t' )
		{
			
		}
		curr_line ++;
	}
}

int main()
{
	get_dictionary(DEFAULT_DICT_PATH);
}
