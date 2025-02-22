/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_order_of_magnitude.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:14:28 by lucorrei          #+#    #+#             */
/*   Updated: 2025/02/22 22:49:47 by lucorrei         ###   ########.fr       */
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
		// ceci est une fonction qui va voir si elle peut 
		// écrire le nombre meme sans avoir des trucs comme
		// "100" = "hundred"
		// c'est un peu moche et je l'ai pas encore assez
		// testé mais je crois que ca marche
		if ((dict.sizes[i]) == len && dict.nums[i][0] == *trying)
		{
			// ici elle voit si un nombre n'a que des
			// zéros à droite,  donc si il pourrait
			// servir à en construire d'autres
			if (is_zero_padded(dict.nums[i]))
			{
				*printer++ = i;
				if (try_full_nums(dict, trying + 1, printer, len - 1))
					return (true);
			}
			// ici elle voit le cas de base, c à dire si
			// un des nums de notre dico correspond entierement
			// à la string que l'on cherche
			else if (ft_strnequals(trying, dict.nums[i], len) == true)
			{
				*printer = i;
				return (true);
			}
		}
	}
	// en théorie cela nous permettrait de construire 
	// "42 042 = forty-two thousand and fort-two" qu'avec 
	// "42 000" et "42" dans le dictionnaire mais je suis
	// un poil trop fatigué pour tester tout ca ajd
	// bonne soirée tout le monde
	return (false);
}

bool	write_units(const t_dictionary dict, char *to_write, int *printer, bool h)
{
	int	i;

	i = -1;
	// si le nombre  est du genre "106" "one hundred and six"
	// il faut pas écrire le tiret entre les dix et les unités
	// c'es pas propre et ca pose meme des problemes de memoire
	// quand c'est invoqué au tt début de la string d'input
	// à colmater demain 
	if (!h && !(*(to_write - 1) == '0'))
		*printer++ = PRINT_HORIZONTAL_LINE;
	while (dict.nums[++i])
	{
		// le meme check qu'avant cette fois avec size = 1
		if ((dict.sizes[i]) == 1 && dict.nums[i][0] == *to_write)
		{
			// "two" !
			*printer = i;

			if (!h)
				// self explanatory
				*(printer + 1) = PRINT_START_STOP;
			return (true);
		}
	}
	return (false);
}

bool	write_tens(t_dictionary dict, char *to_write, int *printer)
{
	int		i;
	bool	success;

	i = -1;
	success = false;
	while (*to_write != '0' && dict.nums[++i])
	{
		// ici la même
		// 1. cette fois on cherche des nums de taille 2
		if (dict.sizes[i] == 2 && dict.nums[i][0] == *to_write)
		{
			// sauf que cette fois il faut considérer que les
			// numéros de 10 à 20 s'écrivent bizarrement
			// si c'est au dessus de 20 ont passe aux
			// unités
			if (*to_write >= '2')
			{
				// "forty"
				*printer = i;
				success = true;
				break ;
			}
			// si c'est entre 10 et 20 il faut que les
			// 2 digits matchent donc nums[i][0 et 1]
			// et *to_write et *(to_write + 1) c'est ce 
			// qu'on vérifie dans ce 2eme if
			else if (dict.nums[i][1] == *(to_write + 1))
			{
				*printer = i;
				return (true);
			}
		}
	}
	// à nouveau, qui serait assez bête pour oublier le cas essentiel
	// n = 0
	// (moi, moi je suis assez bête, tres bête meme)
	if (success || *to_write == '0')
		return (write_units(dict, to_write + 1, printer + success, false));
	return (try_full_nums(dict, to_write, printer, 2));
}

bool	write_hundreds(t_dictionary dict, char *to_write, int *printer)
{
	int		i;
	bool	success;

	// assumons qu'on traite le nombre "142"
	// en tres gros : 
	// pour digit on parcoure tout notre dictionnaire
	i = -1;
	success = false;
	while (*to_write != '0' && dict.nums[++i])
	{
		// à la recherche de
		//  1. des chiffres qui sont de la bonne taille
		//  (donc pour les centaines len = 3
		//  2. qui nous donnent le mot "hundred"
		//  donc num[i] == "100"
		if (dict.sizes[i] == 3 && ft_strnequals(dict.nums[i], "100", 3) == true)
		{
			// et puis on écrit ce qui vient avant le "hundred"
			// c'est à dire le "one" 
			if (!write_units(dict, to_write, printer, true))
				break ;
			// on écrit le "hundred"
			*(++printer) = i;
			success = true;
			// après les centaines en anglais il y tjrs un "and"
			*++printer = PRINT_AND;
			break ;
		}
	}
	// si la case des 100 est nulle ont passe au suivant
	// sinon on fallback sur "try_full_nums" qui brute force la chose
	if (success || *to_write == '0')
		return (write_tens(dict, to_write + 1, printer + success));
	return (try_full_nums(dict, to_write, printer, 3));
}
