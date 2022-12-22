/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manage_input.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <fsnelder@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 11:56:54 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/04/12 14:20:32 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	error(t_list **stack)
{
	t_list	*temp;

	temp = (*stack);
	while ((*stack) != NULL)
	{
		(*stack) = (*stack)-> next;
		free (temp);
		temp = (*stack);
	}
	stack = NULL;
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	overall_check(t_list **stack)
{
	t_list	*head;

	head = (*stack);
	if ((*stack) == NULL)
		return (error(stack));
	while ((*stack) != NULL)
	{
		if (double_check(*stack) == 0)
			return (error(stack));
		(*stack) = (*stack)->next;
	}
	(*stack) = head;
	if (issorted_check(*stack) == 0)
		return (0);
	return (1);
}

int	double_check(t_list *stack)
{
	int	number;

	number = stack -> content;
	while (stack -> next != NULL)
	{
		stack = stack -> next;
		if (number == stack -> content)
			return (0);
	}
	return (1);
}

int	issorted_check(t_list *stack)
{
	t_list	*temp;

	while (stack -> next != NULL)
	{
		temp = stack;
		stack = stack -> next;
		if (temp -> content > stack -> content)
			return (1);
	}
	return (0);
}
