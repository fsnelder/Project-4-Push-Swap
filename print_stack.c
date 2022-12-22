/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <fsnelder@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 11:57:06 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/04/13 10:24:33 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	max_position(t_list *stack)
{
	int		new_max;
	t_list	*temp;

	new_max = 0;
	temp = stack;
	while (stack != NULL)
	{
		if (new_max < stack->position)
			new_max = stack->position;
		stack = stack->next;
	}
	stack = temp;
	return (new_max);
}

int	min_number(t_list *stack)
{
	int		new_min;
	t_list	*temp;

	temp = stack;
	new_min = temp->content;
	while (temp != NULL)
	{
		if (new_min > temp->content)
			new_min = temp->content;
		temp = temp->next;
	}
	stack = temp;
	return (new_min);
}

static int	getmaxbit(int num)
{
	int	maxbit;

	maxbit = 0;
	while ((num >> maxbit) != 0)
		maxbit++;
	return (maxbit);
}

int	ft_sort_large_stack(t_list *stack_a, t_list *stack_b)
{
	int	bit_compare;
	int	maxbit;
	int	i;
	int	size;

	size = ft_lstsize(stack_a);
	maxbit = 0;
	while (maxbit < getmaxbit(max_position(stack_a)))
	{
		i = 0;
		while (i < size)
		{
			bit_compare = (stack_a->position >> maxbit) & 1;
			if (bit_compare == 1)
				ra(&stack_a);
			if (bit_compare == 0)
				pb(&stack_a, &stack_b);
			i++;
		}
		while (stack_b != NULL)
			pa(&stack_a, &stack_b);
		maxbit++;
	}
	freefunctie(&stack_a);
	return (0);
}
