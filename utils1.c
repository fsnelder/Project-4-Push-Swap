/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <fsnelder@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 11:56:30 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/04/05 11:58:35 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list **stack_a)
{
	int	temp;

	if ((*stack_a) == NULL)
		return ;
	if ((*stack_a)->next)
	{
		temp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = temp;
	}
	write (1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	int	temp;

	if ((*stack_b) == NULL)
		return ;
	if ((*stack_b)->next)
	{
		temp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = temp;
	}
	write (1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	int	temp_a;
	int	temp_b;

	if ((*stack_a) == NULL)
		return ;
	if ((*stack_a)->next)
	{
		temp_a = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = temp_a;
	}	
	if ((*stack_b) == NULL)
		return ;
	if ((*stack_b)->next)
	{
		temp_b = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = temp_b;
	}	
	write (1, "ss\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if ((*stack_a) == NULL)
		return ;
	temp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_front(stack_b, temp);
	write (1, "pb\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if ((*stack_b) == NULL)
		return ;
	temp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_front(stack_a, temp);
	write (1, "pa\n", 3);
}
