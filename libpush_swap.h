/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:09:33 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/13 10:57:03 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_SWAP_H
# define LIBPUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

typedef struct s_stack
{	
	struct s_stack	*next;
	int				value;
	int				index;
	int				nb_bit;
}t_stack;

t_stack	*new_stack(int value);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*init_stack(char **av);
double	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
void	stack_addback(t_stack **stack, int value);
void	trieur_3_val(t_stack **stack);
void	trieur_4_val(t_stack **stack_a, t_stack **stack_b);
void	trieur_5_val(t_stack **stack_a, t_stack **stack_b);
void	trieur(t_stack **stack_a, t_stack**stack_b, int stack_size);
void	ranger_nb(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack *stack_a);
void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	swap_s(t_stack **stack_a, t_stack **stack_b);
void	reverse(t_stack **stack);
void	reverse_a(t_stack **stack);
void	reverse_b(t_stack **stack);
void	reverse_rr(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_r(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **src, t_stack **dst);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
void	exit_error2(void);
void	free_split(char **tmp);
void	free_all(t_stack **stack);
void	ft_putstr(char *s);
void	ft_putnbr_fd(int n, int fd);
int		est_decroissant(t_stack *stack);
int		est_valide(t_stack *stack);
int		stack_size(t_stack *stack);
int		check_input(char **str);
int		check_doublon(char **str);
int		check_error(char **str);
int		ft_isdigit(int nbr);
int		ft_strncmp(const char *s1, const char *s2, size_t size);

#endif
