/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 09:03:39 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/10 10:22:54 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_is_prime(int n)
{
	int i;
	
	if (n <= 1)
		return (0);
	i = 2;
	while (n % i != 0)
		i++;
	return (i);
}

void	ft_fprime(int n)
{
	int	diviser;

	diviser = ft_is_prime(n);
	if (diviser == n)
	{
		printf("%d", n);
	}
	else if (diviser != 0)
	{
		ft_fprime(diviser);
		printf("*");
		ft_fprime(n /diviser);
	}
}

int		main(int ac, char **av)
{

	if (ac == 2)
		ft_fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
