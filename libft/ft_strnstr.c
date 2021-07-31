/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:17:20 by melaena           #+#    #+#             */
/*   Updated: 2021/07/31 22:54:27 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(const char *haystack, size_t len)
{
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	return (len);
}

char	*ft_strnstr(const char *haystack,
				const char *needle, size_t len)
{
	size_t	count;
	size_t	iter;
	size_t	sublen;

	count = -1;
	iter = 0;
	if (*needle == '\0')
		return ((char *)(haystack));
	sublen = ft_strlen(needle);
	len = get_len(haystack, len);
	while (++count < len)
	{
		if (haystack[count] == needle[iter])
			iter++;
		else
		{
			count -= iter;
			iter = 0;
		}
		if (iter == sublen)
			return ((char *)haystack + count - sublen + 1);
	}
	return (0);
}
