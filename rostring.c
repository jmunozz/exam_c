/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:02:05 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/11 18:16:32 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_putstr(char *s)
{
	while ((*s == ' ' || *s == '\t') && *s)
		s++;
	while (*s != '\0'  && *s != ' ' && *s != '\t')
	{
			write(1 , s, 1);
			s++;
	}
	while ((*s == ' ' || *s == '\t') && *s)
		s++;
	return (s);
}

char	*len_after_fw(char *s)
{
	int fw;
	
	fw = 0;
	while (*s)
	{
		if ((*s == ' ' || *s == '\t') && fw == 1)
			return (++s);
		if (!fw && (*s != ' ' && *s != '\t'))
		   fw = 1;	
		s++;
	}
	return (0);
}

void	ft_rostring(char *s)
{
	char	*string;
	int		len_fw;

	string = len_after_fw(s);
	if (!*string)
		ft_putstr(s);
	while (*string)
	{
		string = ft_putstr(string);
		write (1, " ", 1);
	}
	ft_putstr(s);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
