/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:34:47 by melaena           #+#    #+#             */
/*   Updated: 2020/10/31 23:32:46 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len1;
	int		len2;

	if (!s1)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ptr == 0)
		return (0);
	ptr[len1 + len2] = 0;
	while (len2--)
		ptr[len1 + len2] = s2[len2];
	while (len1--)
		ptr[len1] = s1[len1];
	return (ptr);
}
