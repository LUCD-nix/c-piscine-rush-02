/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_logic_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:33:22 by lucorrei          #+#    #+#             */
/*   Updated: 2025/02/22 18:56:54 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/num2words.h"

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
