/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:06:06 by melaena           #+#    #+#             */
/*   Updated: 2021/07/31 22:54:46 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	count;
	int	len;

	if (!s)
		return ;
	count = -1;
	len = ft_strlen(s);
	while (++count < len)
		write(fd, &s[count], 1);
}
