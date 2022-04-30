/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:12:41 by user42            #+#    #+#             */
/*   Updated: 2022/01/12 12:59:00 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	go_to_first(&stack);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		else if (stack->data < stack->next->data
			|| stack->data == stack->next->data)
			stack = stack->next;
	}
	return (1);
}

void	redirect(t_stack **stack_a, t_stack **stack_b, int ac)
{
	(void)stack_b;
	if (is_sorted((*stack_a)) == 1)
		return ;
	if (ac == 3)
		sort_2(stack_a);
	if (ac == 4)
		sort_3_1(stack_a);
	if (ac == 5)
		sort_4(stack_a, stack_b);
	if (ac == 6)
		sort_5(stack_a, stack_b);
	if (ac >= 7)
		big_sort(stack_a, stack_b);
}

void	sort_2(t_stack **stack)
{
	if ((*stack))
	{
		if ((*stack)->data < (*stack)->next->data)
			return ;
		if ((*stack)->data == (*stack)->next->data)
			return ;
		if ((*stack)->data > (*stack)->next->data)
			ft_sab((*stack), "sa");
	}
}

void	sort_3_1(t_stack **stack)
{
	if ((*stack))
	{
		if ((*stack)->data < (*stack)->next->data
			&& (*stack)->next->data < (*stack)->next->next->data)
			return ;
		if ((*stack)->data > (*stack)->next->data)
		{
			ft_sab((*stack), "sa");
			go_to_last(stack);
			if ((*stack)->data < (*stack)->prev->data)
			{
				if ((*stack)->data < (*stack)->prev->prev->data)
					ft_rrab(stack, "rra");
				else
				{
					ft_rrab(stack, "rra");
					ft_sab((*stack), "sa");
					go_to_first(stack);
					return ;
				}
			}
		}
		sort_3_2(stack);
	}
}

void	sort_3_2(t_stack **stack)
{
	go_to_first(stack);
	if ((*stack)->data < (*stack)->next->data
		&& (*stack)->data > (*stack)->next->next->data)
	{
		ft_rrab(stack, "rra");
		go_to_first(stack);
		return ;
	}
	if ((*stack)->data < (*stack)->next->data
		&& (*stack)->next->data > (*stack)->next->next->data)
	{
		ft_rrab(stack, "rra");
		ft_sab((*stack), "sa");
		go_to_first(stack);
		return ;
	}
	return ;
}
