/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajid <amajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:35:42 by amajid            #+#    #+#             */
/*   Updated: 2023/11/10 16:01:12 by amajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static char	*reverse(char *str)
{
	int				len;
	unsigned int	i;
	char			*result;

	i = 0;
	len = ft_strlen(str);
	result = malloc(len + 1);
	if (!result)
	{
		free(str);
		return (NULL);
	}
	len--;
	while (len > -1)
		result[i++] = str[len--];
	result[i] = 0;
	free(str);
	return (result);
}

static char	*check(void)
{
	char	*hexa_number;

	hexa_number = ft_calloc(2, 1);
	if (!hexa_number)
		return (NULL);
	hexa_number[0] = '0';
	return (hexa_number);
}

char	*ft_itoh(unsigned long long val, char prefix)
{
	int					i;
	unsigned long long	temp;
	char				*hexa_number;
	char				*result;

	i = 0;
	if (!val)
		return (check());
	temp = val;
	while (temp && ++i)
		temp /= 16;
	hexa_number = ft_calloc(i + 2, 1);
	if (!hexa_number)
		return (NULL);
	i = 0;
	while (val)
	{
		temp = val % 16;
		temp = (temp < 10) * (temp + '0')
			+ (temp + prefix - 10) * !(temp < 10);
		hexa_number[i++] = temp;
		val /= 16;
	}
	result = reverse(hexa_number); 
	return (result);
}
