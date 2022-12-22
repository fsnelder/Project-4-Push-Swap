/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <fsnelder@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 11:57:24 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/04/05 11:58:17 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_list **stack_a)
{
	t_list	*temp;

	if ((*stack_a) == NULL)
		return ;
	temp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_back(stack_a, temp);
	temp->next = NULL;
	write (1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*temp;

	if ((*stack_b) == NULL)
		return ;
	temp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_back(stack_b, temp);
	temp->next = NULL;
	write (1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	if ((*stack_a) == NULL || (*stack_b) == NULL)
		return ;
	temp_a = *stack_a;
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_back(stack_a, temp_a);
	temp_a->next = NULL;
	temp_b = *stack_b;
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_back(stack_b, temp_b);
	temp_b->next = NULL;
	write (1, "rr\n", 3);
}

void	rra(t_list **stack_a)
{
	t_list	*temp;

	if ((*stack_a) == NULL)
		return ;
	temp = ft_lstlast(*stack_a);
	ft_oneto_lstlast(*stack_a)->next = NULL;
	ft_lstadd_front(stack_a, temp);
	write (1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;

	if ((*stack_b) == NULL)
		return ;
	temp = ft_lstlast(*stack_b);
	ft_oneto_lstlast(*stack_b)->next = NULL;
	ft_lstadd_front(stack_b, temp);
	write (1, "rrb\n", 4);
}
