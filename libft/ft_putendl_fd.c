/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajid <amajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:22:49 by amajid            #+#    #+#             */
/*   Updated: 2023/11/10 16:13:27 by amajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putendl_fd(char *s, int fd)
{
	size_t	size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (write(fd, s, size) == -1)
		return (-1);
	if (write(fd, "\n", 1) == -1)
		return (-1);
	return (size + 1);
}
