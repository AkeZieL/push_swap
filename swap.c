/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:13:41 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/13 10:47:28 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

void	swap(t_stack *stack_a)
{
	int	tmp;

	if (stack_a == NULL || stack_a->next == NULL)
		return ;
	tmp = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = tmp;
}

void	swap_a(t_stack **stack)
{
	swap(*stack);
	ft_putstr("sa\n");
}

void	swap_b(t_stack **stack)
{
	swap(*stack);
	ft_putstr("sb\n");
}

void	swap_s(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
