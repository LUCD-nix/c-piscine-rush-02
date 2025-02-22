/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:49:39 by arcornil          #+#    #+#             */
/*   Updated: 2025/02/22 10:05:14 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/num2words.h"

t_dictionary *get_dictionary(char *dict_path)
{
	int	fd;
	
	fd = open(dict_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
}
