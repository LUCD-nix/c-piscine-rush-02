/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num2words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:04:14 by arcornil          #+#    #+#             */
/*   Updated: 2025/02/22 17:44:50 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/num2words.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_dictionary	*dict;
	char			*num_str;
	bool			custom_dict;
	int				i;

	if (!(argc >= 2 && argc <= 3))
	{
		ft_putstr("Usage: ./rush02 [optional: custom dict path] [number]");
		return (1);
	}
	custom_dict = false;
	if (argc == 2)
		num_str = argv[1];
	else if (argc == 3)
	{
		num_str = argv[2];
		custom_dict = true;
	}
	i = 0;
	while(num_str[i])
	{
		if (!(num_str[i] >= '0' && num_str[i] <= '9'))
		{
			ft_putstr("Error\n");
			return (1);
		}
		i ++;
	}
	if (custom_dict)
		dict = get_dictionary(argv[1]);
	else
		dict = get_dictionary(DEFAULT_DICT_PATH);
	if (!dict)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	while (*(dict->nums))
	{
		printf("%s: %s\n", *(dict->nums), *(dict->words));
		dict->nums ++;
		dict->words ++;
	}
	return(0);
}
