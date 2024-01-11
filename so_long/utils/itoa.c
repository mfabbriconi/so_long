/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:11:09 by mfabbric          #+#    #+#             */
/*   Updated: 2023/04/05 16:11:41 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	div_calc(int power)
{
	int	result;

	result = 1;
	while (power > 1)
	{
		result *= 10;
		power--;
	}
	return (result);
}

int	allocate_memory(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		n += 1;
	}
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i += 2;
	return (i);
}

char	*conversion_minint(int n, int power, char *str)
{
	int	i;
	int	div;
	int	n_const;

	i = 0;
	n += 1;
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	div = div_calc(power);
	n_const = n;
	while (div > 9)
	{
		n = n / div;
		div = div / 10;
		str[i++] = (n % 10) + '0';
		n = n_const;
	}
	str[i++] = ((n % 10) + 1) + '0';
	str[i] = '\0';
	return (str);
}

char	*conversion(int n, int power, char *str)
{
	int	i;
	int	div;
	int	n_const;

	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	div = div_calc(power);
	n_const = n;
	while (div > 9)
	{
		n = n / div;
		div = div / 10;
		str[i++] = (n % 10) + '0';
		n = n_const;
	}
	str[i++] = (n % 10) + '0';
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		power;

	size = allocate_memory(n);
	if (n < 0)
		power = size - 2;
	if (n >= 0)
		power = size - 1;
	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (0);
	if (n == -2147483648)
		conversion_minint(n, power, str);
	else
		str = conversion(n, power, str);
	return (str);
}
