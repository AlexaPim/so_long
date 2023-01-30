/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ado-prad <ado-prad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:50:36 by ado-prad          #+#    #+#             */
/*   Updated: 2023/01/30 16:16:42 by ado-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_count_dig(int n)
{
	int	i;

	i = 1;
	while (n < -9 || n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	digits = ft_count_dig(n);
	str = (char *)malloc(digits * sizeof(char) + (n < 0) + 1);
	if (n < 0)
		str[0] = '-';
	str[digits + (n < 0)] = '\0';
	while (digits > 0)
	{
		str[digits + (n < 0) - 1] = ft_abs(n % 10) + '0';
		n /= 10;
		digits--;
	}
	return (str);
}
