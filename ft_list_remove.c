/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:32:33 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/10 12:43:18 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;
	t_list *last;

	last = *begin_list;
	current = last->next;
	while (*current)
		if (cmp(current->data, data_ref) == 0)
		{
			last->next = current->next;
			free(current);
			current = last->next;
		}
		else
		{
			last = current;
			current = last->next;
		}
	current = *begin_list;
	if (cmp(current->data, ata_ref) == 0)
	{
		*begin_list = current->next;
		free(current);
	}
}
