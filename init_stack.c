/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:11:19 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/13 10:49:59 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"
#include <stdio.h>

t_stack	*new_stack(int value)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->index = 0;
	tmp->nb_bit = 0;
	tmp->next = NULL;
	return (tmp);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*res;

	res = stack;
	while (res)
	{
		if (res->next == NULL)
			return (res);
		res = res->next;
	}
	return (res);
}

void	stack_addback(t_stack **stack, int value)
{
	t_stack	*res;

	if (!stack)
		return ;
	res = NULL;
	if (*stack)
	{
		res = ft_stacklast(*stack);
		res->next = new_stack(value);
	}
	else
		*stack = res;
}

int	stack_size(t_stack *stack)
{
	int	res;

	res = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		res++;
	}
	return (res);
}

t_stack	*init_stack(char **av)
{
	long long int	nb;
	t_stack			*stack;
	int				i;

	stack = NULL;
	nb = 0;
	i = 0;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		if (nb > 2147483647 || nb < -2147483648)
			exit_error(&stack, NULL);
		if (stack == NULL)
			stack = new_stack((int)nb);
		else
			stack_addback(&stack, (int)nb);
		i++;
	}
	return (stack);
}
/*
int	main(int argc, char **argv)
{
	t_stack *test;
	int	i;
	char	**tmp;

	(void)argc;
	i = 1;
	while (argv[i])
		tmp = ft_split(argv[i++], ' ');
	test = init_stack(tmp);
	while (test)
	{
		printf("%d", test->value);
		test = test->next;
	}
}*/
