/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <fsnelder@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 11:56:44 by fsnelder      #+#    #+#                 */
/*   Updated: 2022/04/13 12:54:12 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	freefunctie(t_list **stack)
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
}

t_list	*create_stack(char **argv, t_list *stack_a, int stack_length)
{
	int		num;
	t_list	*temp;
	int		i;

	i = 1;
	num = 0;
	temp = NULL;
	while (i <= stack_length)
	{
		num = ft_atoi(argv[i]);
		temp = ft_lstnew(num);
		if (temp == NULL)
			freefunctie(&stack_a);
		ft_lstadd_back(&stack_a, temp);
		i++;
	}
	return (stack_a);
}

void	add_position_to_list(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp != NULL)
	{
		temp->position = check_position(&stack, temp->content);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	int		stack_length;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*head;

	stack_a = NULL;
	stack_b = NULL;
	head = NULL;
	stack_length = argc - 1;
	if (argv[1] == '\0')
		return (0);
	stack_a = create_stack(argv, stack_a, stack_length);
	if (stack_a == 0)
		return (0);
	head = stack_a;
	if (overall_check(&stack_a) == 0)
		return (0);
	stack_a = head;
	add_position_to_list(stack_a);
	if (stack_length < 6)
		ft_sort_small_stack(&stack_a, &stack_b, stack_length);
	else
		ft_sort_large_stack(stack_a, stack_b);
	return (0);
}
