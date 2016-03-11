/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:46:10 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/10 16:48:54 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '\t' && s[i] != ' ')
			return (0);
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_epur_str(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s != '\t' && *s != ' ')
		{
			ft_putchar(*s);
			i = 1;
		}
		else if (!ft_strlen(s))
		{
			if (i == 1)
				ft_putchar(*s);
			i = 0;
		}
		s++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_epur_str(av[1]);
	ft_putchar('\n');
	return (0);
}
