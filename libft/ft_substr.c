/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:23:17 by melaena           #+#    #+#             */
/*   Updated: 2020/11/03 15:30:57 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		count;
	size_t	iter;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	ptr = (char *)malloc(sizeof(*s) * (len) + 1);
	if (!ptr)
		return (0);
	iter = -1;
	count = start;
	while (++iter < len)
		ptr[iter] = s[count++];
	ptr[iter] = 0;
	return (ptr);
}
