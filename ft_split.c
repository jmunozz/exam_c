/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 19:23:52 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/11 21:00:19 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		count_char(char *str)
{
	int len;

	len = 0;
	while (str[len] != ' ' && str[len] != '\n' && str[len] != '\t' && str[len])
		len++;
	return (len);
}

int		count_words(char *str)
{
	int	i;
	int nb_words;

	i = 0;
	nb_words = (str[0] != ' ' && str[0] != '\t' && str[0] != '\n' && str[i] != '\0')
				? 1 : 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && (str[i + 1] !=
			'\0' && str[i + 1] != ' ' && str[i + 1] != '\t' && str[i+ 1] != '\n'))
			nb_words += 1;
		i++;
	}
	return (nb_words);
}

char	*copy_words(char **str)
{
	int 	i;
	int		j;
	int		word_size;
	char	*word;

	i = 0;
	j = 0;
	while ((**str == ' ' || **str == '\t' || **str == '\n') && **str)
		(*str)++;
	word_size = count_char(*str);
	if (!(word = (char*)malloc(sizeof(char) * (word_size + 1))))
			return (NULL);
	word[word_size] = '\0';
	while (word_size--)
	{
		word[j++] = **str;
		(*str)++;
	}
	return (word);
}

char	**ft_split(char *str)
{
	int	nb_words;
	char **tab;

	tab = NULL;
	if (str)
	{
		nb_words = count_words(str);
		tab = (char**)malloc(sizeof(char*) * (nb_words + 1));
		tab[nb_words] = NULL;
		nb_words = 0;
		while (tab[nb_words])
			tab[nb_words++] = copy_words(&str);
	}
	return (tab);
}

int		main(int ac, char **av)
{
	char **tab;
	char **tab_first;

	tab = NULL;
	if (ac == 2)
	{
		tab = ft_split(av[1]);
		tab_first = tab;
		while (tab && *tab)
		{
			printf("%s\n", *tab);
			free(*tab);
			tab++;
		}
		free(tab_first);	
	}
	return (0);
}
