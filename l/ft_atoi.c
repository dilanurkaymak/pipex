/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:47:19 by dkaymak           #+#    #+#             */
/*   Updated: 2025/07/09 06:40:20 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	skip_whitespace(const char *nptr, int i)
{
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	return (i);
}

static	int	check_sign(const char *nptr, int i, int *sign)
{
	if (nptr[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	i = skip_whitespace(nptr, i);
	i = check_sign(nptr, i, &sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
