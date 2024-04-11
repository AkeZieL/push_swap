/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:05:33 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/13 10:52:55 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

int	check_input(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][0] == '-')
			j++;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_doublon(char **str)
{
	int	nb_i;
	int	nb_j;
	int	i;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{
		nb_i = ft_atoi(str[i]);
		j = i + 1;
		while (str[j] != NULL)
		{
			nb_j = ft_atoi(str[j]);
			if (nb_i == nb_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(char **str)
{
	if (check_input(str) == 1 && check_doublon(str) == 0)
		return (0);
	return (1);
}
