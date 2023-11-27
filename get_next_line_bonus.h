/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:14:23 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/27 14:11:14 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_gnl
{
	char			c;
	struct s_gnl	*next;
}	t_gnl;

typedef struct s_find
{
	char	buffer[BUFFER_SIZE];
	int		pos;
	int		bytes;
}	t_find;

char	*get_next_line(int fd);
char	*ft_transform(t_gnl *root, int len);
void	ft_insert_end(t_gnl **root, char c);
void	ft_dealloc(t_gnl **root);
int		ft_build_line(t_find *file, t_gnl **root, int bytes);
int		ft_read_file(int fd, t_find *file, t_gnl **root);
int		ft_lstchr(t_gnl *root);

#endif
