/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:40:10 by user42            #+#    #+#             */
/*   Updated: 2022/01/12 12:56:03 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_highest_index(t_stack *stack)
{
	int	high;

	go_to_first(&stack);
	high = stack->index;
	while (stack->next)
	{
		if (stack->index > high)
			high = stack->index;
		if (stack->next)
			stack = stack->next;
	}
	if (stack->index > high)
		high = stack->index;
	return (high);
}

int	get_bytes(int index)
{
	int	i;

	i = 0;
	while ((index / 2) > 0)
	{
		index = index / 2;
		i++;
	}
	return (i + 1);
}

int	get_size(t_stack *stack)
{
	int	i;

	i = 0;
	go_to_first(&stack);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	bytes_num;
	int	i;
	int	size;
	int	j;

	bytes_num = get_bytes(get_highest_index((*stack_a)));
	size = get_size((*stack_a));
	i = 0;
	while (i < bytes_num)
	{
		j = 0;
		while (j < size)
		{
			if ((*stack_a)->index >> i & 1)
				ft_rab(stack_a, "ra");
			else
				ft_pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			ft_pa(stack_a, stack_b);
		i++;
	}
}
