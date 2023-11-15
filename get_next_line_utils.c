/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:09:01 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/15 15:23:46 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	insert_end(t_gnl **root, char c)
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
