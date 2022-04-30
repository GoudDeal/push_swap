/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:54:22 by user42            #+#    #+#             */
/*   Updated: 2022/01/12 12:58:53 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rab(t_stack **stack, char *type)
{
	t_stack	*tmp;

	if ((*stack))
	{
		go_to_first(stack);
		tmp = (*stack);
		(*stack)->next->prev = NULL;
		go_to_last(stack);
		(*stack)->next = tmp;
		tmp->prev = (*stack);
		tmp->next = NULL;
		go_to_first(stack);
		if (type)
		{
			ft_putstr_fd(type, 1);
			write(1, "\n", 1);
		}
	}
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rab(stack_a, "rr");
	ft_rab(stack_b, NULL);
}

void	ft_rrab(t_stack **stack, char *type)
{
	t_stack	*tmp;

	if ((*stack))
	{
		if (type)
		{
			ft_putstr_fd(type, 1);
			write(1, "\n", 1);
		}
		go_to_last(stack);
		tmp = (*stack);
		(*stack)->prev->next = NULL;
		go_to_first(stack);
		(*stack)->prev = tmp;
		tmp->next = (*stack);
		tmp->prev = NULL;
		go_to_first(stack);
	}
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrab(stack_a, "rrr");
	ft_rrab(stack_b, NULL);
}
