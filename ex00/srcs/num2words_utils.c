/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num2words_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:04:45 by arcornil          #+#    #+#             */
/*   Updated: 2025/02/22 20:00:36 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/num2words.h"

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i ++;
	write(1, str, i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

bool	is_zero_padded(char *num_str)
{
	while(++num_str)
	{
		if (*num_str != '0')
			return (false);
	}
	return (true);
}

bool	is_magnitude(char *num_str)
{
	bool	is_thousand;
	
	is_thousand = (ft_strlen(num_str) % 3 == 1);
	return (is_thousand \
		&&  *num_str == '1' \
	       	&& is_zero_padded(num_str));
}

bool	ft_strnequals(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 1;
	if (n == 0)
		return (0);
	while (*s1 && *s2 && (*s1 == *s2) && i < n)
	{
		i++;
		s1++;
		s2++;
	}
	return ((*s1 - *s2) != 0);
}
