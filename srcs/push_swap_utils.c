/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:43:05 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/12 12:58:45 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strisdigit(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

void	get_stack(t_stack *stack, int ac, char **av)
{
	t_stack	*current;
	t_stack	*prev;
	int		i;

	i = 2;
	current = stack;
	prev = stack;
	current->prev = NULL;
	while (ac > 2)
	{
		current->next = ft_lstnew(ft_atoi(av[i]));
		current = current->next;
		current->prev = prev;
		prev = current;
		current->index = -2147483648;
		i++;
		ac--;
	}
	set_index(stack);
}

void	get_lowest_index(t_stack **stack)
{
	int	low;

	while ((*stack)->index != -2147483648 && (*stack)->next)
		(*stack) = (*stack)->next;
	low = (*stack)->data;
	while ((*stack)->next)
	{
		if ((*stack)->data < low && (*stack)->index == -2147483648)
			low = (*stack)->data;
		(*stack) = (*stack)->next;
	}
	if ((*stack)->data < low && (*stack)->index == -2147483648)
		low = (*stack)->data;
	go_to_first(stack);
	while ((*stack)->next)
	{
		if ((*stack)->data != low && (*stack)->index != -2147483648)
			(*stack) = (*stack)->next;
		else if ((*stack)->data == low && (*stack)->index == -2147483648)
			break ;
		else
			(*stack) = (*stack)->next;
	}
	if (!(*stack)->next && (*stack)->index == -2147483648)
		(*stack)->index = get_highest_index((*stack)) + 1;
}

int	check_all_index(t_stack *stack)
{
	go_to_first(&stack);
	while (stack->next)
	{
		if (stack->index == -2147483648)
			return (0);
		stack = stack->next;
	}
	if (stack->index == -2147483648)
		return (0);
	go_to_first(&stack);
	return (1);
}

void	set_index(t_stack *stack)
{
	int		low;
	int		i;

	i = 1;
	get_lowest(&stack);
	low = stack->data;
	stack->index = 0;
	go_to_first(&stack);
	if (stack->data != low)
		stack->index = -2147483648;
	while (check_all_index(stack) == 0)
	{
		go_to_first(&stack);
		get_lowest_index(&stack);
		stack->index = i;
		i++;
	}
}
