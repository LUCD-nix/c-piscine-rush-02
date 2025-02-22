/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:49:39 by arcornil          #+#    #+#             */
/*   Updated: 2025/02/22 14:51:28 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/num2words.h"

#define BUFFER_SIZE 2048

size_t	get_file_size(char *file_path)
{
	char 	buffer[BUFFER_SIZE];
	size_t	size;
	size_t	total_size;
	int		fd;

	fd = open(file_path, O_RDONLY);
	total_size = 0;
	while((size = read(fd, buffer, BUFFER_SIZE)))
		total_size += size;
	close(fd);
	return (total_size);
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

	nbr_line = 0;
	while (*str)
	{
		if (*str == '\n')
			nbr_line ++;
		str ++;
	}
	return (nbr_line);
}

char	*num_dup(char *ptr)
{
	int		i;
	char	*num_str;

	i = 0;
	while (ptr[i] && ptr[i] != ':' && ptr[i] != ' ')
		i ++;
	if (!ptr[i])
		return (NULL);
	num_str = (char *)malloc(sizeof(char) * i + 1);
	if (!num_str)
		return (NULL);
	i = 0;
	while (ptr[i] && ptr[i] != ':' && ptr[i] != ' ')
	{
		num_str[i] = ptr[i];
		i ++;
	}
	num_str[i] = 0;
	return (num_str);
}

char	*word_dup(char *ptr)
{
	int		i;
	char	*word_str;

	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		i ++;
	if (!ptr[i])
		return (NULL);
	word_str = (char *)malloc(sizeof(char) * i + 1);
	if (!word_str)
		return (NULL);
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
	{
		word_str[i] = ptr[i];
		i ++;
	}
	word_str[i] = 0;
	return (word_str);
}

t_dictionary *get_dictionary(char *dict_path)
{
	char 			*raw_dict;
	t_dictionary	*dict;
	int				curr_line;
	int				nbr_lines;
	int				i;
	int				j;
	char			*curr_num;
	char			*curr_word;
	int				curr_num_size;

	raw_dict = get_file_content(dict_path);
	if (!raw_dict)
		return (NULL);
	dict = (t_dictionary *)malloc(sizeof(t_dictionary));
	if (!dict)
		return (NULL);
	nbr_lines = get_nbr_lines(raw_dict);
	if (!nbr_lines)
		return (NULL);
	dict->nums = (char **)malloc(sizeof(char *) * nbr_lines + 1);
	if (!dict->nums)
		return (NULL);
	dict->words = (char **)malloc(sizeof(char *) * nbr_lines + 1);
	if (!dict->words)
		return (NULL);
	dict->sizes = (int *)malloc(sizeof(int) * nbr_lines + 1);
	curr_line = 0;
	i = 0;
	while (curr_line < nbr_lines)
	{
		j = 0;
		while ((raw_dict + i)[j] == ' ')
			j ++;
		if ((raw_dict + i)[j] == '+')
			j ++;
		else if ((raw_dict + i)[j] == '-')
			return (NULL);
		curr_num = num_dup(&(raw_dict + i)[j]);
		if (!curr_num)
			return (NULL);
		dict->sizes[curr_line] = ft_strlen(curr_num);
		while((raw_dict + i)[j] != ':')
			j ++;
		j ++;
		while ((raw_dict + i)[j] == ' ')
			j ++;
		curr_word = word_dup(&(raw_dict + i)[j]);
		while((raw_dict + i)[j] >= 32 && (raw_dict + i)[j] <= 126)
			j ++;
		if ((raw_dict + i)[j] != '\n')
			return (NULL);
		j ++;
		dict->nums[curr_line] = curr_num;
		dict->words[curr_line] = curr_word;
		i += j;
		curr_line ++;
	}
	dict->nums[curr_line] = 0;
	dict->words[curr_line] = 0;
	return (dict);
}
