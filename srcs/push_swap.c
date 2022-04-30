/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:41:34 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/14 21:35:56 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_error(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		return (1);
	if (ac < 2)
		return (0);
	while (av[i])
	{
		if (ft_strlen(av[i]) >= 10)
		{	
			if (ft_strncmp(av[i], "2147483647", ft_strlen(av[i])) >= 1)
				return (0);
			else if (ft_strncmp(av[i], "-2147483648", ft_strlen(av[i])) >= 1
				&& av[i][0] == '-')
				return (0);
		}
		if (ft_strisdigit(av[i]) != 1)
			return (0);
		i++;
	}
	if (check_double(av, ac) == 0)
		return (0);
	return (1);
}

int	check_double(char **av, int ac)
{
	int	i;
	int	num;
	int	recurrence;

	i = 1;
	num = ft_atoi(av[i]);
	while (ac > 1)
	{
		i = 1;
		recurrence = 0;
		while (av[i])
		{
			if (num == ft_atoi(av[i]))
				recurrence++;
			i++;
		}
		if (recurrence >= 2)
			return (0);
		ac--;
		num = ft_atoi(av[i - ac]);
	}
	return (1);
}

void	free_them_all(t_stack *stack)
{
	t_stack	*tmp;

	if (stack)
	{
		go_to_first(&stack);
		while (stack)
		{
			tmp = stack->next;
			free(stack);
			stack = tmp;
		}
		free(tmp);
	}
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_b = NULL;
	stack_a = ft_lstnew(ft_atoi(av[1]));
	if (check_error(ac, av))
	{
		get_stack(stack_a, ac, av);
		redirect(&stack_a, &stack_b, ac);
		free_them_all(stack_a);
	}
	else
	{
		free_them_all(stack_a);
		write(1, "Error\n", 6);
	}
	return (0);
}
