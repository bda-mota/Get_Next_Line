/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:56 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/15 15:20:15 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_gnl
{
	char			c;
	struct s_gnl	*next;
}	t_gnl;

char	*get_next_line(int fd);
char	*transform(t_gnl *root);
void	insert_end(t_gnl **root, char c);

#endif
