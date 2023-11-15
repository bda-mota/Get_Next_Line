/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:09:01 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/15 18:24:53 by bda-mota         ###   ########.fr       */
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*memory;
	size_t	total_size;

	total_size = nmemb * size;
	if (total_size != 0 && total_size / nmemb != size)
		return (NULL);
	memory = malloc(total_size);
	if (memory != NULL)
		ft_bzero(memory, total_size);
	return (memory);
}

char	*ft_transform(t_gnl *root, int len)
{
	t_gnl	*curr;
	t_gnl	*temp;
	char	*str;
	int		i;

	curr = root;
	i = 0;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (curr)
	{
		str[i] = curr->c;
		temp = curr;
		curr = curr->next;
		free (temp);
		i++;
	}
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*str;
	int			i;

	str = s;
	i = 0;
	while (str[i] && str[i] != (unsigned char)c)
		i++;
	if (str[i] == (unsigned char)c)
		return ((char *)(str + i));
	return (NULL);
}
