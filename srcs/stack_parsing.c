/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:35:22 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/12 12:59:11 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	go_to_last(t_stack **stack)
{
	if ((*stack))
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
	}
}

void	go_to_first(t_stack **stack)
{
	if ((*stack))
	{
		while ((*stack)->prev)
			(*stack) = (*stack)->prev;
	}
}

void	get_lowest(t_stack **stack)
{
	int	low;

	low = (*stack)->data;
	while ((*stack)->next)
	{
		if ((*stack)->data < low)
			low = (*stack)->data;
		(*stack) = (*stack)->next;
	}
	if ((*stack)->data < low)
		low = (*stack)->data;
	go_to_first(stack);
	while ((*stack)->next)
	{
		if ((*stack)->data != low)
			(*stack) = (*stack)->next;
		else
			break ;
	}
}
