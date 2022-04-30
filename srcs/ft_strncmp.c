/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:48:35 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/12 12:58:33 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL && n != 0)
	{
		while ((*s1 || *s2) && *s1 == *s2 && --n > 0)
		{
			s1++;
			s2++;
		}
		return (((unsigned char)*s1 - (unsigned char)*s2));
	}
	return (0);
}
