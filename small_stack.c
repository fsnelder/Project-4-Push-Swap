/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <fsnelder@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 11:57:15 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/04/13 10:21:24 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_three(t_list **stack_a)
{
	if (issorted_check(*stack_a) == 0)
		return ;
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
		sa(stack_a);
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
	{	
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		rra(stack_a);
	else
		ra(stack_a);
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		position;
	t_list	*head;

	position = 0;
	head = (*stack_a);
	min = min_number(*stack_a);
	(*stack_a) = head;
	while ((*stack_a) != NULL )
	{
		if (min == (*stack_a)->content)
			break ;
		(*stack_a) = (*stack_a)->next;
		position++;
	}
	(*stack_a) = head;
	while (position > 0)
	{
		ra(stack_a);
		position--;
	}
	pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	ft_handle_five(t_list **stack_a, t_list **stack_b, int position)
{
	if (position < 3)
	{
		while (position > 0)
		{
			ra(stack_a);
			position--;
		}
		pb(stack_a, stack_b);
		ft_sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
		return ;
	}
	while ((5 - position) > 0)
	{
		rra(stack_a);
		position++;
	}
	pb(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		position;
	t_list	*temp;

	position = 0;
	temp = (*stack_a);
	min = min_number(*stack_a);
	while ((*stack_a) != NULL )
	{
		if (min == temp->content)
			break ;
		temp = temp->next;
		position++;
	}
	ft_handle_five(stack_a, stack_b, position);
}

int	ft_sort_small_stack(t_list **stack_a, t_list **stack_b, int stack_length)
{
	if (stack_length == 2)
		ra(stack_a);
	if (stack_length == 3)
		ft_sort_three(stack_a);
	if (stack_length == 4)
		ft_sort_four(stack_a, stack_b);
	if (stack_length == 5)
		ft_sort_five(stack_a, stack_b);
	freefunctie(stack_a);
	return (0);
}
