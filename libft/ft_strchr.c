/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:43:33 by melaena           #+#    #+#             */
/*   Updated: 2020/10/31 23:32:19 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int		count;

	count = -1;
	while (str[++count])
		if (str[count] == c)
			return ((char *)str + count);
	if (c == 0)
		return ((char *)str + count);
	return (0);
}
