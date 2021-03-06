/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:42:01 by telee             #+#    #+#             */
/*   Updated: 2021/05/18 08:23:54 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	*ft_calloc(size_t count, size_t size)
{
	long	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	while (i < count)
		ptr[i++] = 2147483648;
	return (ptr);
}
