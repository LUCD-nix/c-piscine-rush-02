/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num2words_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:04:45 by arcornil          #+#    #+#             */
/*   Updated: 2025/02/22 17:38:34 by arcornil         ###   ########.fr       */
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
