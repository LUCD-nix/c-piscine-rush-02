/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_order_of_magnitude.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:14:28 by lucorrei          #+#    #+#             */
/*   Updated: 2025/02/22 18:46:59 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/num2words.h"

bool	try_full_nums(t_dictionary dict, char *trying, int *printer, int len)
{	
	int	i;

	if (len == 0)
		return (true);
	if (*trying == 0)
		return (false);
	i = -1;
	while (dict.nums[++i])
	{
		if ((dict.sizes[i]) == len && dict.nums[i][0] == *trying)
		{
			if (is_zero_padded(dict.nums[i]))
			{
				*printer++ = i;
				if (try_full_nums(dict, trying + 1, printer, len - 1))
					return (true);
			}
			else if (ft_strncmp(trying, dict.nums[i], len) == 0)
			{
				*printer = i;
				return (true);
			}
		}
	}
	return (false);
}

bool	write_units(const t_dictionary dict, char *to_write, int *printer)
{
	int	i;
	while (dict.nums[++i])
	{
		if ((dict.sizes[i]) == 1 && dict.nums[i][0] == *to_write)
		{
			*printer = i;
			return (true);
		}
	}
	return (false);
}

bool	write_tens(t_dictionary dict, char *to_write, int *printer, bool is_final)
{
	int	i;

	i = -1;
	while (dict.nums[++i] && *to_write != '0')
	{
		if (dict.sizes[i] == 2 && dict.nums[i][0] == *to_write)
		{
			if (*to_write >= '2')
			{
				*printer++ = i;
				*printer++ = PRINT_HORIZONTAL_LINE;
				return (write_units(dict, to_write + 1, printer));
			}
			else if (dict.nums[i][1] == *(to_write + 1))
			{
				*printer = i;
				return (true);
			}
		}
	}
	return (try_full_nums(dict, to_write, printer, 2));
}

bool	write_hundreds(t_dictionary dict, char *to_write, int *printer, bool is_final)
{	
	int	i;
	bool	next_is_zero;
	bool	success;

	i = -1;
	success = false;
	next_is_zero = (*(to_write + 1) == '0');
	while (*to_write != 0 && dict_nums[++i])
	{
		if (dict.sizes[i] == 3 && ft_strncmp(dict.nums[i], "100", 3) == 0)
		{
			if (!write_units(dict, to_write, printer))
				return (false);
			*(++printer) = i;
			success = true;
			break ;
		}
	}
	*printer++ = PRINT_AND;
	printer += next_is_zero;
	if (success)
		return (write_tens(dict, printer + 1, to_write + 1));
	return (try_full_nums(dict, to_write, printer, 3));
}
