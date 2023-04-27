/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spookier <spxxky.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:18:10 by spookier           #+#    #+#             */
/*   Updated: 2023/03/15 22:36:51 by spookier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	check_size(const char *str)
{
	int		size;
	char	*flags;

	size = 0;
	flags = "cspdiuxX%";
	size = count_flags(str, flags);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		num_args;
	va_list	args;
	int		count;

	if (!str)
		return (0);
	num_args = check_size(str);
	va_start(args, str);
	count = print_all(args, str, num_args);
	va_end(args);
	return (count);
}
