/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:56 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/21 19:39:27 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl
{
	char			c;
	struct s_gnl	*next;
}	t_gnl;

typedef struct s_find
{
	char	buffer[BUFFER_SIZE];
	int		max;
	int		pos;
	int		bytes;
}	t_find;

int		ft_lstchr(t_gnl *root);
char	*get_next_line(int fd);
char	*ft_transform(t_gnl *root, int len);
void	ft_insert_end(t_gnl **root, char c);
int		ft_build_line(t_find *file, t_gnl **root, int bytes);

#endif
