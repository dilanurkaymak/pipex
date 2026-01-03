/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:20:50 by dkaymak           #+#    #+#             */
/*   Updated: 2025/07/09 14:15:55 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	trim_start;
	size_t	trim_end;
	size_t	i;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	trim_start = 0;
	while (s1[trim_start] && ft_strchr(set, s1[trim_start]))
		trim_start++;
	trim_end = ft_strlen(s1);
	while (trim_end > trim_start && ft_strchr(set, s1[trim_end - 1]))
		trim_end--;
	trimmed = malloc(trim_end - trim_start + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (trim_start < trim_end)
	{
		trimmed[i] = s1[trim_start];
		i++;
		trim_start++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
