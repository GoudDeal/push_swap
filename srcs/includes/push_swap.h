/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:05:29 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/12 12:59:31 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		ft_strisdigit(char	*str);
void	get_stack(t_stack *stack, int ac, char **av);
void	ft_sab(t_stack *stack, char *type);
void	ft_ssab(t_stack *stack_a, t_stack *stack_b);
void	verify(t_stack *stack);
void	verify_all(t_stack *stack);
void	go_to_first(t_stack **stack);
void	go_to_last(t_stack **stack);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_rab(t_stack **stack, char *type);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rrab(t_stack **stack, char *type);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	redirect(t_stack **stack_a, t_stack **stack_b, int ac);
void	sort_2(t_stack **stack);
void	sort_3_1(t_stack **stack);
void	sort_3_2(t_stack **stack);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	big_sort(t_stack **stack_a, t_stack **stack_b);
void	get_lowest(t_stack **stack);
int		exception(t_stack *stack);
int		get_data_index(t_stack *stack);
void	set_index(t_stack *stack);
int		check_double(char **av, int ac);
int		get_highest_index(t_stack *stack);
int		is_sorted(t_stack *stack);
int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_stack	*ft_lstnew(int content);
int		ft_isdigit(int c);

#endif