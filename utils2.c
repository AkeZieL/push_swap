/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:31:26 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/13 10:46:55 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (ft_strlen(s) < start)
	{
		tmp = malloc(1);
		tmp[0] = 0;
		return (tmp);
	}
	if (start + len < ft_strlen(s))
		tmp = (char *)malloc(sizeof (*s) * len +1);
	else
		tmp = (char *)malloc(sizeof(*s) * (ft_strlen(s) - start + 1));
	if (!tmp)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

int	est_valide(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
