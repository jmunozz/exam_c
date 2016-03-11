/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:27:01 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/10 12:31:07 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_bits(int nb, int n)
{
	
	if (nb)		
	{
		ft_print_bits(nb / 2, n + 1);	
		ft_putchar(nb % 2 + '0');
	}
	else
		while (n++ < 8)
			ft_putchar('0');
 }

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
		ft_print_bits(atoi(av[1]), 0);
	ft_putchar('\n');
	return (0);
}
