/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:19:12 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/11 19:23:07 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_specials(int nb)
{

	if (!nb)
		return ("0");
	if (nb == -2147483648)
		return ("-2147483648");
	else 
		return (NULL);
}

char	*ft_itoa(int nb)
{
	int	len;
	int	temp_nb;
	char *s;

	if (ft_specials(nb))
		return (ft_specials(nb));
	len = (nb >= 0 ) ? 1 : 2;
	temp_nb = (nb >= 0) ? nb : nb * -1;
	while ((temp_nb /= 10))
		len++;
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
	s[len] = '\0';
	s[0] = '-';
	nb *= (nb < 0) ? -1 : 1;
	while (nb)
	{
		s[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (s);	
}

int		main(int ac, char **av)
{
	if (ac == 2)
		printf("%s\n", ft_itoa(atoi(av[1])));
	return (0);
}
	
