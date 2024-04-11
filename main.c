/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:49:23 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/13 10:48:32 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && est_valide(*stack_a) == 0)
		swap_a(stack_a);
	if (stack_size == 3 && est_valide(*stack_a) == 0)
		trieur_3_val(stack_a);
	else if (stack_size == 4 && est_valide(*stack_a) == 0)
		trieur_4_val(stack_a, stack_b);
	else if (stack_size == 5 && est_valide(*stack_a) == 0)
		trieur_5_val(stack_a, stack_b);
	if (stack_size > 5 && est_valide(*stack_a) == 0)
		trieur(stack_a, stack_b, stack_size);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tmp;
	int		st_size;

	if (argc > 1)
	{
		tmp = &argv[1];
		if (argc == 2)
			tmp = ft_split(argv[1], ' ');
		if (check_error(tmp) == 1)
			exit_error2();
		stack_b = NULL;
		stack_a = init_stack(tmp);
		st_size = stack_size(stack_a);
		push_swap(&stack_a, &stack_b, st_size);
		if (argc == 2)
			free_split(tmp);
		free_all(&stack_a);
		free_all(&stack_b);
	}
	return (0);
}
