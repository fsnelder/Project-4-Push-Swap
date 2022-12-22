/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:40:51 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/04/12 14:13:06 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		print_stack(t_list *stack_a, t_list *stack_b);
int		radix_sort(t_list *stack_a, t_list *stack_b);
int		ft_sort_large_stack(t_list *stack_a, t_list *stack_b);
int		max_position(t_list *stack);
int		min_number(t_list *stack);
t_list	*ft_oneto_lstlast(t_list *lst);
t_list	*ft_smallest_node(t_list **stack);
t_list	simple_numbering(t_list **stack);
int		check_position(t_list **stack, int node);
void	add_position_to_list(t_list *stack);
void	freefunctie(t_list **stack);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

int		overall_check(t_list **stack);
int		double_check(t_list *stack);
int		issorted_check(t_list *stack);

void	ft_sort_three(t_list **stack_a);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);
void	ft_handle_five(t_list **stack_a, t_list **stack_b, int position);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);
int		ft_sort_small_stack(t_list **stack_a, t_list **stack_b,
			int stack_length);

#endif
