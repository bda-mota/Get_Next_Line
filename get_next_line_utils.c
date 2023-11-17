/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:09:01 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/17 17:34:43 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_insert_end(t_gnl **root, char c)
{
	t_gnl	*new_node;
	t_gnl	*curr;

	new_node = malloc(sizeof(t_gnl));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->c = c;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

char	*ft_transform(t_gnl *root, int len)
{
	t_gnl	*curr;
	t_gnl	*temp;
	char	*str;
	int		i;

	curr = root;
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (len != 0)
	{
		str[i] = curr->c;
		temp = curr;
		curr = curr->next;
		free (temp);
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

int	ft_lstchr(t_gnl *root, char c)
{
	t_gnl	*curr;

	curr = root;
	if (curr == NULL)
		return (0);
	while (curr->next != NULL && curr->c != c)
		curr = curr->next;
	if (curr->next != NULL && curr->c == c)
		return (1);
	return (0);
}
