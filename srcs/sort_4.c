/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:56:59 by user42            #+#    #+#             */
/*   Updated: 2022/01/12 12:59:03 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	if (exception((*stack_a)) == 1)
	{
		ft_rrab(stack_a, "rra");
		return ;
	}
	get_lowest(stack_a);
	while ((*stack_a)->prev)
	{
		ft_rab(stack_a, "ra");
		get_lowest(stack_a);
	}
	ft_pb(stack_a, stack_b);
	sort_3_1(stack_a);
	ft_pa(stack_a, stack_b);
}

int	exception(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data == stack->next->data)
			stack = stack->next;
		else
		{
			stack = stack->next;
			break ;
		}
	}
	if (!stack->next)
		return (1);
	return (0);
}
