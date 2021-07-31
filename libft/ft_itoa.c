/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:58:37 by melaena           #+#    #+#             */
/*   Updated: 2021/07/31 22:47:03 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	modulo(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static char	*get_ptr(int n, int len)
{
	char	*ptr;

	if (n < 0)
	{
		ptr = (char *)malloc(sizeof(char) * (len + 2));
		if (!ptr)
			return (0);
		ptr[0] = '-';
		ptr[len + 1] = 0;
	}
	else
	{
		ptr = (char *)malloc(sizeof(char) * (len + 1));
		if (!ptr)
			return (0);
		ptr[len] = 0;
	}
	return (ptr);
}

static char	*fill_ptr(char *ptr, int count, int pow, int n)
{
	while (1)
	{
		ptr[count++] = n / pow + '0';
		n -= n / pow * pow;
		pow /= 10;
		if (modulo(pow) < 1)
			break ;
	}
	ptr[count] = 0;
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		pow;
	int		len;
	int		count;

	count = 0;
	len = 1;
	pow = 1;
	while (pow <= modulo(n / 10) && ++len != 1)
		pow *= 10;
	ptr = get_ptr(n, len);
	if (!ptr)
		return (0);
	if (n < 0)
	{
		pow = -pow;
		len++;
		count++;
	}
	ptr = fill_ptr(ptr, count, pow, n);
	return (ptr);
}
