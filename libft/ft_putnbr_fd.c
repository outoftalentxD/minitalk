/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:12:25 by melaena           #+#    #+#             */
/*   Updated: 2020/10/31 23:31:48 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		pow;
	int		val;

	if (n < 0)
		val = -(n / 10);
	else
		val = n / 10;
	if (n < 0)
		write(fd, "-", 1);
	pow = 1;
	while (pow < val)
		pow *= 10;
	if (n < 0)
		pow = -pow;
	while (pow)
	{
		c = n / pow + '0';
		write(fd, &c, 1);
		n -= n / pow * pow;
		pow /= 10;
	}
}
