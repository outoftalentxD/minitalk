/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:10:50 by melaena           #+#    #+#             */
/*   Updated: 2021/07/31 23:05:39 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char const *s, char c)
{
	int	words_count;
	int	count;

	count = 0;
	words_count = 0;
	while (s[count])
	{
		if (s[count] != c && s[count])
		{
			words_count++;
			while (s[count] != c && s[count])
				count++;
		}
		else
			count++;
	}
	return (words_count);
}

static char	*get_word(char *ptr, char c)
{
	int		len;
	char	*word;
	char	*temp;
	int		count;

	count = 0;
	temp = ptr;
	len = 0;
	while (*temp != c && *temp++)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == 0)
		return (0);
	temp = ptr;
	while (*temp != c && *temp)
		word[count++] = *temp++;
	word[count] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		strs_len;
	int		count;

	if (!s)
		return (0);
	strs_len = words_count(s, c);
	strs = (char **)malloc(sizeof(char *) * (strs_len + 1));
	if (!strs)
		return (0);
	strs[strs_len] = 0;
	count = -1;
	while (++count < strs_len)
	{
		while (*s == c && *s)
			s++;
		strs[count] = get_word((char *)s, c);
		while (*s != c && *s)
			s++;
	}
	return (strs);
}
