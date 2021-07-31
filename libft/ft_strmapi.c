/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:53:51 by melaena           #+#    #+#             */
/*   Updated: 2020/11/03 15:30:30 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	count;
	unsigned int	len;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!ptr)
		return (0);
	count = 0;
	while (count < len)
	{
		ptr[count] = f(count, s[count]);
		count++;
	}
	ptr[count] = 0;
	return (ptr);
}
