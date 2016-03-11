/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:42:06 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/10 15:54:20 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s && *s != ' ')
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_rev_wstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i -= 1;
	while (i >= 0)
	{
		if (s[i] == ' ')
		{
			ft_putstr(&s[i + 1]);
			ft_putchar(' ');
		}
		i--;
	}
	ft_putstr(s);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_rev_wstr(av[1]);
	ft_putchar('\n');
	return (0);
}
