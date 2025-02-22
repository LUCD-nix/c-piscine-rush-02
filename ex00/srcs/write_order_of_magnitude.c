/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_order_of_magnitude.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:14:28 by lucorrei          #+#    #+#             */
/*   Updated: 2025/02/22 15:33:43 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/num2words.h"

bool	try_full_nums(const t_dictionary dict, char *trying, int *printer, int len)
{	
	int	i;

	i = -1;
	if (len == 0)
		return (true);
	if (*trying == 0)
		return (false);
	while (dict.nums[++i])
	{
		if (ft_strlen(dict.nums[i] == len && dict.nums[i][0] == *trying))
		{
			if (is_zero_padded(dict.nums[i]))
			{
				*printer++ = i;
				if (!try_full_nums(dict, trying + 1, printer, len - 1))
					break ;
			}
		}
	}
}
bool	write_units(const t_dictionary dict, char *to_write, int *printer)
{
	int	i;
	while (dict.nums[++i])
	{
		if ft_strlen(dict.nums[i] == 1 && dict.nums[i][0] == *to_write)
		{
			*printer = i;
			return (true);
		}
	}
	return (false);
}

bool	write_tens(const t_dictionary dict, char *to_write, int *printer)
{
	int	i;

	i = -1;
	while (dict.nums[++i])
	{
		if (ft_strlen(dict.nums[i]) == 2 && dict.nums[i][0] == *to_write)
		{
			if (*to_write >= '2')
			{
				*printer++ = i;
				*printer++ = PRINT_HORIZONTAL_LINE;
				return (write_units(dict, to_write + 1, printer));
			}
			else if (dict.nums[i][1] == *(to_write + 1))
			{
				printer = i;
				return (true);
			}
		}
	}
	return (try_full_nums(dict, to_write, printer, 2));
}

bool	write_hundreds(t_dictionary dict, char *to_write, int *printer)
{	
	int	i;
	bool	success;

	i = -1;
	if (*to_write = '0')
	{
		*printer = PRINT_AND;
		return write_tens(dict, to_write + 1, printer + 1);
	}
	while (dict_nums[++i])
	{
		if (ft_strlen(dict.nums[i] == 3))
		{
			if (is_magnitude(dict.nums[i]))
			{
				if (!write_units(dict, to_write, printer))
					return (false);
				*(++printer) = i;
				return (write_tens(dict, to_write + 1, printer + 1));
			}
		}
	}
	return (try_full_nums(dict, to_write, printer, 3));
}
