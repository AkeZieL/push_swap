/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trieur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:51:39 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/13 10:47:16 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static void	assign_index(t_stack **stack, int stack_size)
{
	t_stack	*tmp;
	int		i;
	int		max;

	i = 0;
	while (i++ < stack_size)
	{
		tmp = *stack;
		max = 2147483647;
		while (tmp != NULL)
		{
			if (tmp->value < max && tmp->index == 0)
				max = tmp->value;
			tmp = tmp->next;
		}
		tmp = *stack;
		while (tmp->value != max)
			tmp = tmp->next;
		tmp->index = i;
	}
}

void	trieur_3_val(t_stack **stack_a)
{
	while (est_valide(*stack_a) == 0)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a(stack_a);
		if ((*stack_a)->next->value > (*stack_a)->next->next->value)
			reverse_a(stack_a);
	}
}

void	trieur_4_val(t_stack **stack_a, t_stack **stack_b)
{
	assign_index(stack_a, 4);
	while ((*stack_a)->index != 1)
		rotate_a(stack_a);
	push_b(stack_a, stack_b);
	trieur_3_val(stack_a);
	push_a(stack_a, stack_b);
}

void	trieur_5_val(t_stack **stack_a, t_stack **stack_b)
{
	int	moved;

	assign_index(stack_a, 5);
	moved = 0;
	while (moved < 2)
	{
		if ((*stack_a)->index == 1)
		{
			moved++;
			push_b(stack_a, stack_b);
		}
		else if ((*stack_a)->index == 2)
		{
			moved++;
			push_b(stack_a, stack_b);
		}
		else
			rotate_a(stack_a);
	}
	trieur_3_val(stack_a);
	if ((*stack_b)->value < (*stack_b)->next->value)
		swap_b(stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	trieur(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	int	i;
	int	j;

	assign_index(stack_a, stack_size);
	i = 0;
	while (est_valide(*stack_a) == 0)
	{
		j = 0;
		while (j++ < stack_size && est_valide(*stack_a) == 0)
		{
			if (((*stack_a)->index >> i & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
		}
		while (*stack_b)
			push_a(stack_a, stack_b);
		i++;
	}
}
