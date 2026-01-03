/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:06:07 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/28 17:52:30 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;
	int	len;

	len = ft_strlen(s);
	count = 0;
	i = 0;
	while (i < len)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	word_length(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	return (len);
}

static void	free_all(char **arr, int count)
{
	while (count--)
		free(arr[count]);
	free(arr);
}

static int	split_words(char **sub_str, char const *s, char c, int word_count)
{
	int	i;
	int	word_index;
	int	len;

	i = 0;
	word_index = 0;
	while (s[i] && word_index < word_count)
	{
		while (s[i] && s[i] == c)
			i++;
		len = word_length(s, c, i);
		sub_str[word_index] = malloc(len + 1);
		if (!sub_str[word_index])
		{
			free_all(sub_str, word_index);
			return (0);
		}
		ft_strlcpy(sub_str[word_index], &s[i], len + 1);
		i += len;
		word_index++;
	}
	sub_str[word_index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**sub_str;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	sub_str = malloc(sizeof(char *) * (word_count + 1));
	if (!sub_str)
		return (NULL);
	if (!split_words(sub_str, s, c, word_count))
		return (NULL);
	return (sub_str);
}
