/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num2words_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:04:45 by arcornil          #+#    #+#             */
/*   Updated: 2025/02/22 09:44:16 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/num2words.h"

int	ft_atoi(char *str)
{
	int		num;
	bool	is_negative;

	while (*str == '\t' || *str == '\v' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == ' ')
		str ++;
	is_negative = false;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = !is_negative;
		str ++;
	}
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		if (is_negative)
			num -= *str - '0';
		else
			num += *str - '0';
		str ++;
	}
	return (num);
}
