/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:01:14 by dkaymak           #+#    #+#             */
/*   Updated: 2025/07/03 19:30:46 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*last;
	int		i;

	last = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			last = (char *)(str + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(str + i));
	return (last);
}
