/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:20:32 by dcyprien          #+#    #+#             */
/*   Updated: 2022/01/12 12:58:16 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst != NULL && src != NULL && src != dst)
	{
		if (src <= dst)
		{
			d = (unsigned char *)dst;
			s = (unsigned char *)src;
			while (len--)
				d[len] = s[len];
		}
		else
			ft_memcpy(dst, src, len);
		return (dst);
	}
	return (NULL);
}
