/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_order_of_magnitude.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:14:28 by lucorrei          #+#    #+#             */
/*   Updated: 2025/02/22 12:41:53 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/num2words.h"

bool	write_tens(const t_dictionary dict, char *to_write, int *printer)
{
	int	i;

	i = -1;
	while (dict.nums[++i])
	{
		if (ft_strlen(dict.nums[i]) == 2)
		{
			if (dict.nums[i][0] == *to_write)
			{
				if (*to_write >= '2')
				{
					ft_putstr(dict.words[i]);
					write(1, "-", 1);
					return (write_units(to_write + 1));
				}
				else if (dict.nums[i][1] == *(to_write + 1))
				{
					ft_putstr(dict.words[i]);
					return (true);
				}
			}
		}
	}
	return (false);
}

bool	write_hundreds(t_dictionary dict, char *to_write, int *printer)
{	
	int	i;
	bool	success;

	i = -1;
	while (dict_nums[++i])
	{
		if (ft_strlen(dict.nums[i] == 3))
		{
			if (is_magnitude(dict.nums[i]))
			{
				if (!write_units(to_write, printer))
					return (false);
				++printer = i;
			}
		}
	}
	if (!write_tens(dict, to_write + 1, printer + 1))
		return (false);
}
