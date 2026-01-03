/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:04:33 by dkaymak           #+#    #+#             */
/*   Updated: 2025/07/09 14:11:53 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	put_number_str(char *str, int n, int len)
{
	unsigned int	num;

	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		num = (unsigned int)(-n);
	}
	else
		num = (unsigned int)n;
	while (len-- > 0)
	{
		if (str[len] == '-')
			break ;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = count_digits(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	put_number_str(str, n, len);
	return (str);
}
