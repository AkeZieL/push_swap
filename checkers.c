/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:30:09 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/13 10:51:19 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static void	do_move2(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(*stack_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(*stack_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
	{
		swap(*stack_a);
		swap(*stack_b);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

static void	do_move(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse(stack_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse(stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		reverse(stack_a);
		reverse(stack_b);
	}
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
	{
		rotate(stack_b);
		rotate(stack_a);
	}
	else
		do_move2(stack_a, stack_b, line);
}

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		do_move(stack_a, stack_b, line);
		free(line);
	}
	if (est_valide(*stack_a) == 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tmp;

	if (argc > 1)
	{
		tmp = &argv[1];
		if (argc == 2)
			tmp = ft_split(argv[1], ' ');
		if (check_error(tmp) == 1)
			exit_error2();
		stack_b = NULL;
		stack_a = init_stack(tmp);
		checker(&stack_a, &stack_b);
		if (argc == 2)
			free_split(tmp);
		free_all(&stack_a);
		free_all(&stack_b);
	}
}
