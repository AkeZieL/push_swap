/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:57:02 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/13 10:48:06 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

t_stack	*ft_avant_derniere_stack(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

void	reverse(t_stack **stack)
{
	t_stack	*res;
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	res = ft_stacklast(*stack);
	tmp = ft_avant_derniere_stack(*stack);
	res->next = *stack;
	tmp->next = NULL;
	*stack = res;
}

void	reverse_a(t_stack **stack)
{
	reverse(stack);
	ft_putstr("rra\n");
}

void	reverse_b(t_stack **stack)
{
	reverse(stack);
	ft_putstr("rrb\n");
}

void	reverse_rr(t_stack **stack_a, t_stack **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_putstr("rrr\n");
}
