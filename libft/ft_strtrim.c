/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:46:37 by melaena           #+#    #+#             */
/*   Updated: 2021/07/31 22:46:36 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static int	set_len(int len, int count)
{
	if (len < count)
		count = len;
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		count;
	char	*start;
	int		len;
	int		iter;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	start = (char *)s1;
	count = 0;
	while (start[count] && is_inset(start[count], set))
		count++;
	iter = 0;
	while (is_inset(start[--len], set))
		;
	len++;
	count = set_len(len, count);
	ptr = (char *)malloc(sizeof(*s1) * (len - count) + 1);
	if (!ptr)
		return (0);
	while (count < len)
		ptr[iter++] = start[count++];
	ptr[iter] = 0;
	return (ptr);
}
