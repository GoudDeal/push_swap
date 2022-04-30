/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:36:30 by user42            #+#    #+#             */
/*   Updated: 2022/01/12 12:59:06 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 2;
	while (i > 0)
	{
		get_lowest(stack_a);
		if (!(*stack_a)->next || !(*stack_a)->next->next)
			ft_rrab(stack_a, "rra");
		else if ((*stack_a)->prev)
			ft_rab(stack_a, "ra");
		get_lowest(stack_a);
		if (!(*stack_a)->prev)
		{
			ft_pb(stack_a, stack_b);
			i--;
		}
	}
	sort_3_1(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
