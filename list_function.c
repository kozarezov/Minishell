/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:24:34 by ceccentr          #+#    #+#             */
/*   Updated: 2020/09/20 15:29:43 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_add_back(t_env **lst, t_env *new)
{
	t_env	*lst_begin;

	if (*lst)
	{
		lst_begin = *lst;
		while (lst_begin->next)
			lst_begin = lst_begin->next;
		lst_begin->next = new;
	}
	else
		*lst = new;
}

int			sort_position(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (i < 4)
	{
		res = res * 100 + (!(str[i]) ? 123 : str[i]);
		i++;
	}
	return (res / 100000);
}

t_env		*ft_new(char *name, char *value, int env)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (new)
	{
		new->name = name;
		new->value = value;
		new->environ = env;
		new->sort = sort_position(new->name);
		new->next = NULL;
	}
	return (new);
}
