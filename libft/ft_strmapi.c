/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:59:16 by dkaymak           #+#    #+#             */
/*   Updated: 2025/07/06 16:19:25 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*allocated;
	size_t			len;
	size_t			i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	allocated = (char *)malloc(sizeof(char) * (len + 1));
	if (!allocated)
		return (NULL);
	i = 0;
	while (i < len)
	{
		allocated[i] = f(i, s[i]);
		i++;
	}
	allocated[len] = '\0';
	return (allocated);
}
