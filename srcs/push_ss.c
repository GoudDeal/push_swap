/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:47:48 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/12 12:58:40 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sab(t_stack *stack, char *type)
{
	int		tmp;
	int		index_tmp;
	t_stack	*cur;

	if (type)
	{
		ft_putstr_fd(type, 1);
		write(1, "\n", 1);
	}
	cur = stack->next;
	tmp = stack->data;
	index_tmp = stack->index;
	if (!stack->data || !stack->next)
		return ;
	stack->data = cur->data;
	stack->index = cur->index;
	cur->data = tmp;
	cur->index = index_tmp;
}

void	ft_ssab(t_stack *stack_a, t_stack *stack_b)
{
	ft_sab(stack_a, "ss\n");
	ft_sab(stack_b, NULL);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if ((*stack_b))
	{
		ft_putstr_fd("pa\n", 1);
		go_to_first(stack_a);
		go_to_first(stack_b);
		tmp = (*stack_b);
		if ((*stack_b)->next)
			(*stack_b) = (*stack_b)->next;
		else
			(*stack_b) = NULL;
		(*stack_a)->prev = tmp;
		tmp->next = (*stack_a);
		tmp->prev = NULL;
		(*stack_a) = tmp;
		if ((*stack_b))
			(*stack_b)->prev = NULL;
		go_to_first(stack_a);
	}
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if ((*stack_a))
	{
		ft_putstr_fd("pb\n", 1);
		go_to_first(stack_a);
		tmp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		if (!(*stack_b))
		{
			(*stack_b) = tmp;
			(*stack_a)->prev = NULL;
			(*stack_b)->next = NULL;
		}
		else
		{
			go_to_first(stack_b);
			(*stack_b)->prev = tmp;
			tmp->next = (*stack_b);
			tmp->prev = NULL;
			(*stack_a)->prev = NULL;
		}
	}
}
