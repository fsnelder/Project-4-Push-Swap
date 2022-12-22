/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <fsnelder@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 11:57:34 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/04/12 13:34:28 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	if ((*stack_a) == NULL || (*stack_b) == NULL)
		return ;
	temp_a = ft_lstlast(*stack_a);
	ft_oneto_lstlast(*stack_a)->next = NULL;
	ft_lstadd_front(stack_a, temp_a);
	temp_b = ft_lstlast(*stack_b);
	ft_oneto_lstlast(*stack_b)->next = NULL;
	ft_lstadd_front(stack_b, temp_b);
	write(1, "rrr\n", 4);
}

t_list	*ft_oneto_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next->next == NULL)
			return (lst);
		else
			lst = lst->next;
	}
	return (lst);
}

t_list	*ft_smallest_node(t_list **stack)
{
	t_list	*new_min;

	new_min = NULL;
	while ((*stack) != NULL)
	{
		if (new_min > (*stack))
			new_min = (*stack);
		(*stack) = (*stack)->next;
	}
	return (new_min);
}

int	check_position(t_list **stack, int node)
{
	int		position;
	t_list	*temp;

	temp = (*stack);
	position = 0;
	while (temp != NULL)
	{
		if (temp->content < node)
			position++;
		temp = temp->next;
	}
	return (position);
}
