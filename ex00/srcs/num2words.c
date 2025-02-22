/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num2words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:04:14 by arcornil          #+#    #+#             */
/*   Updated: 2025/02/22 11:22:57 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/num2words.h"

int main(int argc, char **argv)
{
	t_dictionary	*dict;
	char			*num_str;
	bool			custom_dict;
	int				num;

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
	//TODO: Check if number is valid
	num = ft_atoi(num_str);
	if (custom_dict)
		dict = get_dictionary(argv[1]);
	else
		dict = get_dictionary(DEFAULT_DICT_PATH);
	if (!dict)
	{
		ft_putstr("Dict Error \n");
		return (1);
	}
	return(0);
}
