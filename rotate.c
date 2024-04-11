/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:26:11 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/13 10:47:46 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*res;

	if (stack == NULL || *stack == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	res = ft_stacklast(*stack);
	tmp->next = NULL;
	res->next = tmp;
}

void	rotate_a(t_stack **stack)
{
	rotate(stack);
	ft_putstr("ra\n");
}

void	rotate_b(t_stack **stack)
{
	rotate(stack);
	ft_putstr("rb\n");
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
