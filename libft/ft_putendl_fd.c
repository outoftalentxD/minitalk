/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:09:21 by melaena           #+#    #+#             */
/*   Updated: 2021/07/31 22:54:34 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	count;
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	count = -1;
	while (++count < len)
		write(fd, &s[count], 1);
	write(fd, "\n", 1);
}
